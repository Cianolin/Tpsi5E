// CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 5
#define SERVERPORT 1313

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    int socketfd;
     int vett[]={20,4,5,17,29}, pari, dispari;
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    printf("Inserisci la stringa\n");
    scanf("%s", str1);
    write(socketfd, vett, sizeof(vett));
    read(socketfd, pari, sizeof(int));
    read(socketfd, dispari, sizeof(int));
    printf("Pari: %d\nDispari: %d", pari, dispari);
    close(socketfd);
    return 0;
}
