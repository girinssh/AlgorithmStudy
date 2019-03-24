#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void) {
	List *a = Init_List(0);

	printf("%d\n", (*a).data);

	system("pause");
	return 0;
}