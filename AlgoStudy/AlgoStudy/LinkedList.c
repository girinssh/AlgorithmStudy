#include "LinkedList.h"

List Init(int data) {
	List node;
	node.data = data;
	node.next = NULL;

	return node;
}