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

int main()
{
    struct sockaddr_in servizio;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_family = AF_INET;
    servizio.sin_port = htons(SERVERPORT);
    int vett1[DIM] = {0, 1, 2, 3}, vett2[DIM] = {3, 4, 5, 6}, vett3[DIM], vett4[DIM], vett5[DIM];
    float vett6[DIM];
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("Errore nella creazione della socket");
        close(socketfd);
        exit(EXIT_FAILURE);
    }
    if (connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0)
    {
        perror("Errore nella connessione");
        close(socketfd);
        exit(EXIT_FAILURE);
    }
    write(socketfd, vett1, sizeof(vett1));
    write(socketfd, vett2, sizeof(vett2));
    read(socketfd, vett3, sizeof(vett3));
    read(socketfd, vett4, sizeof(vett4));
    read(socketfd, vett5, sizeof(vett5));
    read(socketfd, vett6, sizeof(vett6));
    printf("\nSomma:\n");
    for (int i = 0; i < DIM; i++)
    {
        printf("%d\n", vett3[i]);
    }
    printf("\nDifferenza:\n");
    for (int i = 0; i < DIM; i++)
    {
        printf("%d\n", vett4[i]);
    }
    printf("\nProdotto:\n");
    for (int i = 0; i < DIM; i++)
    {
        printf("%d\n", vett5[i]);
    }
    printf("\nQuoziente:\n");
    for (int i = 0; i < DIM; i++)
    {
        printf("%f\n", vett6[i]);
    }
    close(socketfd);
    return 0;
}