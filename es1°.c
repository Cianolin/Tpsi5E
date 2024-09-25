#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int nVettore = 10;
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
void Show(int Vettore[])
{
    for (int i = 0; i < nVettore; i++)
    {
        printf("%d,", Vettore[i]);
    }
}
// 2. Mostra inverso
void Invert(int Vettore[])
{
    for (int i = nVettore; i >= 0; i--)
    {
        printf("%d,", Vettore[i]);
    }
}
// 3. Totale
int Sum(int Vettore[])
{
    int a = 0;
    for (int i = 0; i < nVettore; i++)
    {
        a = a + Vettore[i];
    }
    printf("%d\n", a);
}
// 3. Media
int Average(int Vettore[])
{
    int x = Sum(Vettore);
    int a = (x / nVettore);
    printf("%d", x);
    printf("%d", a);
}
// 4. Visualizza n. pari
void evenN(int Vettore[])
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
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Scambia arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void oddN(int Vettore[])
{
    for (int i = 0; i < nVettore; i++)
    {
        if ((Vettore[i] % 2) == 1)
        {
            printf("%d,", Vettore[i]);
        }
    }
}
// 6. Ricerca
void Search(int Vettore[], int num)
{
    for (int i = 0; i < nVettore; i++)
    {
        if (Vettore[i] == num)
        {
            printf("Il numero si trova in posizione %d\n", i);
        }
        else
        {
            printf("Non è presente il numero\n");
        }
    }
}
// 7 Elimina
void Delete(int vettore[], int num)
{
    for (int i = 0; i < nVettore; i++)
    {
        vettore[i] = vettore[i + 1];
    }
    nVettore--;
}
// 8. N alterni
int *Alterni(int vettore[])
{
    int vettore2[nVettore];
    for (int i = 0; i < nVettore; i++)
    {
        if (i % 2 == 1)
        {
            vettore2[i] = vettore[i + 1];
        }
        else
        {
            vettore2[i] = vettore[i - 1];
        }
    }
    int *x = vettore2;
    return x;
}
// bubble sort
void stampaArray(int *vettore)
{
    for (int i = 0; i < nVettore; i++)
    {
        printf("%d", vettore[i]);
    }
}
int main(int argc, char *argv[])
{

    int vettore[nVettore];
    srand(time(NULL));
    for (int i = 0; i < nVettore; i++)
    {
        vettore[i] = rand() % 100;
    }
    do
    {
        int nMenu; /* condition */
        menu();
        scanf("%d", &nMenu);
        switch (nMenu)
        {
        case 1:
            Show(vettore);
            break;
        case 2:
            Invert(vettore);
            break;
        case 3:
            Average(vettore);
            break;
        case 4:
            evenN(vettore);
            break;
        case 5:
            oddN(vettore);
            break;
        case 6:
            int num1;
            printf("Inserisci il numero che si vuole cercare\n");
            scanf("%d\n", &num1);
            Search(vettore, num1);
            break;
        case 7:
            int num2;
            printf("Inserisci il numero che vuoi eliminare\n");
            scanf("%d\n", &num2);
            Delete(vettore, num2);
            break;

        case 8:
            stampaAlternata(Alterni(vettore));
            break;
        }
        scanf("\n");
    } while (1);
}
