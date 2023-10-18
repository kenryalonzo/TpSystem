#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4

// definissons une structure pour gerer les pages

typedef struct {

    int number;
    int lastReferenced;
}Page;

int findLRUPage(Page pages[], int n);

int main(int argc, char *argv[]) {

    int pageReferences[] = { 2, 3, 1, 0, 2, 3, 8, 9, 1, 5, 4, 5};
    int referenceCount = sizeof(pageReferences) / sizeof(pageReferences[0]);

    Page pages[PAGE_SIZE];
    int pageFaults = 0;

    for (int i = 0; i < referenceCount; i++) {
        
        int pageNumber = pageReferences[i];
        int pageFound = 0;

        // maintenant essyons de verifier si la page es deja en memoire

        for (int k = 0; k < PAGE_SIZE; k++) {
            
            if (pages[k].number == pageNumber) {
                pageFound = 1;
                break;
            }
        }

        // essayons maintenant de gerer le cas ou la page n'est pas en memoire, il faudra donc la charger

        if (!pageFound) {
            
            int lruPageIndex = findLRUPage(pages, PAGE_SIZE);
            pages[lruPageIndex].number = pageNumber;
            pages[lruPageIndex].lastReferenced = i;
            pageFaults++;
        }
    }

    printf("Le nombre de defauts de page est de %d\n", pageFaults);
    
    return 0;
}

// Essayons de creer une fonction pour trouver l'indice de la page a supprimer

int findLRUPage(Page pages[], int n) {

    int lruIndex = 0;
    int minLastReferenced = pages[0].lastReferenced;

    for (int i = 0; i < n; i++){
        
        if (pages[i].lastReferenced < minLastReferenced){


            minLastReferenced = pages[i].lastReferenced;
            lruIndex = i;
        }
    }

    return lruIndex;
    
}