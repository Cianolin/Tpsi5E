#include <stdio.h>

void scambia(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void selectionSort(int array[], int dimensione) {
    int i, j, minIndice;
    for (i = 0; i < dimensione - 1; i++) {
        minIndice = i;
        for (j = i + 1; j < dimensione; j++) {
            if (array[j] < array[minIndice]) {
                minIndice = j;
            }
        }
        scambia(array, minIndice, i);
    }
}

int main() {
    int array[] = {64, 25, 12, 22, 11};
    int dimensione = sizeof(array) / sizeof(array[0]);
    printf("Array originale: \n");
    for (int i = 0; i < dimensione; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    selectionSort(array, dimensione);
    printf("\nArray ordinato: \n");
    for (int i = 0; i < dimensione; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
