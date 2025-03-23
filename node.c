#include "node.h"
#include <string.h>

/*
  This creates a binary search tree node
  that contains the properties:
    value - represent string length
    listHead - first linked list element
    left - pointer to another binary tree node to the left of parent
    right - pointer to anotehr binary tree node to the right of parent
*/
node_t *createNode(int value) {
  node_t* result = (node_t *) malloc(sizeof(node_t));
  if (result == NULL) {
    perror("FATAL: something went wrong");
    exit(-1);
  } else {
    result->value = value;
    result->listHead = NULL;
    result->left = NULL;
    result->right = NULL;
  }
  return result;
}

/*
  This recursive function adds a node to the tree.
  It takes in the root node then checks if the node is null
  if NULL
    it creates a new node and attaches a linked list containing string values
  else
    does check to see if node already exist or belongs on left or right side
*/
void addNode(node_t **treeHead, int inputLength, char inputString[250]) {
  if (*treeHead == NULL) {
    *treeHead = createNode(inputLength);
    (*treeHead)->listHead = addItem((*treeHead)->listHead, createNewItem(inputString));
  } else {
    // no insert (if string length is equal to node value add the word to the node list)
    if ((*treeHead)->value == inputLength) {
      (*treeHead)->listHead = addItem((*treeHead)->listHead, createNewItem(inputString));
    }
    // left insert
    if ((*treeHead)->value > inputLength) {
      addNode(&(*treeHead)->left, inputLength, inputString);
    }
    // right insert
    if ((*treeHead)->value < inputLength) {
      addNode(&(*treeHead)->right, inputLength, inputString);
    }
  }
}


// This function creates a linked list item to hold the string value for a certain length
list_item *createNewItem(char *value) {
  list_item *allocated_item = (list_item *) malloc(sizeof(list_item));
  if (allocated_item == NULL) {
    perror("FATAL: something went wrong");
    exit(-1);
  } 
  strcpy((*allocated_item).value, value);
  (*allocated_item).next = NULL;
  return allocated_item;
}

// This function adds the linked list item to binary tree node
list_item *addItem(list_item *head, list_item *newListItem) {
  (*newListItem).next = head;
  return newListItem;
}

// This function ouputs the items in the linked list for a certain binary tree node
void outputList(list_item *listHead, FILE *fileP) {
  list_item *temp = listHead;

  while (temp != NULL) {
    fprintf(fileP, " %s", temp->value);
    temp = temp->next;
  }

  free(temp);
}
