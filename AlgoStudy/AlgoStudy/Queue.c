#include "Queue.h"

Queue* Init_Queue(void) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->size = 0;
	q->first = NULL;
	q->rear = NULL; 
	return q;
}

void Push(Queue* q, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if(q->size == 0){
		q->first = newNode;
		q->rear = newNode;
	}
	else
		q->rear->next = newNode;
	q->size += 1;
	return;
}

int Pull(Queue* q) {
	int data = q->first->data;
	Node* del_node = q->first;
	q->first = del_node->next;

	free(del_node);
	q->size -= 1;
	
	if(q->size == 0)
		q->rear = NULL;

	return data;
}

int Front(Queue *q){
	return q->first->data;
}
int Rear(Queue *q){
	return q->rear->data;
}
int Size(Queue *q){
	return q->size;
}