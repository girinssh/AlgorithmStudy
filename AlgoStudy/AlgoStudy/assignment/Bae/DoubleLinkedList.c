#include "DoubleLinkedList.h"
#define MAX_INDEX dlist->size

//if (index > MAX_INDEX || index < 0) {		//�ε����� �����ľ�. ���� ���� ������ ������ ����ϰ� �Լ� ����.
//	printf("Out Of Range Error : index %d\n", index);
//	return -1;
//}

DList* Init_DList(void) {
	DList* dlist = (DList*)malloc(sizeof(DList));

	dlist->head = NULL;
	dlist->size = 0;		//prev�� �������� �ʰ� ���� ��,������� 0.
	
	return dlist;
}

int DListAppendNode(DList* dlist, int data) {	//��尡 ���϶� �Ѱ� �߰�. ���� �ƴϸ� �� ��尡 ����Ű���� �ϰ�...
	DNode *newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->data = data;
	newDNode->next = NULL;
	if (dlist->head == NULL) {
		dlist->head = newDNode;
		newDNode->prev = NULL;
		dlist->size += 1;
		return 1;
	}
	DNode* dnode = dlist->head;
	while (dnode->next != NULL) {
		dnode = dnode->next;
	}
	dnode->next = newDNode;
	newDNode->prev = dnode;						//�´����� �ణ �ǹ��� ��. �����غ��� ����
	dlist->size += 1;
	return 1;

}
int DListInsertNode(DList* dlist, int index, int data) {
	
	if (index > MAX_INDEX || index < 0) {		//�ε����� �����ľ�. ���� ���� ������ ������ ����ϰ� �Լ� ����.
	printf("Out Of Range Error : index %d\n", index);
	return -1;
	}
	DNode *newDNode = (DNode*)malloc(sizeof(DNode));
	newDNode->data = data;
	newDNode->next = NULL;
	newDNode->prev = NULL;
	if (index == 0) {
		DNode* prevhead = dlist->head;
		newDNode->next = dlist->head;
		prevhead->prev = newDNode;
		dlist->head = newDNode;
		dlist->size += 1;
		return 1;
	}
	else if (index > 0 && index < MAX_INDEX - 1) {
		DNode* prev_dnode = dlist->head;
		DNode* next_dnode = dlist->head;
		for (int i = 0; i < index - 1; i++) {
			prev_dnode = prev_dnode->next;
		}
		for (int i = 0; i < index; i++) {
			next_dnode = next_dnode->next;
		}
		newDNode->next = next_dnode;
		newDNode->prev = prev_dnode;
		prev_dnode->next = newDNode;
		next_dnode->prev = newDNode;
		dlist->size += 1;
		return 1;
	}
	else
		DListAppendNode(dlist, data);
}

void PrintDList(DList* dlist) {
	DNode *n = dlist->head;

	while (n != NULL) {
		printf("%d ", n->data);
		n = n->next;
	}
	puts("");
}

int DListRemoveNode(DList* dlist, int index) {
	if (index > MAX_INDEX || index < 0) {		//�ε����� �����ľ�. ���� ���� ������ ������ ����ϰ� �Լ� ����.
		printf("Out Of Range Error : index %d\n", index);
		return -1;
	}
	
	DNode *del_dnode;
	if (index == 0) {
		del_dnode = dlist->head;
		dlist->head = del_dnode->next;
		DNode *head_node = dlist->head;
		head_node->prev = NULL;
	}
	else if(index>0 && index < MAX_INDEX - 1){
		DNode *prev_dnode = dlist->head;
		DNode *next_dnode = dlist->head;
		for (int i = 0; i < index - 1; i++) {
			prev_dnode = prev_dnode->next;
		}
		for (int i = 0; i < index + 1; i++) {
			next_dnode = next_dnode->next;
		}
		del_dnode = prev_dnode->next;
		prev_dnode->next=next_dnode;
		next_dnode->prev = prev_dnode;
	}
	else {
		DNode* prev_dnode = dlist->head;
		for (int i = 0; i < index - 1; i++) {
			prev_dnode = prev_dnode->next;
		}
		del_dnode = prev_dnode->next;
		prev_dnode->next = NULL;
	}
	free(del_dnode);
	dlist->size -= 1;
	return 1;
}