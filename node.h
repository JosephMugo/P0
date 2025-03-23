#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
  int value;
  struct list_item *listHead;
  struct node_t *left;
  struct node_t *right;
} node_t;

typedef struct list_item {
  char value[50];
  struct list_item *next;
} list_item;

/*
* createNode
* @param int value which represents string length
*/
node_t *createNode(int value);

/*
* addNode
* @param treeHead - pointer to tree head pointer
* @param input Length - input length to determine where node gets added in tree
* @param inputString is the string being added to tree
*/
void addNode(node_t **treeHead, int inputLength, char inputString[250]);

/*
* createNewItem 
* @param value is the string that is being created into a linked list item
*/
list_item *createNewItem(char *value);

/*
* addItem 
* @param head is a pointer to the linked list head
* @param newListItem is the new linked list item being added
*/
list_item *addItem(list_item *head, list_item *newListItem);

/*
* outputList 
* @param listHead is a pointer to the linked list head
* @param fileP is the file with string content
*/
void outputList(list_item *listHead, FILE *fileP);

#endif