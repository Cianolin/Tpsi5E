#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define dim 5
#define SERVERPORT 1313

int main(int argc, char **argv)
{

    struct sockaddr_in servizio;
    int socketfd, vett[dim], min, max;
    char str1[DIM], str2[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    for (int i = 0; i < 4; i++)
    {
        printf("Vettore %d\n", i+1);
        scanf("%d", &vett[i]);
    }
    write(socketfd, vett, sizeof(vett));
    read(socketfd, &min, sizeof(max));
    read(socketfd, &max, sizeof(min));
    printf("Numero massimo è %d\nNumero minimo è %d\n", max, min);
    close(socketfd);
    return 0;
}
