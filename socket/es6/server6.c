#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313
/*Esercizio 6
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input un
vettore di numeri interi, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al
Client la somma e la media del vettore stesso.*/
int Media(int somma){
    int media;
    media=somma/4;
    return media;
}
int Sum(int Vettore[]){
    int sum=0;
    for (int i = 0; i < 4; i++)
    {
        sum=Vettore[i]+sum;
    }
    return sum;
}
int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio),vett[DIM];
    char str[DIM],newstr[DIM]="ricevuta";
    int somma, mediaV;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
     listen(socketfd,10);
    // ciclo infinito
    for (; ;)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        //legge dal client
        read(soa,vett,sizeof(vett));
        
        printf("Vettore ricevuto\n");
        somma=Sum(vett);
        mediaV=Media(somma);
        write(soa, &mediaV, sizeof(mediaV));
        write(soa, &somma, sizeof(somma));
        close(soa);
     }
      
   return 0;
    
}