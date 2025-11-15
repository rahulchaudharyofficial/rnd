#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<stdbool.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

typedef struct Head head_t;
typedef struct Node node_t;

head_t* _createHead(void);
node_t* _createNode(void);
head_t* createHead( int size,  node_t *front,  node_t* rear);
node_t* createNode( int data,  node_t* next,  node_t* previous);