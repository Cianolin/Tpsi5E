#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
L'obiettivo è quello di creare una rappresentazione per i e le a cui appartengono. Ogni libro avrà diverse informazioni e sarà assegnato a una categoria specifica.

Implementa un programma in linguaggio C che gestisce i libri di una libreria. Ogni libro è identificato da titolo, autore, anno di pubblicazione e prezzo. I libri sono organizzati per categoria (ad esempio, narrativa, saggistica, scienze, arte), e ogni categoria può avere più libri.
Immaginate di dover gestire questi raccolta di libri, suddivisi per categorie, e di dover trovare un modo per tenere traccia delle informazioni di ciascun libro. Ogni libro dovrà avere un titolo, che lo identificherà, un autore, che ci dirà chi ha scritto il libro, l'anno di pubblicazione, che ci permetterà di sapere quando è stato pubblicato, e infine un prezzo, per indicare quanto costa.
Dovrete anche pensare a come suddividere questi libri in categorie. Ogni categoria avrà un nome, che indicherà di che tipo di libri stiamo parlando, come "Narrativa" o "Scienze", e conterrà una lista di libri che appartengono a quella specifica categoria.
Il vostro compito sarà trovare il modo migliore per organizzare e gestire tutte queste informazioni. Inoltre, dovrete scrivere delle funzioni che vi permettano di stampare tutti i libri che appartengono a una determinata categoria, cercare un libro specifico in base al titolo e trovare tutti i libri che rientrano in una certa categoria.
Sarà vostro compito decidere come rappresentare questi dati e implementare le funzioni necessarie per far funzionare il programma.

Buon lavoro!La consegna dovrà contenere il codice (su git) e una relazione dettagliata sulla PROGETTAZIONE e sulle firme delle funzioni da realizzare

In allegato, qui, trovate il file da cui pescare i libri per popolare correttamente la libreria.
*/
typedef struct{
    char romanzo[20]="romanzo";
    char narrativa[20]="narrativa";
}categoria;
typedef struct{
    char title[40];
    char author[40];
    int year;
    float price;
    categoria genere;
}libro;
void read(){
    libro book;
    char stringa[40];
    int count;
    FILE *fp;
    if(fopen(argv[2], "r")==null){
     printf("File non trovato\n");
     return 0;
    }
    while ((c = fgetc(fp)) != EOF) {
        if(c=='\n'){
         count=0;    
        }else{
            if(c!=','){
            stringa+=c;
        }else{
            if(count==0){
            book.title=stringa;
            }else if(count==1){
                book.author=stringa;
            }
            stringa="";
            count++;
        }

        
        
        
    }
    
}
void GestioneCategoria(libro libray[], int size){
    for(int i=0; i<size;i++){
        if(library[i].categoria==)
    }
}
int main()
{
    libro library[];
    int size = sizeof(library) / sizeof(library[0]);
    return 0;
}
