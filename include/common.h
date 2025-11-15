#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<stdbool.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#define DEFAULT_SIZE -1

typedef struct Head head_t;
typedef struct Node node_t;

head_t* createHead(void);
node_t* createNode(const int data);

// head methods
int get_head_size(head_t*);
node_t* get_head_front(head_t*);
node_t* get_head_rear(head_t*);
void set_head_size(head_t* head, int size);
void set_head_front(head_t* head, node_t* front);
void set_head_rear(head_t* head, node_t* rear);

// node methods
int get_node_data(node_t*);
node_t* get_node_previous(node_t*);
node_t* get_node_next(node_t*);
void set_node_data(node_t* node, int data);
void set_node_previous(node_t* to, node_t* previous);
void set_node_next(node_t* to, node_t* next);