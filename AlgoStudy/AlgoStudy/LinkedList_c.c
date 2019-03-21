#include <stdio.h>
#include "pch.h"

typedef struct List {
	int data;
	List* next;
}List;

List Init(int data) {
	List n;
	n.data = data;
	n.next = NULL;
	return n;
}

void Insert(List** head, int index, int data) {
	if (index == 0) {

	}
}