#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(void) {
	Queue* q = Init_Queue();

	Push(q, 1);
	Push(q, 2);
	printf("%d\n", Front(q));
	printf("%d\n", Rear(q));

	system("pause");
	return 0;
}