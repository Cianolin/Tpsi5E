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
#define DIM 512
typedef struct
{
    char title[40];
    char author[40];
    int year;
    float price;
    char categoria[40];
} Libro;

typedef struct
{
    char name[40];
    Libro book[20];
    int nLibri;
} Categoria;
int nCategorie = 0;
void read(char *argv[], Libro Library[])
{
    char c;
    int libroIndex = 0;
    char stringa[40] = "";
    int count = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File non trovato\n");
        exit(1);
    }
    while ((c = fgetc(fp)) != EOF)
    {
        if (c != '\n')
        {
            if (c != ',')
            {
                int len = strlen(stringa);
                stringa[len] = c;
                stringa[len + 1] = '\0';
            }
            else
            {
                if (count == 0)
                {
                    strcpy(Library[libroIndex].title, stringa);
                }
                else if (count == 1)
                {
                    strcpy(Library[libroIndex].author, stringa);
                }
                else if (count == 2)
                {
                    Library[libroIndex].year = atoi(stringa);
                }
                else if (count == 3)
                {
                    Library[libroIndex].price = atof(stringa);
                }
                else if (count == 4)
                {
                    strcpy(Library[libroIndex].categoria, stringa);
                }
                count++;
                stringa[0] = '\0';
            }
        }
        else
        {
            if (count == 4)
            {
                strcpy(Library[libroIndex].categoria, stringa);
            }
            else
            {
                libroIndex++;
                count = 0;
                stringa[0] = '\0';
            }
        }
    }
    fclose(fp);
}
int ConforntoCategorie(Categoria categoria, char *stringa)
{
    if (strcmp(categoria.name, stringa) == 0)
    {
        return 1;
    }
    return 0;
}
void CreaCategoria(Categoria categoria[], int *nCategorie, Libro libreria[], int size)
{
    for (int k = 0; k < size; k++)
    {
        int esiste = 0;
        for (int i = 0; i < *nCategorie; i++)
        {
            esiste = strcmp(categoria[*nCategorie].name, libreria[k].categoria);
        }
        if (!esiste)
        {
            strcpy(categoria[*nCategorie].name, libreria[k].categoria);
            (*nCategorie)++;
        }
    }
}
int RicercaLibro(Libro libreria[], int size, char *nome)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(nome, libreria[i].title) == 0)
        {
            return i;
        }
    }
    return -1;
}
int RicercaCategoria(Categoria categoria[], char *stringa)
{
    for (int i = 0; i < nCategorie; i++)
    {
        int esiste = strcmp(categoria[(nCategorie)].name, stringa);
        if (esiste)
        {
            return i;
        }
    }
    return -1;
}
void StampaSingolo(Libro libro)
{
    printf("%s\n", libro.title);
    printf("%s\n", libro.author);
    printf("%d\n", libro.year);
    printf("%.2f\n",libro.price);
    printf("%s\n", libro.categoria);
}
void Stampa(Libro library[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", library[i].title);
        printf("%s\n", library[i].author);
        printf("%d\n", library[i].year);
        printf("%.2f\n", library[i].price);
        printf("%s\n", library[i].categoria);
    }
}
void StampaCategoria(Categoria generi[]){
for (int i = 0; i < nCategorie; i++)
{
        printf("%s\n", generi[i].name);
}
}
void Menu()
{
    printf("1. Ricerca categoria");
    printf("2. Stampa la libreria");
    printf("3. Ricerca libro");
}
int main(int argv, char *argc[])
{
    Libro libreria[20];
    Categoria categorie[10];
    int size = sizeof(libreria) / sizeof(libreria[0]);
    read(argc, libreria);
    int choose;
    int exit = 0;
    while (!exit)
    {
        Menu();
        scanf("%d\n",&choose);
        switch (choose)
        {
        case 1:
            char categoria[10];
            scanf("%s", categoria);
            if (RicercaCategoria(categorie, categoria) == 1)
            {
                printf("Esiste la categoria\n");
            }
            break;
        case 2:

            Stampa(libreria, size);

            break;
        case 3:
            char titolo[20];
            scanf("%s\n", titolo);
            int posizone;
            if ((posizone= RicercaLibro(libreria, size, titolo)) == -1)
            {
                printf("Libro non esiste\n");
                printf("non");
            }
            else
            {
                printf("Libro esiste\n");
                //StampaSingolo(libreria[posizone]);
            }
        case 6:
            exit = 1;
        default:
            break;
        }
    }
    return 0;
}