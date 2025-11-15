#include "common.h"

struct Head {
	int size;
	struct Node* front;
	struct Node* rear;
};

struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
};

head_t* _createHead(void)
{
	head_t* head = (head_t*) malloc(sizeof(head_t));
	assert(head != NULL);
	return head;
}

node_t* _createNode(void)
{
	node_t* node = (node_t*)malloc(sizeof(node_t));
	assert(node != NULL);
	return node;
}

head_t* createHead( int size,  node_t* front,  node_t* rear)
{
	head_t* head = _createHead();
	head -> size = size;
	head->front = front;
	head->rear = rear;
	return head;
}

node_t* createNode( int data,  node_t* next,  node_t* previous)
{
	node_t* node = _createNode();
	node->data = data;
	node->next = next;
	node->previous = previous;
	return node;
}