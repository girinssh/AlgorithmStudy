#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	int data;
	struct List* next;
}List;

List* Init_List(int data);

int AppendNode(List **head, int data);
int InsertNode(List **head, int index, int data);

void PrintList(List **head);

int RemoveNode(List **head, int index);
