#include "stack.h"

#include <stdlib.h>
#include <string.h>

Stack* allocateStack(unsigned int sizeOfElement) {
    Stack* newStack = malloc(sizeof(Stack));
    if (!(newStack)) return NULL;

    newStack->top = NULL;
    newStack->stackSize = 0;
    newStack->sizeOfElement = sizeOfElement;

    return newStack;
};

int stack(Stack* stack, void* elementInput) {
    if (!(stack)) return 0;

    Node* newNode = malloc(sizeof(Node));
    if (!(newNode)) return 0;

    newNode->element = malloc(stack->sizeOfElement);
    if (!(newNode->element)) {
        free(newNode);
        return 0;
    }

    newNode->next = stack->top;
    memcpy(newNode->element, elementInput, stack->sizeOfElement);

    stack->top = newNode;
    stack->stackSize++;

    return 1;
};

int unstack(Stack* stack, void* elementOutput) {
    if (!(stack) || isEmpty(stack)) return 0;

    Node* aux = stack->top;
    stack->top = aux->next;

    memcpy(elementOutput, aux->element, stack->sizeOfElement);

    free(aux->element);
    free(aux);

    stack->stackSize--;

    return 1;
};

char isEmpty(Stack* stack) { return (stack->stackSize == 0); };

unsigned int getSizeOfStack(Stack* stack) { return stack->stackSize; };

void deleteStack(Stack* stack) {
    if (!(stack)) return;

    Node* aux;
    while (stack->top) {
        aux = stack->top;
        stack->top = aux->next;

        free(aux->element);
        free(aux);
    };

    free(stack);
};