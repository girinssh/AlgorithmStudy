#include "LinkedList.h"
#define MAX_INDEX Length(*head)
List* Init_List(int data) {
	List* node = (List*)malloc(sizeof(List));
	node->data = data;
	node->next = NULL;

	return node;
}

int Length(List *head) {
	int L = 0;
	List *node = head;
	while (node != NULL) {
		node = node->next;
		L++;
	}
	return L;
}

int AppendNode(List **head, int data) {

	if (head == NULL) {
		printf("List is NULL\n");
		return -1;
	}

	List *newNode = Init_List(data);
	List **node = head;

	while ((*node)->next != NULL) {
		node = &((*node)->next);
	}
	(*node)->next = newNode;

	return 1;
}

int InsertNode(List **head, int index, int data) {	/// index (0 to n)
	if (index > MAX_INDEX || index < 0) {
		printf("Out Of Range Error : index %d\n", index);
		return -1;
	}

	List *newNode = Init_List(data);
	
	if (index == 0) {
		List *second = *head;
		List **first = head;
		(*first) = newNode;
		(*first)->next = second;
	}

	else if (index == MAX_INDEX) { /// This part is the same as func AppendNode(head, data)
		List **node = head;

		while ((*node)->next != NULL) {
			node = &((*node)->next);
		}
		(*node)->next = newNode;
	}
	else {
		List **node = head;

		for (int i = 0; i < index-1; i++) {
			node = &((*node)->next);
		}
		newNode->next = (*node)->next;
		(*node)->next = newNode;
	}
	return 1;
}

void PrintList(List **head) {
	List *l = *head;

	while (l != NULL) {
		printf("%d ", l->data);
		l = l->next;
	}
	puts("");
}

int RemoveNode(List **head, int index) {
	List **node = head;

	if (index < 0 || index > MAX_INDEX) {
		printf("Out Of Range Error : index %d\n", index);
		return -1;
	}

	if (index == 0) {
		(*head) = (*node)->next;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			node = &((*node)->next);
		}
		(*node)->next = (*node)->next->next;
	}

	return 1;
}
