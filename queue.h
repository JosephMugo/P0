#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include <stdbool.h>

typedef struct queue_node {
  node_t *value;
  struct queue_node *next;
} queue_node;

typedef struct queue {
  int size; 
  queue_node *head;
  queue_node *tail;
} queue;

void initQueue(queue *q);

int queueSize(queue *q);

bool enqueue(queue *q, node_t *value);

node_t *dequeue(queue *q);

#endif