#include "common.h"


#define HEAD_LIST \
	HEAD_LIST_ARRTIBUTE (size, int) \
	HEAD_LIST_ARRTIBUTE (front, node_t*) \
	HEAD_LIST_ARRTIBUTE (rear, node_t*) \


#define NODE_LIST \
	NODE_LIST_ARRTIBUTE (data, int) \
	NODE_LIST_ARRTIBUTE (previous, node_t*) \
	NODE_LIST_ARRTIBUTE (next, node_t*) \

struct Node
{
	#define NODE_LIST_ARRTIBUTE(NAME, TYPE)	\
		TYPE NAME;
		NODE_LIST
	#undef NODE_LIST_ARRTIBUTE
};

struct Head {
	#define HEAD_LIST_ARRTIBUTE(NAME, TYPE)	\
		TYPE NAME;
		HEAD_LIST
	#undef HEAD_LIST_ARRTIBUTE
};
/**
 #define HEAD_LIST_ARRTIBUTE(NAME, TYPE) \
 	TYPE get_head_##NAME(void); \	
 	void set_head_##NAME(TYPE NAME); \
 	HEAD_LIST
 #undef HEAD_LIST_ARRTIBUT
 #define NODE_LIST_ARRTIBUTE(NAME, TYPE)	\
 	TYPE get_node_##NAME(void); 			\
 	void set_node_##NAME(TYPE NAME);		\
 	NODE_LIST
 #undef NODE_LIST_ARRTIBUTE
*/
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