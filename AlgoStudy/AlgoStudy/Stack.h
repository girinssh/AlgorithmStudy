#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Stack {
	int size;
	Node* top;
}Stack;

Stack* Init_Stack(void);

int Push(Stack* s, int data);

void PrintTop(Stack* s);

int Pop(Stack* s);