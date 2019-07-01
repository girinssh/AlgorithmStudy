#pragma once

typedef struct DNode {
	int data;
	struct DNode* prev;
	struct DNode* next;
}DNode;

typedef struct DList {
	int size;
	DNode* head;
}DList;

DList* Init_DList(void);

int DListAppendNode(DList* dlist, int data);
int DListInsertNode(DList* dlist, int index, int data);

void PrintDList(DList* dlist);

int DListRemoveNode(DList* dlist, int index);