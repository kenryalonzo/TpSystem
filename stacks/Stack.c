#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Stack.h"

// create boolean enumerate type

Bool is_empty_stack(Stack *stack) {

    if (stack == NULL) 
        return True;
    return False;
}

// maintenant on poursuit avec la fonction qui ajoute un element au sommet de la pile.

void ajouter_tete(Stack* stack, int element) {

    if (stack->top < MAX_ELEMENTS) {

        stack->elements[stack->top] = element;
        stack->top++;
        printf("Ajout de %d au somment de la pile\n", element);
    }
    else
        printf("La pile est pleine, impossible d'ajouter %d\n", element);
    
}

//  maintenant on poursuit avec la fonction qui retire un element du sommet de la pile.

void supprimer(Stack *stack) {

    if (!is_empty_stack(stack)) { 
        stack->top--;
        printf(" Suppression de l'element au sommet de la pile\n");
    }
    else
        printf("Attention vous essayer de supprimer une pile vide, cela est impossibble");
}

// creation d'une fonction pour fusionner deux

void fusionner(Stack *stack_dest, Stack *stack_src) {
    
    for (int i = 0; i < stack_src->top; i++) {
        ajouter_tete(stack_dest, stack_src->elements[i]);
    }
    printf("Fusion de piles effectuée\n");
}

// creation d'une fonction pour lire les operations effectuer par les piles

void *lecture(void *arg) {

    Stack *stack = (Stack *)arg;
    int elements = stack->elements[stack->top - 1];
    printf(" Lecture de l'élément %d\n", elements);

    return NULL;
}

