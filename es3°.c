
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*campi: ModelloAuto, marca, cilindrata, prezzo, anno_immatricolazione, determinare:
1) Il prezzo + alto e quello + basso visualizzando anche il modello dell&#39;auto;
2) Ordinare la lista delle auto in base all&#39;anno d&#39;immatricolazione;
3) Visualizzare il nome delle auto a partire da un prezzo scelto dall&#39;utente.*/

typedef struct
{
    char modelloAuto[40];
    char marca[40];
    double prezzo;
    int cilindrata;
    int anno_inmadricolazione;
} Auto;
void Visualizza(struct Auto garage[])
{
    for (int i = 0; i < strlen(garage); i++)
    {
        printf("Prezzo auto %2f\n", auto.prezzo);
        printf("Modello auto %s", auto.modelloAuto);
    }
}
//1
void VisualizzaPerPrezzo(struct Auto garage[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (garage.prezzo[j] > garage.prezzo[j + 1])
            {
                int temp = garage[j];
                garage[j] = garage[j + 1];
                garage[j + 1] = temp;
            }
        }
    }
}
// 2
void OrdinaPerAnno(struct Auto arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// 3
void PrezzoAuto(struct Auto garage[], double sceltaPrezzo)
{
    printf("Da quel prezzo in poi ci sono:\n") for (int i = 0; i < strlen(garage); i++)
    {
        if (garage[i].prezzo >= sceltaPrezzo)
        {
            printf("%c\n", garage[i].modelloAuto);
        }
    }
}
int main()
{
    struct Auto garege[20];
    Auto auto1;
    int choose;
    switch (choose)
    {
    case 1:
        Visualizza(garege);
        break;
    case 2:
        OrdinaPerAnno(garege);
        break;
    case 3:
        double prezzo;
        printf("Scegli un prezzo da cui partire a cercare:\n");
        scanf("%f\n", prezzo);
        PrezzoAuto(garege, prezzo);
        Visualizza(garege);
    default:
        break;
    }
    return 0;
}