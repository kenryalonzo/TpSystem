#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Stack.h"

int main(int argc, char **argv) {

     // Création de la pile

    Stack stack;
    stack.top = 0;

    // Ajout de 7 éléments à la pile
    ajouter_tete(&stack, 2);
    ajouter_tete(&stack, 3);
    ajouter_tete(&stack, 6);
    ajouter_tete(&stack, 1);
    ajouter_tete(&stack, 0);
    ajouter_tete(&stack, 2);
    ajouter_tete(&stack, 3);

    // Suppression de 3 éléments de la pile

    supprimer(&stack);
    supprimer(&stack);
    supprimer(&stack);

    // Création des threads pour effectuer les lectures

    pthread_t threads[10];
    int i;
    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, lecture, (void *)&stack);
    }

    // Attente de la fin des threads

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}