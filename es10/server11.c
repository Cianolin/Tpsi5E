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

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    int socketfd, soa, fromlen=sizeof(servizio);
    int vett[], pari=0, dispari=0;
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    listen(socketfd,10);
    
    for (; ;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        read(soa,vett,sizeof(DIM));
        printf("Vettore ricevuto");
        for(int i=0;i<0;i++){
            if(vett[i]%2!=0){
                dispari++;
            }
            else{
                pari++;
            }
        }
        write(soa, pari, sizeof(int));
        write(soa, dispari, sizeof(int));
        close(soa);
    }
   return 0;   
}
