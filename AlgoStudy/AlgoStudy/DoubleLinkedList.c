#include "DoubleLinkedList.h"
#define MAX_INDEX dlist->size

DList* Init_DList(void) {
	DList* dlist = (DList*)malloc(sizeof(DList));

	dlist->head = NULL;
	dlist->size = 0;

	return dlist;
}

int DListAppendNode(DList* dlist, int data) {
	DNode* newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->data = data;
	newDNode->next = NULL;
	newDNode->prev = NULL;

	if (dlist->head == NULL) {
		dlist->head = newDNode;
		dlist->size += 1;
		return 1;
	}
	DNode* dnode = dlist->head;
	while (dnode->next != NULL) {
		dnode = dnode->next;
	}
	dnode->next = newDNode;
	newDNode->prev = dnode;						
	dlist->size += 1;
	return 1;

}
int DListInsertNode(DList* dlist, int index, int data) {
	if (index > MAX_INDEX || index < 0) {
		printf("Out Of Range Error : index %d\n", index);
		return -1;
	}
	DNode* newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->data = data;
	newDNode->next = NULL;
	newDNode->prev = NULL;

	if (index == 0) {
		newDNode->next = dlist->head;
		dlist->head->prev = newDNode;
		dlist->head = newDNode;
		dlist->size += 1;
		return 1;
	}

	else if (index > 0 && index < MAX_INDEX) {
		DNode* node = dlist->head;

		for (int i = 0; i < index; i++) 
			node = node->next;
		
		newDNode->next = node;
		newDNode->prev = node->prev;
		node->prev->next = newDNode;
		node->prev = newDNode;

		dlist->size += 1;
		return 1;
	}
	else
		DListAppendNode(dlist, data);
}

void PrintDList(DList* dlist) {
	DNode* n = dlist->head;

	while (n != NULL) {
		printf("%d ", n->data);
		n = n->next;
	}
	puts("");
}

int DListRemoveNode(DList* dlist, int index) {
	if (index > MAX_INDEX || index < 0) {		//인덱스의 조건파악. 만약 맞지 않을때 오류문 출력하고 함수 종료.
		printf("Out Of Range Error : index %d\n", index);
		return -1;
	}

	if (index == 0) {
		dlist->head = dlist->head->next;
		free(dlist->head->prev);
	}
	else if (index > 0 && index < MAX_INDEX - 1) {
		DNode* node = dlist->head;
		for (int i = 0; i < index; i++)
			node = node->next;

		node->prev->next = node->next;
		node->next->prev = node->prev;

		free(node);
	}
	else {
		DNode* node = dlist->head;
		for (int i = 0; i < index; i++)
			node = node->next;

		node->prev->next = node->next;

		free(node);
	}
	dlist->size -= 1;
	return 1;
}