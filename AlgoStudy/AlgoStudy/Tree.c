#include <stdio.h>

typedef struct node {
	char name[20];
	struct node* children[2];
}node;

typedef struct tree {
	node* root;
};