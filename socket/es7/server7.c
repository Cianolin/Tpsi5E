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
/*Esercizio 7
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input un
vettore di numeri interi, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al
Client la somma e la media dei numeri pari e la somma e la media dei numeri dispari.*/

int Media(int *Vett){
    int media, sum=0, i=0;
    while (Vett[i]==0)
    {
        sum=sum+Vett[i];
        
        i++;
    }
    media=sum/(i+1);
    return media;
}
int Sum(int *Vettore){
    int sum=0, i=0;
    while (Vettore[i]==0)
    {
        sum=sum+Vettore[i];
    }
    
    return sum;
}
void ControlloPari(int *Vett, int *VettPari, int *VettDispari){
    int length=sizeof(Vett)/sizeof(Vett[0]);
    int index=0;
    int index1=0;
    for (int i = 0; i < 4; i++)
    {
        if((Vett[i]%2)==0){
            VettPari[index]=Vett[i];
            index++;
        }else{
            VettDispari[index1]=Vett[i];
            index1++;
        }
    }
    
}
int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio),vett[DIM], vettPari[DIM], vettDispari[DIM];
    char str[DIM],newstr[DIM]="ricevuta";
    int somma, mediaV;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    if(socketfd<0){
        perror("errore nella creazione della socket");
    }
    
    if(bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio))<0){
        perror("errore nella bind");
    }
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
        ControlloPari(vett, vettPari, vettDispari);
        somma=Sum(vettDispari);
        mediaV=Media(vettPari);
        write(soa, &mediaV, sizeof(mediaV));
        write(soa, &somma, sizeof(somma));
        close(soa);
     }
      
   return 0;
    
}