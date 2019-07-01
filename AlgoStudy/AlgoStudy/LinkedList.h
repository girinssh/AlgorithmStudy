#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct List {
	int size;
	Node *head;
}List;

List* Init_List(void);

int ListAppendNode(List *list, int data);
int ListInsertNode(List *list, int index, int data);
					
void PrintList(List *list);
				
int ListRemoveNode(List *list, int index);