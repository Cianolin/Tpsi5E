#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#include <ctype.h>

#define SERVERPORT 1313
#define DIM 4

void somma(int *vett1, int *vett2, int *vett3, int *vett4, int *vett5, float *vett6)
{
    for (int i = 0; i < DIM; i++)
    {
        vett3[i] = vett1[i] + vett2[i];
        vett4[i] = vett1[i] - vett2[i];
        vett5[i] = vett1[i] * vett2[i];
        vett6[i] = vett1[i] / vett2[i];
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    int socketfd, soa, fromlen = sizeof(servizio), value;
    int vett1[DIM], vett2[DIM], vett3[DIM], vett4[DIM], vett5[DIM];
    float vett6[DIM];
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("Errore nella creazione del socket");
        exit(EXIT_FAILURE);
    }
    if (bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0)
    {
        perror("Errore nel bind");
        close(socketfd);
        exit(EXIT_FAILURE);
    }
    if (listen(socketfd, 10) < 0)
    {
        perror("Errore nel listen");
        close(socketfd);
        exit(EXIT_FAILURE);
    }
    for (;;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa,vett1,sizeof(vett1));
        read(soa,vett2, sizeof(vett2));
        somma(vett1,vett2,vett3,vett4,vett5,vett6);
        write(soa, vett3, sizeof(vett3));
        write(soa, vett4, sizeof(vett4));
        write(soa, vett5, sizeof(vett5));
        write(soa, vett6, sizeof(vett6));
        close(soa);
    }
    return 0;
}