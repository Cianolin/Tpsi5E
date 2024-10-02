#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char modelloAuto[40];
    char marca[40];
    float prezzo;
    int cilindrata;
    int anno_inmadricolazione;
} Auto;

void Visualizza(Auto garage[], int i) {
    printf("Prezzo auto: %.2f\n", garage[i].prezzo);
    printf("Modello auto: %s\n", garage[i].modelloAuto);
    printf("Anno di immatricolazione: %d\n", garage[i].anno_inmadricolazione);
}

// 1
int MaxPrezzo(Auto garage[], int size) {
    float maxPrezzo = garage[0].prezzo;
    int posizione = 0;
    for (int i = 1; i < size; i++) {
        if (maxPrezzo < garage[i].prezzo) {
            maxPrezzo = garage[i].prezzo;
            posizione = i;
        }
    }
    return posizione;
}

int MinPrezzo(Auto garage[], int size) {
    float minPrezzo = garage[0].prezzo;
    int posizione = 0;
    for (int i = 1; i < size; i++) {
        if (minPrezzo > garage[i].prezzo) {
            minPrezzo = garage[i].prezzo;
            posizione = i;
        }
    }
    return posizione;
}

// 2
void OrdinaPerAnno(Auto arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].anno_inmadricolazione > arr[j + 1].anno_inmadricolazione) {
                Auto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 3
void PrezzoAuto(Auto garage[], int size, float sceltaPrezzo) {
    printf("Da quel prezzo in poi ci sono:\n");
    for (int i = 0; i < size; i++) {
        if (garage[i].prezzo >= sceltaPrezzo) {
            printf("%s\n", garage[i].modelloAuto);
        }
    }
}

int main() {
    Auto auto1 = {
        .modelloAuto = "Fiat Panda",
        .marca = "Fiat",
        .prezzo = 15000.0,
        .cilindrata = 1300,
        .anno_inmadricolazione = 2015
    };

    Auto auto2 = {
        .modelloAuto = "Volkswagen Golf",
        .marca = "Volkswagen",
        .prezzo = 20000.0,
        .cilindrata = 1600,
        .anno_inmadricolazione = 2018
    };

    Auto auto3 = {
        .modelloAuto = "Toyota Yaris",
        .marca = "Toyota",
        .prezzo = 12000.0,
        .cilindrata = 1000,
        .anno_inmadricolazione = 2012
    };

    Auto garage[3] = {auto1, auto2, auto3};
    int size = sizeof(garage) / sizeof(garage[0]);
    int choose;

    do {
        printf("1. Visualizza l'auto più costosa e meno costosa\n");
        printf("2. Ordina le auto per anno di immatricolazione\n");
        printf("3. Visualizza le auto a partire dal prezzo che inserisci\n");
        printf("4. Visualizza tutte le auto\n");
        printf("5. Esci\n");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Auto con prezzo più alto\n");
                Visualizza(garage, MaxPrezzo(garage, size));
                printf("Auto con prezzo più basso\n");
                Visualizza(garage, MinPrezzo(garage, size));
                break;
            case 2:
                OrdinaPerAnno(garage, size);
                printf("Auto ordinate per anno di immatricolazione:\n");
                for (int i = 0; i < size; i++) {
                    Visualizza(garage, i);
                }
                break;
            case 3:
                {
                    float prezzo;
                    printf("Scegli un prezzo da cui partire a cercare:\n");
                    scanf("%f", &prezzo);
                    PrezzoAuto(garage, size, prezzo);
                }
                break;
            case 4:
                for (int i = 0; i < size; i++) {
                    Visualizza(garage, i);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Scelta non valida. Riprova.\n");
                break;
        }
    } while (1);

    return 0;
}