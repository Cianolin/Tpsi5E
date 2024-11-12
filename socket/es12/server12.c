#include <stdio.h>     
#include <stdlib.h>      
#include <sys/socket.h> 
#include <sys/types.h>   
#include <netinet/in.h>  
#include <string.h>      
#include <errno.h>      
#include <ctype.h> 
#include <unistd.h>     
/*Scrivere il codice C di un’applicazione CLIENT-SERVER in cui il Client invia 2 stringhe al Server,
e quest’ultimo le reinvia al Client invertite.*/
#define DIM 50
#define SERVERPORT 1313
void invert(char *str){
    char temp;
    int leng=strlen(str);
    for (int i = 0; i < leng/2; i++)
    {
        temp=str[i];
        str[i]=str[leng-1-i];
        str[leng-1-i]= temp;
    }
}
int main(){
    struct sockaddr_in servizio, addr_remote;
    servizio.sin_family=AF_INET;
    servizio.sin_port=htons(SERVERPORT);
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    int socketfd, soa, fromlen=sizeof(servizio);
    char str1[DIM], str2[DIM];
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
        invert(str1);
        invert(str2);
        write(soa,str1, sizeof(str1));
        write(soa,str2, sizeof(str2));
        close(soa);
    }
    return 0;
}