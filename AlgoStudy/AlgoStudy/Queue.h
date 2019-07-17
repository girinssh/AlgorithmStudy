#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	int size;
	Node* first;
	Node* rear;
}Queue;

Queue* Init_Queue(void);

void Enqueue(Queue* q, int data);

int Dequeue(Queue* q);

int Front(Queue* q);
int Rear(Queue* q);
int Size(Queue *q);
