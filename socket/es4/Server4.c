//SERVER
#include <stdio.h>     
#include <stdlib.h>      
#include <sys/socket.h> 
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>      
#include <errno.h>      
#include <ctype.h>      
#include <unistd.h>    

/*Esercizio 4
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e un carattere,e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
numero di occorrenze del carattere nella stringa.*/
#define DIM 50
#define SERVERPORT 1313
int Count(char *str, char c){
    int count=0;
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i]== c){
            count++;
        }
    }
    return count;
}
int main()
{
    struct sockaddr_in servizio, addr_remoto;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM], str1[DIM], c;
    int count;
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    listen(socketfd,10);
    for (; ;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        read(soa,str,sizeof(str));
        printf("Stringa ricevuta: %s\n",str);
        read(soa, &c, 1);
        count = Count(str, c);
        printf("si ripete per %d", count);
        close(soa);
    }
   return 0;   
}
