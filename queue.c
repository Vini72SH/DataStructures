#include "queue.h"

Queue* allocateQueue(unsigned int sizeOfElement) {
    Queue* newQueue = malloc(sizeof(Queue));
    if (!(newQueue)) return NULL;

    newQueue->start = NULL;
    newQueue->end = NULL;
    newQueue->queueSize = 0;
    newQueue->sizeOfElement = sizeOfElement;

    return newQueue;
};

int enqueue(Queue* queue, void* elementInput) {
    if (!(queue)) return 0;

    Node* aux;
    Node* newNode = malloc(sizeof(Node));
    if (!(newNode)) return 0;

    newNode->next = NULL;
    newNode->element = malloc(queue->sizeOfElement);

    if (!(newNode->element)) {
        free(newNode);
        return 0;
    }

    if (!(isQueueEmpty(queue))) {
        aux = queue->end;
        aux->next = newNode;
    } else {
        queue->start = newNode;
    }

    memcpy(newNode->element, elementInput, queue->sizeOfElement);
    queue->end = newNode;
    queue->queueSize++;

    return 1;
};

int dequeue(Queue* queue, void* elementOutput) {
    if (!(queue) || isQueueEmpty(queue)) return 0;

    Node* aux = queue->start;
    queue->start = aux->next;
    queue->queueSize--;
    memcpy(elementOutput, aux->element, queue->sizeOfElement);

    if (getSizeOfQueue(queue) == 0) queue->end = NULL;

    free(aux->element);
    free(aux);

    return 1;
};

unsigned int getSizeOfQueue(Queue* queue) { return queue->queueSize; };

int isQueueEmpty(Queue* queue) { return (queue->queueSize == 0); };

void deleteQueue(Queue* queue) {
    if (!queue) return;

    Node* aux;
    while (queue->start) {
        aux = queue->start;
        queue->start = aux->next;

        free(aux->element);
        free(aux);
    }

    free(queue);
};