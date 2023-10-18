#ifndef __STACK__H__
#define __STACK__H__

#define MAX_ELEMENTS 14

typedef struct {

    int elements[MAX_ELEMENTS];
    int top;

}Stack;

typedef enum {

    False,
    True

}Bool;

void ajouter_tete(Stack* stack, int element);
void supprimer(Stack *stack);
void fusionner(Stack *stack_dest, Stack *stack_src);
void *lecture(void *arg);

#endif