#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// Menu
void menu()
{
    printf("1-Visualizza l'array\n");
    printf("2-Visualizza l'array invertito\n");
    printf("3-Visualizza la somma media del vettore\n");
    printf("4-Visualizza i numeri pari\n");
    printf("5-Visualizza i numeri dispari\n");
    printf("6-Cerca un numero\n");
    printf("7-Elimina un elemento\n");
    printf("8-Visualizzare alterni i numeri dell'array\n");
    printf("9-Visualizza i vettore in ordine cresente\n");
}
// 1. Mostra
void Show(int Vettore[], int nVettore)
{
    for (int i = 0; i < nVettore; i++)
    {
        printf("%d,", Vettore[i]);
    }
}
// 2. Mostra inverso
void Invert(int Vettore[], int nVettore)
{
    for (int i = nVettore; i >= 0; i--)
    {
        printf("%d,", Vettore[i]);
    }
}
// 3. Totale
int Sum(int Vettore[], int nVettore)
{
    int a = 0;
    for (int i = 0; i < nVettore; i++)
    {
        a = a + Vettore[i];
    }
    printf("%d\n", a);
}
// 3. Media
int Average(int Vettore[], int nVettore)
{
    int x = Sum(Vettore, nVettore);
    int a = (x / nVettore);
    printf("%d", x);
    printf("%d", a);
}
// 4. Visualizza n. pari
void evenN(int Vettore[], int nVettore)
{
    for (int i = 0; i < nVettore; i++)
    {
        if ((Vettore[i] % 2) == 0)
        {
            printf("%d,", Vettore[i]);
        }
    }
}
// 5. Visualizza dispari
void oddN(int Vettore[], int nVettore)
{
    for (int i = 0; i < nVettore; i++)
    {
        if ((Vettore[i] % 2) == 1)
        {
            printf("%d,", Vettore[i]);
        }
    }
}
//6. Ricerca
void Search(int Vettore[], int nVettore, int num){
    for (int i = 0; i < nVettore; i++)
    {
        if (Vettore[i]== num)
        {
            printf("Il numero si trova in posizione %d\n", i);
        }        
        else
        {
            printf("Non è presente il numero\n")
        }
        
    }
}
//7 Elimina
void Delete(int vettore[], int nVettore){
    for (int i = 0; i < nVettore-1; i++)
    {
        
    }
    
}
int main(int argc, char *argv[])
{
    int nVettore = 10;
    int vettore[nVettore];
    srand(time(NULL));
    for (int i = 0; i < nVettore; i++)
    {
        vettore[i] = rand() % 100;
    }
    do
    {
        int nMenu;/* condition */
        menu();
        scanf("%d", &nMenu);
        switch (nMenu)
        {
        case 1:
            Show(vettore, nVettore);
            break;
        case 2:
            Invert(vettore, nVettore);
            break;
        case 3:
            Average(vettore, nVettore);
            break;
        case 4:
            evenN(vettore, nVettore);
            break;
        case 5:
            oddN(vettore, nVettore);
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;
        }
        scanf("\n");
    } while (1);
}
