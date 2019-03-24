#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	int data;
	struct List* next;
}List;

List* Init_List(int data);