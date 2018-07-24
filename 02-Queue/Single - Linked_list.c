#include <stdio.h>
#include <stdlib.h>

typedef struct Linklist {
    int value;
    struct Linklist* next;
}Linklist;

typedef struct QueueLinklist {
    Linklist* front;
    Linklist* rear;
}QueueLinklist;

Linklist* CreateLinklist (int value) {

    Linklist* temp = (Linklist*)malloc(sizeof(Linklist));
    temp->next = NULL;
    temp->value = value;

    return temp;
}

QueueLinklist* CreateQueue () {

    QueueLinklist* temp = (QueueLinklist*)malloc(sizeof(QueueLinklist));
    temp->front = NULL;
    temp->rear = NULL;

    return temp;
}

int isEmpty (QueueLinklist* queue) {

    if(queue->front==NULL) {
        return 1;
    } else {
        return 0;
    }
}

void Enqueue (QueueLinklist* queue , int data) {

    Linklist* temp = CreateLinklist(data);

    if(queue->rear==NULL) {
        queue->rear = temp;
    } else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
    if(queue->front==NULL) {
        queue->front = temp;
    }
}

int Dequeue (QueueLinklist* queue) {

    int data;
    Linklist* oldnode = (Linklist*)malloc(sizeof(Linklist));
    oldnode = queue->front;

    if(isEmpty(queue)) {
        fprintf(stderr,"queue is empty, but you want to pop something");
        exit(1);
    } else {
        data = queue->front->value;
        queue->front = queue->front->next;
        free(oldnode);
    }

    return data;
}


int main()
{
    QueueLinklist* queue = CreateQueue();

    for(int i=0;i<10;i++) {
        Enqueue(queue,i);
    }

    for(int i=0;i<10;i++) {
        printf("%d ",Dequeue(queue));
    }


    return 0;
}
