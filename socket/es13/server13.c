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
/*Scrivere il codice C di un’applicazione CLIENT-SERVER in cui il Client invia 2 stringhe al Server,
e quest’ultimo reinvia al Client il messaggio se sono uguali oppure no.*/
void Compara(char *str1,char *str2, char *str3){
    int result=strcmp(str1,str2);
    if(result==0){
        strcpy(str3, "La stringa è uguale");
    }else 
    {
        strcpy(str3, "Le stringhe non sono uguali");
    }
    
}
int main(){
    struct sockaddr_in servizio, addr_remote;
    servizio.sin_family=AF_INET;
    servizio.sin_port=htons(SERVERPORT);
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    int socketfd, soa, fromlen=sizeof(servizio);
    char str1[DIM], str2[DIM], str3[DIM];
    socketfd=socket(AF_INET, SOCK_STREAM, 0);
    if(bind(socketfd,(struct sockaddr*)&servizio, sizeof(servizio))<0){
        perror("Errore nella bind");
        exit(1);
    }
    listen(socketfd, 10);
    for(; ;){
        printf("\nServer in ascolto");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remote,&fromlen);
        read(soa,str1,sizeof(str1));
        read(soa,str2,sizeof(str2));
        printf("stringa ricevuta");
        Compara(str1,str2,str3);
        write(soa,str3, sizeof(str3));
        close(soa);
    }
    return 0;
}