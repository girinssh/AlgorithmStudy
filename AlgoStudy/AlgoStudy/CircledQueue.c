#include "CircledQueue.h"

CircledQueue* Init_CircledQueue(int maxSize) {
	CircledQueue* q = (CircledQueue*)malloc(sizeof(CircledQueue));
	q->data = (int*)malloc(sizeof(int) * maxSize);
	q->maxSize = maxSize;
	q->front= 0;
	q->rear = 0;
	return q;
}

void Enqueue(CircledQueue* q, int data) {
	if ((q->rear + 1) % q->maxSize == q->front) {
		return;
	}
	q->rear = (q->rear+1)%q->maxSize;
	q->data[q->rear] = data;
	return;
}

int Dequeue(CircledQueue* q) {
	if ((q->front + 1) % q->maxSize == q->rear) {
		return;
	}
	q->front = (q->front + 1) % q->maxSize;

	return q->data[q->front];
}

int Front(CircledQueue *q){
	return q->data[q->front];
}
int Rear(CircledQueue *q){
	return q->data[q->rear];
}
