#include "queue.h"
#include <stdio.h>

// initialize queue
void initQueue(queue *q) {
  q->size = 0;
  q->head = NULL;
  q->tail = NULL;
}

// get queue size
int queueSize(queue *q) {
    return q->size;
}

bool enqueue(queue *q, node_t *value) {
  // create new node
  queue_node *newnode = (queue_node *) malloc(sizeof(queue_node));
  if (newnode == NULL) return false;
  newnode->value = value;
  newnode->next = NULL;
  // if there is a tail, connect that tail to new node.
  if (q->tail != NULL) {
    q->tail->next = newnode;
  }
  q->tail = newnode;
  if (q->head == NULL) {
    q->head = newnode;
  }
  q->size++;
  return true;
}

node_t *dequeue(queue *q) {
  if (q->head == NULL) return NULL;

  queue_node *tmp = q->head;
  node_t *result = tmp->value;
  q->head = q->head->next;
  if (q->head == NULL) {
    q->tail = NULL;
  }
  free(tmp);
  q->size--;
  return result;
}
