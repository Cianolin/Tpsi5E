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
#define SERVERPORT 1313
int max(int *vett)
{
    int max = vett[0];
    for (int i = 1; i < 5; i++)
    {
        if (max > vett[i])
            max = vett[i];
    }
}
int min(int *vett)
{
    int min = vett[0];
    for (int i = 1; i < 5; i++)
    {
        if (min > vett[i])
            min = vett[i];
    }
}
int main(int argc, char **argv)
{

    struct sockaddr_in servizio;
    int socketfd, vett[DIM];
    char str1[DIM], str2[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    write(socketfd, vett, sizeof(vett));
    close(socketfd);
    return 0;
}
