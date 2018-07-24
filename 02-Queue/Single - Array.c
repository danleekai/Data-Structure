#include <stdio.h>
#include <stdlib.h>

typedef struct QueueArray {
    int rear;
    int front;
    int capacity;
    int* array;
}QueueArray;

QueueArray* CreateQueue (int size) {

    QueueArray* temp = (QueueArray*)malloc(sizeof(QueueArray));
    temp->capacity = size;
    temp->front = -1;
    temp->rear = -1;
    temp->array = (int*)malloc(sizeof(int)*size);

    return temp;
}

int isFULL (QueueArray* Queue) {

    if(Queue->front+1==Queue->capacity) {
            return 1;
    } else {
            return 0;
    }
}

int isEmpty (QueueArray* Queue) {

    if(Queue->front==Queue->rear) {
            return 1;
    } else {
            return 0;
    }
}

void Enqueue (QueueArray* Queue , int value) {

    if(isFULL(Queue)) {
        fprintf(stderr,"Queue is FULL, but you want push something");
        exit(1);
    } else {
        Queue->array[++Queue->front]=value;
    }
}

int Dequeue (QueueArray* Queue) {

    int data;

    if(isEmpty(Queue)) {
        fprintf(stderr,"Queue is Empty, but you want pop something");
        exit(1);
    } else {
        data = Queue->array[++Queue->rear];
    }

    return data;
}

int main()
{
    QueueArray* Queue = CreateQueue(10);

    for (int i=0;i<10;i++) {
        Enqueue(Queue,i);
    }
    for (int i=0;i<11;i++) {
        printf("%d ",Dequeue(Queue));
    }

    return 0;
}
