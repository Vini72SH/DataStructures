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

void enqueue(Queue* queue, void* element) {
    if (!(queue)) return;

    Node* aux;
    Node* newNode = malloc(sizeof(Node));
    if (!(newNode)) return;

    newNode->next = NULL;
    newNode->element = malloc(queue->sizeOfElement);

    if (!(newNode->element)) {
        free(newNode);
        return;
    }

    memcpy(newNode->element, element, queue->sizeOfElement);

    if (!(isEmpty(queue))) {
        aux = queue->end;
        aux->next = newNode;
    } else {
        queue->start = newNode;
    }

    queue->end = newNode;
    queue->queueSize++;
};

void* dequeue(Queue* queue) {
    if (!(queue) || isEmpty(queue)) return NULL;

    Node* aux = queue->start;
    void* element = malloc(queue->sizeOfElement);
    if (!(element)) {
        queue->start = aux->next;
        queue->queueSize--;

        if (queue->queueSize == 0) queue->end = NULL;

        free(aux->element);
        free(aux);
        return NULL;
    }

    memcpy(element, aux->element, queue->sizeOfElement);
    queue->start = aux->next;
    queue->queueSize--;

    if (getSizeOfQueue(queue) == 0) queue->end = NULL;

    free(aux->element);
    free(aux);

    return element;
};

int getSizeOfQueue(Queue* queue) { return queue->queueSize; };

char isEmpty(Queue* queue) { return (queue->queueSize == 0); };

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