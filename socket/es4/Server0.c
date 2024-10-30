//SERVER
#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi 
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

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
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    // definizione dei dati del socket p.161
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM], str1[DIM], c;
    int count;
    // impostazione del transport endpoint del server p.163-164
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    // leghiamo l'indirizzo al transport endpoint p. 164
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client 
    listen(socketfd,10);// pu� attendere fino a 10 client
    // ciclo infinito
    for (; ;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        //il server accetta la connessione pag. 165
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        //legge dal client
        read(soa,str,sizeof(str));
        printf("Stringa ricevuta: %s\n",str);
        read(soa, &c, 1);
        count = Count(str, c);
        printf("si ripete per %d", count);
        write(soa, &count, 4);
        close(soa);
    }
   return 0;   
}
