#ifndef StaticStack_h
#define StaticStack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int values[MAX_SIZE];
    int top;
} StaticStack;

void startStack( StaticStack* stack );

bool isEmpty( StaticStack* stack );
bool isFull( StaticStack* stack );
int size( StaticStack* stack );
int top( StaticStack* stack );
void print( StaticStack* stack );

void push( StaticStack* stack, int value );
void pop( StaticStack* stack );

#endif