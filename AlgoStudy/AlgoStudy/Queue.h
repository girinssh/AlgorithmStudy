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
}CircledQueue;

CircledQueue* Init_Queue(void);

void Enqueue(CircledQueue* q, int data);

int Dequeue(CircledQueue* q);

int Front(CircledQueue* q);
int Rear(CircledQueue* q);
int Size(CircledQueue *q);
