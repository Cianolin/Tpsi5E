// SERVER
#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define DIM 50
#define SERVERPORT 1313

int Palindroma(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i]!=str[strlen(str)-1-i])
        {
            return 0;
        }
    }
    
    return 1;//palindromo
}

int main()
{
    struct sockaddr_in servizio, addr_remoto; 
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], str1[DIM];
    int palintromo;
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) <0){
        exit(-1);
    }
    listen(socketfd, 10);
    for (;;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa, str, sizeof(str));
        printf("Stringa ricevuta: %s\n", str);
        palintromo= Palindroma(str);
        write(soa, &palintromo, sizeof(int));
        close(soa);
    }
    return 0;
}
