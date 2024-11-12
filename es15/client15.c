/*Scrivere il codice C di un’applicazione CLIENT-SERVER in cui il Client invia 2 stringhe al Server,
e quest’ultimo reinvia al Client le lettere comuni alle 2 stringhe.*/
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

int main(){
    struct sockaddr_in servizio;
    servizio.sin_family= AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    char str1[DIM], str2[DIM];
    int socketfd;
    socketfd= socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));
    printf("Prima stringa\n");
    scanf("%s", str1);
    printf("Seconda stringa\n");
    scnaf("%s", str2);
    write(socketfd, str1,sizeof(str1));
    write(socketfd, str2, sizeof(str2));
    printf("%s\n", str2);
    close(socketfd);
    return 0;
}