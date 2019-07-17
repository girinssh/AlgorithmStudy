#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct CircledQueue {
	int maxSize;
	int* data;
	int front;
	int rear;
}CircledQueue;

CircledQueue* Init_Queue(void);

void Enqueue(CircledQueue* q, int data);

int Dequeue(CircledQueue* q);

int Front(CircledQueue* q);
int Rear(CircledQueue* q);
int CurrentSize(CircledQueue *q);
