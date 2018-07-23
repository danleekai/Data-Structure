#include <stdio.h>
#include <stdlib.h>

typedef struct StackArray {
    int top;
    int capacity;
    int* Array;
}StackArray;

StackArray* CreateStack (int size) {

    StackArray* temp = (StackArray*)malloc(sizeof(StackArray));
    temp->top = -1;
    temp->capacity = size;
    temp->Array = (int*)malloc(sizeof(int)*size);

    return temp;
}

int isFULL (StackArray* stack) {

    if(stack->top+1==stack->capacity) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEMPTY (StackArray* stack) {

    if(stack->top==-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push (StackArray* stack,int value) {

    if(isFULL(stack)) {
        fprintf(stderr,"stack is full");
        exit(1);
    }else {
        stack->Array[++stack->top]=value;
    }
}

int pop (StackArray* stack) {

    int pop_data;

    if(isEMPTY(stack)) {
        fprintf(stderr,"stack is empty");
        exit(1);
    }else {
        pop_data = stack->Array[stack->top--];
    }

    return pop_data;

}

int main()
{
    StackArray* stack = CreateStack(10);

    for(int i=0 ; i<10 ; i++) {
        push(stack,i);
    }

    for(int i=0 ; i<10 ;i++) {
        printf("%d",stack->Array[i]);
    }

    for(int i=0 ; i<10 ;i++) {
        pop(stack);
    }

    return 0;
}
