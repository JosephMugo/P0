#ifndef BUILDTREE_H
#define BUILDTREE_H
#include "node.h"
#include <stdio.h>

int validateInputStringAndGetLength(char *inputString);

node_t* buildTree(FILE *file);

#endif