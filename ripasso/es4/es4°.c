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
    char genere[40];
} Libro;
int nLibri = 0;
void read(char *argv[], Libro *libri)
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
                    strcpy(libri[libroIndex].title, stringa);
                }
                else if (count == 1)
                {
                    strcpy(libri[libroIndex].author, stringa);
                }
                else if (count == 2)
                {
                    libri[libroIndex].year = atoi(stringa);
                }
                else if (count == 3)
                {
                    libri[libroIndex].price = atof(stringa);
                }
                count++;
                stringa[0] = '\0';
            }
        }
        else
        {
            if (count == 4)
            {
                strcpy(libri[libroIndex].genere, stringa);
            }
            stringa[0] = '\0';
            count = 0;
            libroIndex++;
            (nLibri)++;
        }
    }
    fclose(fp);
}
void CreaCategoria(char generi[][80], Libro book, int *size)
{
    int found = 0;
    for (int i = 0; i < *size; i++)
    {
        if (strcmp(book.genere, generi[i]))
        {
            found = 1;
        }
    }
    if (!found)
    {
        strcpy(generi[*size], book.genere);
        (*size)++;
    }
}
void Stampa(Libro book)
{
    printf("%s\n", book.title);
    printf("%s\n", book.author);
    printf("%d\n", book.year);
    printf("%.2f\n", book.price);
    printf("%s\n", book.genere);
}
void TrovaCategoria(Libro *library, char *categoria, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(library[i].genere, categoria))
        {
            Stampa(library[i]);
        }
    }
}
int TrovaLibro(Libro *library, int size, char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(library[i].title, name))
        {
            return i;
        }
    }
    return -1;
}
void Menu()
{
    printf("1. Stampa libreria\n");
    printf("2. Trova libro\n");
    printf("3. Trova libri della categoria\n");
    printf("4. Esci\n");
}
int main(int argv, char *argc[])
{
    int nCategorie = 0;

    Libro libreria[40];
    Libro book;
    char genere[20];
    char name[20];
    int choose;
    int esci = 0;
    int size = sizeof(libreria) / sizeof(libreria[0]);
    read(argc, libreria);
    while (!esci)
    {
        Menu();
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            for (int i = 0; i < nLibri; i++)
            {
                Stampa(libreria[i]);
            }
            break;
        case 2:
            scanf("%s", name);
            printf("Metti il titolo del libro da cercare\n");
            int index = TrovaLibro(libreria, nLibri, name);
            if (index == -1)
            {
                printf("Libro non trovato");
            }
            else
            {
                Stampa(libreria[index]);
            }
        case 3:
            printf("Scegli una categoria da cercare\n");
            scanf("%s", genere);
            TrovaCategoria(libreria, genere, nLibri);
            break;
        case 4:
            esci = 1;
            break;
        }
    }
    return 0;
}