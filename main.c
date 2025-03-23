#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "node.h"
#include "traversals.h"
#include "buildTree.h"
#include "queue.h"

/*
* basename gets the base name of text file passed in
* @param *path - path with basename at the end
* @return char with pathname
*/
char *getBaseName(char const *path);

char *getBaseName(char const *path) {
    char *s = (char *) strrchr(path, '/');

    char *name = (s == NULL) ? strdup(path) : strdup(s + 1);
    
    if (name == NULL) return NULL;
    
    char *dot = (char *) strrchr(name, '.');
    if (dot != NULL) {
        *dot = '\0';
    }
    
    return name;
}

int main(int argc, char* argv[]) {

  if (argc == 2) {

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
      perror("FATAL: Could not open file\n");
      return -1;
    }
    
    // get file name from path
    char *fileName = getBaseName(argv[1]);

    // when 
    node_t *root = buildTree(file);
    
    if (root == NULL) {
      printf("FATAL: Failed to build tree!\n");
      return -1;
    }
  
    traverseLevelOrder(root, fileName);
    traversePreOrder(root, fileName);
    traversePostOrder(root, fileName);

    free(fileName);
    fclose(file);

    printf("Tree Built & Traversals Done!\n");

  } else if (argc == 1) {
    printf("READ FROM KEYBOARD [NOT IMPLEMENTED]");
  } else {
    printf("FATAL: Improper usage\n");
  }

}