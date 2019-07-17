#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(void) {
	Queue* q = Init_Queue();

	Enqueue(q, 1);
	Enqueue(q, 2);
	printf("%d\n", Front(q));
	printf("%d\n", Rear(q));
	printf("%d\n", Dequeue(q));
	printf("%d\n", Dequeue(q));
	
	system("pause");
	return 0;
}