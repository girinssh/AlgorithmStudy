#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/*
typedef struct stackArr {
	int* data;
	int top;
	int size;
	int originalSize;
}StackArr;

StackArr* init_Stack(int size) {
	StackArr* newStack = (StackArr*)malloc(sizeof(StackArr));
	newStack->data = (int*)malloc(sizeof(int) * size);
	newStack->originalSize = size;
	newStack->size = 0;
	newStack->top = -1;
	return newStack;
}

void push(StackArr* stack, int data) {
	if (stack->size == stack->originalSize) {
		stack->data = (int*)realloc(stack->data, sizeof(int)*(stack->size + 1));
	}
	stack->data[++(stack->top)] = data;
	stack->size += 1;
	return;
}

int pop(StackArr* stack){
	if (stack->top == -1) {
		puts("Stack under flow error");
		return;
	}
	int data = stack->data[stack->top];
	stack->top -= 1;
	stack->size -= 1;
	//if(stack->size > stack->originalSize)
	//	stack->data = (int*)realloc(stack->data, sizeof(int)*(stack->size));
	
	return data;
}

int top(StackArr* stack) {
	return stack->data[stack->top];
}
int size(StackArr* stack) {
	return stack->size;
}
*/
int main(void) {
	//StackArr* s = init_Stack(2);
	//
	//for (int i = 0; i < 5; i++) {
	//	push(s, i);
	//}
	//for (int i = 0; i < 5; i++) {
	//	printf("%d \n", pop(s));
	//}


	Stack* s = Init_Stack();
	for (int i = 0; i < 5; i++) {
		Push(s, i);
	}
	PrintTop(s);
	for (int i = 0; i < 5; i++) {
		printf("%d \n", Pop(s));
	}

	system("pause");
	return 0;
}