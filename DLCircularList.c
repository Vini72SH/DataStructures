#include "DLCircularList.h"

CircularList* createCircularList(unsigned int sizeOfElement) {
    CircularList* newList = malloc(sizeof(CircularList));
    if (!(newList)) return NULL;
    
    newList->start = NULL;
    newList->end = NULL;
    newList->iterator = NULL;
    newList->listSize = 0;
    newList->sizeOfElement = sizeOfElement;

    return newList;
};

int isListEmpty(CircularList* list) {
    return (list->listSize == 0);
};

int getListSize(CircularList* list) {
    return list->listSize;
};

void deleteCircularList(CircularList* list);