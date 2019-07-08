#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Stack {
	int size;
	Node *head;
}List;

Stack* Init_List(void);

int ListAppendNode(Stack *list, int data);
int ListInsertNode(Stack *list, int index, int data);
					
void PrintList(Stack *list);
				
int ListRemoveNode(Stack *list, int index);