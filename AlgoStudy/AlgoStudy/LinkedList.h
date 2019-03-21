#pragma once
#include <stdio.h>

typedef struct List{
	int data;
	struct List* next;
}List;

List Init(int data);