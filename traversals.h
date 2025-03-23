#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include "node.h"

/*
* printPreOrderParseTree 
* @param *rootP is a pointer to the binary tree head
* @param level is the binary tree level
* @param *fileP is a pointer to the file passed in
*/
void printPreOrderParseTree(node_t *rootP, int level, FILE *fileP);

/*
* printPostOrderParseTree 
* @param *rootP is a pointer to the binary tree head
* @param level is the binary tree level
* @param *fileP is a pointer to the file passed in
*/
void printPostOrderParseTree(node_t *rootP, int level, FILE *fileP);

/*
* traverseLevelOrder outputs level order of tree to file
* @param *root is a pointer to the binary tree head
* @param *fileP is a pointer to the file passed in
*/
void traverseLevelOrder(node_t *root, char *fileName);

/*
* traversePreOrder outputs pre order of tree to file
* @param *root is a pointer to the binary tree head
* @param *fileP is a pointer to the file passed in
*/
void traversePreOrder(node_t *root, char *fileName);

/*
* traversePostOrder outputs post order of tree to file
* @param *root is a pointer to the binary tree head
* @param *fileP is a pointer to the file passed in
*/
void traversePostOrder(node_t *root, char *fileName);



#endif