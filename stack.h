/**
 * @file stack.h
 * @brief generic stack struct
 * @details This is an implementation of a generic stack that uses the FILO
 * policy. To stack and unstack values, it is necessary to pass a pointer to a
 * memory region, so that the copy is done efficiently.
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
    void* element; /**<The element of the node. */
    Node* next;    /**<A pointer to the next node. */
};

struct Stack {
    Node* top;                  /**<A pointer to the top of Stack. */
    unsigned int stackSize;     /**The size of the Stack. */
    unsigned int sizeOfElement; /**<The size of elements in the Stack. */
};

/**
 * @brief Allocate the stack.
 * @param sizeOfElement The size of elements stored in the Stack.
 * @return A pointer to Stack.
 */
Stack* allocateStack(unsigned int sizeOfElement);

/**
 * @brief Stack the element.
 * @param stack A pointer to Stack.
 * @param elementInput The element that will be stacked.
 * @return 1 if successfuly, 0 otherwise.
 */
int stack(Stack* stack, void* elementInput);

/**
 * @brief Unstack the element.
 * @param stack A pointer to Stack.
 * @param elementOutput A pointer to the memory region where the element will be
 * copied.
 * @return 1 if successfuly, 0 otherwise.
 */
int unstack(Stack* stack, void* elementOutput);

/**
 * @brief The stack is empty?
 * @param stack A pointer to Stack.
 * @return 1 if is empty, 0 otherwise.
 */
char isEmpty(Stack* stack);

/**
 * @brief Get the size of Stack.
 * @param stack A pointer to Stack.
 */
unsigned int getSizeOfStack(Stack* stack);

/**
 * @brief Delete the stack, freeing memory.
 * @param stack A pointer to Stack.
 */
void deleteStack(Stack* stack);

#endif