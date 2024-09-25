#include <stdio.h>

void eliminaElemento(int arr[], int *n, int indice) {
    if (indice < 0 || indice >= *n) {
        printf("Indice non valido\n");
        return;
    }
    
    for (int i = indice; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*n)--;
}

void stampaArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    printf("Array originale: ");
    stampaArray(arr, n);
    
    eliminaElemento(arr, &n, 3); // Elimina l'elemento all'indice 2
    
    printf("Array dopo l'eliminazione: ");
    stampaArray(arr, n);
    
    return 0;
}
