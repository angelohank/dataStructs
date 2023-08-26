#include "StaticStack.h"

void startStack( StaticStack* stack) {
    stack->top = 0;
}

bool isEmpty( StaticStack* stack ) {
    return stack->top == 0;
}

bool isFull( StaticStack* stack ) {
    return stack->top == MAX_SIZE-1;
}

int size( StaticStack* stack ) {
    return stack->top;
}

int top( StaticStack* stack ) {
    return stack->values[stack->top-1];
}

void print( StaticStack* stack ) {
    printf( "Stack {\n" );
    for( int i = 0; i < size(stack); i++ ) {
        printf("%d\n", stack->values[i]);
    }
    printf("}\n", size(stack));
}

void push( StaticStack* stack, int value ) {
    if( !isFull(stack) ) {
        stack->values[stack->top] = value;
        stack->top++;
    } else {
        printf("Stack is full");
    }
}

void pop( StaticStack* stack ) {
    if( !isEmpty(stack) ) {
        stack->top--;
    } else {
        printf("Stack is empty");
    }
}
