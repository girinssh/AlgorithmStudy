#include "LinkedList.h"
#define MAX_INDEX Length(*head)-1
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

int insert(List **head, int index, int data) {	/// index (0 to n)
	if (index > MAX_INDEX || index < 0) {
		printf("Out Of Range Error : index %d\n", index);
		return -1;
	}

	List *node = Init(data);
	
	if (index == 0) {
		List *second = (*head);
		head = &node;
		(*head)->next = second;
	}

	else if(index == )


}