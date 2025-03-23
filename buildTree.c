#include "buildTree.h"
#include <stdbool.h>

node_t* buildTree(FILE *file) {

  node_t *treeHead = NULL;

  char inputString[250];
  while (fscanf(file, "%s", inputString) != EOF) {
    // validate string and get length
    int inputLength = validateInputStringAndGetLength(inputString);
    if (inputLength == -1) {
      exit(-1);
    }
    
    addNode(&treeHead, inputLength, inputString);
  }
  return treeHead;
}

int validateInputStringAndGetLength(char *inputString) {

  int inputLength = 0;
  for (int i = 0; inputString[i] != '\0'; i++) {
    inputLength++;

    bool charValid = false;

    // Check if A - Z
    if (inputString[i] >= 65 && inputString[i] <= 90) {
      charValid = true;
    }

    // Check if a - z
    if (inputString[i] >= 97 && inputString[i] <= 122) {
      charValid = true;
    }

    // Check if 0 - 9
    if (inputString[i] >= 48 && inputString[i] <= 57) {
      charValid = true;
    }

    // Check if special character ! " # $ % & ( ) * +
    if (inputString[i] >= 33 && inputString[i] <= 43) {
      charValid = true;
    }

    if (!charValid) {
      printf("FATAL: Invalid character: %c", inputString[i]);
      return -1;
    }
  }
  return inputLength;
}