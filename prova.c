#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 50

// Funzione per confrontare e aggiungere una stringa se non esiste
void compareAndAddString(char strings[][MAX_LENGTH], int *size, char *target) {
    int found = 0;
    for(int i = 0; i < *size; i++) {
        if(strcmp(strings[i], target) == 0) {
            printf("La stringa \"%s\" esiste già nell'array.\n", target);
            found = 1;
            break;
        }
    }
    if(!found && *size < MAX_STRINGS) {
        strcpy(strings[*size], target);
        (*size)++;
        printf("La stringa \"%s\" è stata aggiunta all'array.\n", target);
    } else if (!found) {
        printf("L'array è pieno, impossibile aggiungere la stringa \"%s\".\n", target);
    }
}

int main() {
    // Definisci un array di stringhe
    char strings[MAX_STRINGS][MAX_LENGTH] = {
        "Ciao",
        "Mondo",
        "Questo",
        "E'",
        "Un array di stringhe"
    };
    int size = 5;
    
    // Stringa target con cui confrontare e possibilmente aggiungere
    char target[MAX_LENGTH] = "Nuova Stringa";
    
    // Confronta e aggiungi la stringa target se non esiste
    compareAndAddString(strings, &size, target);
    
    // Stampa tutte le stringhe nell'array
    for(int i = 0; i < size; i++) {
        printf("%s\n", strings[i]);
    }
    
    return 0
