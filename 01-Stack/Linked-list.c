#include <stdio.h>
#include <stdlib.h>

typedef struct Linklist {
    int data;
    struct Linklist* next;
}Linklist;

typedef struct StackLinklist {
    Linklist* top;
}StackLinklist;

Linklist* CreateLinklist(int value) {

    Linklist* temp = (Linklist*)malloc(sizeof(Linklist));
    temp->data = value;
    temp->next = NULL;

    return temp;
}

StackLinklist* CreateStack() {

    StackLinklist* stack = (StackLinklist*)malloc(sizeof(StackLinklist));
    stack->top = NULL;
}

int isEmpty(StackLinklist* stack) {

    if(!stack->top) {
        return 1;
    }else {
        return 0;
    }
}

void push (StackLinklist* stack,int value) {

    Linklist* head = CreateLinklist(value);

    head->next = stack->top;
    stack->top = head;
}

int pop (StackLinklist* stack) {

    int data;
    Linklist* oldhead =(Linklist*)malloc(sizeof(Linklist));

    oldhead = stack->top;

    if(isEmpty(stack)) {
        fprintf(stderr,"stack is empty");
        exit(1);
    }else {
        data = stack->top->data;
        stack->top = oldhead->next;
    }
    free(oldhead);
    return data;

}



int main()
{
    StackLinklist* stack = CreateStack(15);

    for(int i=0;i<10;i++){
        push(stack,i);
    }

    for(int i=0;i<10;i++) {
        printf("%d",pop(stack));
    }

    return 0;
}
