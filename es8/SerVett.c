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
#define dim 5
#define SERVERPORT 1313

int Massimo(int vett[])
{
  int max= vett[0];
  for (int i = 0; i < 5; i++)
  {
    if (max < vett[i])
    {
      max = vett[i];
    }
  }
  printf("%d", max);
  return max;
}
int Minimo(int vett[])
{
  int min = vett[0];
  for (int i = 0; i < 5; i++)
  {
    if (min > vett[i])
    {
      min = vett[i];
    }
  }
  printf("%d", min);
  return min;
}
int main()
{
  struct sockaddr_in servizio, addr_remoto;
  int socketfd, soa, fromlen = sizeof(servizio), vett[dim], min, max;
  char str[DIM];
  //,newstr[DIM]="ricevuta";
  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVERPORT);
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("Errore nella socket");
  }
  if (bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0)
  {
    perror("errore nella bind");
  }
  listen(socketfd, 10) ;
  printf("\n\nServer in ascolto...");
  fflush(stdout);
  soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
  printf("ciao");
  read(soa, vett, sizeof(vett));
  // printf("Vettore ricevuto");
  max = Massimo(vett);
  min = Minimo(vett);
  printf("Ciao");
  write(socketfd, &min, sizeof(min));
  write(socketfd, &max, sizeof(max));
  close(soa);
  close(socketfd);
  return 0;
}
