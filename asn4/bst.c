/*
This program implements binary search trees encoded using arrays.
*/
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/*
This function creates a binary seach tree.
*/
// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
BStree bstree_ini(int size) 
{
  BStree tree;
  int i;
  tree = (BStree)malloc(sizeof(BStree_struct));  /* Allocate memory of type BStree_struct */
  Node tree_nodes[size + 1];
  unsigned char is_free[size + 1];
  tree->tree_nodes = (Node *)malloc((size + 1)*sizeof(Node)); /* Allocate memory for a Node array for member tree_nodes */
  tree->is_free = (unsigned char *)malloc((size + 1)*sizeof(unsigned char)); // Allocate memory for an unsigned char array of size+1 for member is_free
  for (i = 0; i < size + 1; i ++)
  {
    tree->is_free[i] = 1; // set all entries of is_free to 1
  }
  tree->size = size; // set member size to ’size’;
  return tree;
}

/*
This function helps to insert nodes by checking if node to insert is bigger or smaller than root and opther nodes and inserts left or right of the nodes.
*/
void helper_insert(BStree bst, int i, Key *key, int data)
{
  int keyCompar;
  if (i > bst->size)
  {
    printf("Array out of bound!\n");
    return;
  }
  if (bst->is_free[i] == 1)
  {
    bst->tree_nodes[i].key = key;
    bst->tree_nodes[i].data = data;
    bst->is_free[i] = 0;
  }
    keyCompar = key_comp(*bst -> tree_nodes[i].key, *key);
    if (keyCompar == 1)
    {
      helper_insert(bst,  2*i, key, data); //go left child
    }
    if (keyCompar == -1)
    {
      helper_insert(bst,  2*i+1, key, data); //go right child
    }
}

/*
This function inserts nodes .
*/
// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
// insertion checks the array bound.
void bstree_insert(BStree bst, Key *key, int data) 
{
  helper_insert(bst, 1, key, data);
}

/*
This function helps to traverse the tree.
*/
void helper_traversal(BStree bst, int i)
{
   if (bst->is_free[i] != 1)
   {
  	if (2*i < bst->size + 1) {
     	  helper_traversal(bst, 2*i); //traverse left children
    	} 
   	print_node(bst -> tree_nodes[i]);
    	if ( 2*i + 1 < bst->size + 1) {
     	  helper_traversal(bst, 2*i+1); //traverse right children
        }
   }
}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) 
{
  helper_traversal(bst, 1);
}

// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) 
{
  int i;
  for (i = 0; i < bst->size + 1; i++)
  {
    if (bst->is_free[i] == 0)
    {
      free(bst->tree_nodes[i].key->name);
    }
  }
  free(bst->tree_nodes);
  free(bst->is_free);
  free(bst);
}

