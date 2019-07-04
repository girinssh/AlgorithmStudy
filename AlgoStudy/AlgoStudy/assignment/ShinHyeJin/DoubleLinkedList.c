#include "DoubleLinkedList.h"
#define MAX_INDEX Length(list)
List* Init_List(void) {
	List* l = (List*)malloc(sizeof(List));
	l->size = 0;
	l->head = NULL;

	return l;
}

int Length(List *list) {
	return list->size;
}

int ListAppendNode(List *list, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->before = NULL;

	if (list->head == NULL) {
		list->head = newNode;
		list->size += 1;
		return 1;
	}

	Node *node = list->head;

	while (node->next != NULL) {
		node = node->next;
	}
	node->next = newNode;
	newNode->before = node;
	list->size += 1;
	return 1;
}

int ListInsertNode(List *list, int index, int data) {	/// index (0 to n)
	if (index > MAX_INDEX || index < 0) {
		printf("Out Of Range Error : index %d\n", index);
		return -1;
	}

	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->before = NULL;

	if (index == 0) {
		newNode->next = list->head;
		list->head->before = newNode;
		list->head = newNode;
	}

	else {
		Node *node = list->head;
		for (int i = 0; i < index - 1; i++) {
			node = node->next;
		}
		if (node->next == NULL) {
			node->next = newNode;
			newNode->before = node;
		}
		else {

			Node* nextNode = node->next;
			newNode->next = nextNode;
			nextNode->before = newNode;
			node->next = newNode;
			newNode->before = node;
		}
	}
	list->size += 1;
	return 1;
}

void PrintListBack(List *list) {
	Node *n = list->head;

	while (n->next != NULL) {
		n = n->next;
	}
	while (n != NULL) {
		printf("%d ", n->data);
		n = n->before;
	}
	puts("");
}

void PrintList(List *list) {
	Node *n = list->head;

	while (n != NULL) {
		printf("%d ", n->data);
		n = n->next;
	}
	puts("");
}

int ListRemoveNode(List *list, int index) {
	Node *node = list->head;

	if (index < 0 || index > MAX_INDEX) {
		printf("Out Of Range Error : index %d\n", index);
		return -1;
	}

	Node *del_node;
	if (index == 0) {
		del_node = list->head;
		list->head = del_node->next;
		list->head->before = NULL;
	}
	else {
		Node *pre_node = list->head;
		for (int i = 1; i < index - 1; i++) {
			pre_node = pre_node->next;
		}
		del_node = pre_node->next;
		Node *nextNode = del_node->next;

		pre_node->next = nextNode;
		nextNode->before = pre_node;
		
	}
	free(del_node);
	list->size -= 1;
	return 1;
} 