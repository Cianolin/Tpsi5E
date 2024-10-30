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

#define DIM 50
#define SERVERPORT 1313

int main(int argc, char **argv)
{ 
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY); 
    char str1[DIM];                               
    servizio.sin_port= htons(SERVERPORT);
    int socketfd;                                
    int palindromo;
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio))<0){
        exit(-1);
    }
    printf("Inserisci la stringa\n");
    scanf("%s", str1);
    write(socketfd, str1, sizeof(str1));
    read(socketfd, &palindromo, sizeof(int));
    if (palindromo)
    {
        printf("La stringa e palindroma");
    }
    else
    {
        printf("La stringa non e palindroma");
    }
    close(socketfd);
    return 0;
}
