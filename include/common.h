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

head_t* createHead(const int size, const node_t *front, const node_t* rear);
node_t* createNode(const int data, const node_t* next, const node_t* previous);