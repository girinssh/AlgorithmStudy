#include "DoubleLinkedList.h"

DList* Init_DList(void) {
	DList* dlist = (DList*)malloc(sizeof(DList));

	dlist->head = NULL;
	dlist->size = 0;

	return dlist;
}

int DListAppendNode(DList* dlist, int data) {

}
int DListInsertNode(DList* dlist, int index, int data) {

}

void PrintDList(DList* dlist) {

}

int DListRemoveNode(DList* dlist, int index) {

}