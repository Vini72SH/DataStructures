#include "queue.h"

int main() {
    // Create a new queue for integers
    Queue* myQueue = allocateQueue(sizeof(int));

    int value = 10;
    enqueue(myQueue, &value);

    value = 20;
    enqueue(myQueue, &value);

    int* dequeuedValue = (int*)dequeue(myQueue);
    printf("Dequeued value: %d\n", *dequeuedValue);
    free (dequeuedValue);

    deleteQueue(myQueue);
    return 0;
}
