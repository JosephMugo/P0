#include "traversals.h"
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// This function takes the root binary tree node and ouputs pre order to file
void printPreOrderParseTree(node_t *rootP, int level, FILE *fileP) {
  if (rootP == NULL) return;
  fprintf(fileP, "%*d %d", level * 4, level, rootP->value);
  outputList(rootP->listHead, fileP);
  fprintf(fileP, "\n");
  printPreOrderParseTree(rootP->left, level+1, fileP);
  printPreOrderParseTree(rootP->right, level+1, fileP);
}

// This function takes the root binary tree node and ouputs post order to file
void printPostOrderParseTree(node_t *rootP, int level, FILE *fileP) {
  if (rootP == NULL) return;
  printPostOrderParseTree(rootP->left, level+1, fileP);
  printPostOrderParseTree(rootP->right, level+1, fileP);
  fprintf(fileP, "%*d %d", level * 4, level, rootP->value);
  outputList(rootP->listHead, fileP);
  fprintf(fileP, "\n");
}


void traverseLevelOrder(node_t *root, char *fileName) {
  if (root == NULL) return;

  // combines fileName provided and type of traversal to create file
  char full_file_name[100];
  sprintf(full_file_name, "%s.levelorder", fileName);

  FILE *fileP;
  fileP = fopen(full_file_name, "w");

  if (fileP == NULL) {
    printf("FATAL: could not open file");
    exit(-1);
  }

  /*
    This uses a queue which is FIFO, which allows for the
    different binary tree levels to be proccessed individually
  */
  queue q1;
  initQueue(&q1);
  enqueue(&q1, root);

  int level = 0;
  while (q1.head) {
    int level_count = queueSize(&q1);
    for (int i = 0; i < level_count; i++) {
      node_t *current = q1.head->value;
      fprintf(fileP, "%*d %d", level * 4, level, current->value);
      outputList(current->listHead, fileP);

      if (current->left != NULL) {
        enqueue(&q1, current->left);
      }
      if (current->right != NULL) {
        enqueue(&q1, current->right);
      }
      
      dequeue(&q1);
      fprintf(fileP, "\n");
    }
    
    level++;
  }
  fclose(fileP);
}

void traversePreOrder(node_t *root, char *fileName) {
  char full_file_name[100];
  sprintf(full_file_name, "%s.preorder", fileName);

  FILE *fileP;
  fileP = fopen(full_file_name, "w");

  if (fileP == NULL) {
    printf("FATAL: could not open file");
    exit(-1);
  }

  printPreOrderParseTree(root, 0, fileP);

  fclose(fileP);
}

void traversePostOrder(node_t *root, char *fileName) {
  char full_file_name[100];
  sprintf(full_file_name, "%s.postorder", fileName);

  FILE *fileP;
  fileP = fopen(full_file_name, "w");

  if (fileP == NULL) {
    printf("FATAL: could not open file");
    exit(-1);
  }

  printPostOrderParseTree(root, 0, fileP);

  fclose(fileP);
}
