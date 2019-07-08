#include "Stack.h"
#define MAX_INDEX s->size
Stack* Init_Stack(void) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->size = 0;
	s->top = NULL;

	return s;
}

int Push(Stack* s, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
	s->size += 1;
	return 1;
}

void PrintTop(Stack* s) {
	printf("%d ", s->top->data);
	
	puts("");
}

int Pop(Stack* s) {
	int data = s->top->data;
	Node* del_node = s->top;
	s->top = del_node->next;

	free(del_node);
	s->size -= 1;
	return data;
}
