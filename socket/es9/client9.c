#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 5
#define SERVERPORT 1313

int main(int argc, char *argv[])
{
    struct sockaddr_in servizio;
    int socketfd;
    int vett[DIM]={30, 57,32, 2,7};

    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    servizio.sin_family = AF_INET;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    write(socketfd, vett, sizeof(vett));

    read(socketfd, vett, sizeof(vett));

    for (int i = 0; i < DIM; i++)
    {
        printf("%d) %d\n", i, vett[i]);
    }

    close(socketfd);
    return 0;
}