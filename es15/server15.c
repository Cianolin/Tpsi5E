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

void Confronta(char *str1, char*str2, char *str3){
    int posix=0;
    for (int i = 0; i < strlen(str1); i++)
    {
        for (int y = 0; y < strlen(str2); y++)
        {
            if(str1[i]==str2[y]){
                for (int x = 0; x < strlen(str3); x++)
                {
                    if(str3[x]=!str1[i]){
                        str3[posix]= str1;
                    }
                }
            }
        }
        
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
        write(soa,str3, sizeof(str3));
        close(soa);
    }
    return 0;
}