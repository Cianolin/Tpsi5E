
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
    float prezzo;
    int cilindrata;
    int anno_inmadricolazione;
} Auto;
void Visualizza(Auto garage[], int i)
{
    printf("Prezzo auto %2f\n", garage[i].prezzo);
    printf("Modello auto %s", garage[i].modelloAuto);
}
// 1
int MaxPrezzo(Auto garage[])
{
    double maxPrezzo = 0;
    int posizione;
    for (int i = 0; i < strlen(garage); i++)
    {
        if (maxPrezzo < garage[i].prezzo)
        {
            maxPrezzo = garage[i].prezzo;
            posizione = i;
        }
    }
    return posizione;
}
int MinPrezzo(Auto garage[])
{
    double minPrezzo = 0;
    int posizione = 0;
    for (int i = 0; i < strlen(garage); i++)
    {
        double minPrezzo = garage[i].prezzo;
        for (int i = 0; i < strlen(garage); i++)
        {
            if (minPrezzo > garage[i].prezzo)
            {
                minPrezzo = garage[i].prezzo;
            }
        }
    }
    return posizione;
}
// 2
void OrdinaPerAnno(Auto arr[])
{
    for (int i = 0; i < 3 - 1; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
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
void PrezzoAuto(Auto garage[], double sceltaPrezzo)
{
    printf("Da quel prezzo in poi ci sono:\n");
    for (int i = 0; i < strlen(garage); i++)
    {
        if (garage[i].prezzo >= sceltaPrezzo)
        {
            printf("%s\n", garage[i].modelloAuto);
        }
    }
}
int main()
{
    Auto auto1 = {
        .modelloAuto = "Fiat Panda",
        .marca = "Fiat",
        .prezzo = 15000.0,
        .cilindrata = 1300,
        .anno_inmadricolazione = 2015};

    Auto auto2 = {
        .modelloAuto = "Volkswagen Golf",
        .marca = "Volkswagen",
        .prezzo = 20000.0,
        .cilindrata = 1600,
        .anno_inmadricolazione = 2018};

    Auto auto3 = {
        .modelloAuto = "Toyota Yaris",
        .marca = "Toyota",
        .prezzo = 12000.0,
        .cilindrata = 1000,
        .anno_inmadricolazione = 2012};
    Auto garege[3] = {auto1, auto2, auto3};
    int choose;
    do
    {
        printf("1. Visualizza l'auto più costosa e meno costosa\n2. Ordina le auto per anno di immatricolazione\n3. Visualizza le auto a partire dal prezzo che inserisci\n4. Visualizza tutte le auto");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Auto con prezzo più alto\n");
            Visualizza(garege, MaxPrezzo(garege));
            printf("Auto con prezzo più basso\n");
            Visualizza(garege, MinPrezzo(garege));
            break;
        case 2:
            OrdinaPerAnno(garege);
            break;
        case 3:
            float prezzo;
            printf("Scegli un prezzo da cui partire a cercare:\n");
            scanf("%2f\n", prezzo);
            PrezzoAuto(garege, prezzo);
        case 4:
            for (int i = 0; i < strlen(garege); i++)
            {
                Visualizza(garege, i);
            }
        default:
            break;
        }
        return 0;
    } while (1);
}