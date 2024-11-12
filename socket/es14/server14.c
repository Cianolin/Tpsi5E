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
    struct sockaddr_in servizio, addr_remote;
    servizio.sin_family=AF_INET;
    servizio.sin_port=htons(SERVERPORT);
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    int socketfd, soa, fromlen=sizeof(servizio);
    char str1[DIM], str2[DIM];
    strcpy(str2, "La stringa non ha doppie");
    socketfd=socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd<0){
        perror("Errore nella creazione della socket\n");
        exit(-1);
    }
    if(bind(socketfd,(struct sockaddr*)&servizio, sizeof(servizio))<0){
        perror("Errore nella bind");
        exit(-1);
    }
    listen(socketfd, 10);
    for(; ;){
        printf("\nServer in ascolto");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remote,&fromlen);
        read(soa,str1,sizeof(str1));
        printf("stringa ricevuta");
        for (int i = 0; i < strlen(str1)-1; i++)
        {
            if (str1[i]==str1[i+1])
            {
                strcpy(str2, "La stringa ha doppie");
            }
        }
        write(soa, str2, sizeof(str2));
        close(soa);
    }
    return 0;
}