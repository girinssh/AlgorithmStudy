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

List Init_List(void);

int AppendNode(List *list, int data);
int InsertNode(List *list, int index, int data);
					
void PrintList(List *list);
				
int RemoveNode(List *list, int index);

//int Retrieve(List *list, int position);