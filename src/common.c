#include "common.h"

struct Head {
	int size;
	struct Node* front;
	struct Node* rear;
};

struct Node
{
	int data;
	struct node* next;
	struct node* previous;
};

head_t* createHead(const int size, const node_t* front, const node_t* rear)
{
	return NULL;
}

node_t* createNode(const int data, const node_t* next, const node_t* previous)
{
	return NULL;
}