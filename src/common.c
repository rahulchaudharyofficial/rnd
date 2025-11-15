#include "common.h"


struct Head {
	int size;
	node_t* front;
	node_t* rear;
};

struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
};

head_t* createHead(void)
{
	head_t* head = (head_t*)malloc(sizeof(head_t));
	if (NULL != head)
	{
		head->size = DEFAULT_SIZE;
		head->front = NULL;
		head->rear = NULL;
	}
	return head;
}

node_t* createNode(const int data)
{
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if(NULL != node)
	{ 
		node->data = data;
		node->next = NULL;
		node->previous = NULL;
	}
	return node;
}

// head methods
int get_head_size(head_t* head) { return (NULL!=head ? head->size : DEFAULT_SIZE); }
node_t* get_head_front(head_t* head) { return (NULL != head ? head->front : NULL); }
node_t* get_head_rear(head_t* head) { return (NULL != head ? head->rear : NULL); }
void set_head_size(head_t* head, int size) { if (NULL != head) head->size = size; }
void set_head_front(head_t* head, node_t* front) { if (NULL != head) head->front = front; }
void set_head_rear(head_t* head, node_t* rear) { if (NULL != head) head->rear = rear; }

// node methods
int get_node_data(node_t* node) { return (NULL != node? node->data : DEFAULT_SIZE); }
node_t* get_node_previous(node_t* node) { return (NULL != node ? node->previous : NULL); }
node_t* get_node_next(node_t* node) { return (NULL != node ? node->next : NULL); }
void set_node_data(node_t* node, int data) { if (NULL != node) node->data = data; }
void set_node_previous(node_t* to, node_t* previous) { if (NULL != to) to->previous = previous; }
void set_node_next(node_t* to, node_t* next) { if (NULL != to) to->next = next; }