#include "bstree.h"

/*Allocate memory of type BStreenode*, set the value to NULL, and return a pointer to theallocated memory.*/
BStree bstree_ini(void)
{
  BStree bst;
	bst = (BStree)malloc(sizeof(BStree_node*)); 
	*bst = NULL;
	return bst;
}

/*Insert data with key in to bst. If key is in bst, then do nothing.*/
void bstree_insert(BStree bst, Key key, Data data)
{
  BStree_node* nodeTree = *bst;
  BStree_node* node = NULL; 

  while (nodeTree != NULL)
  {
    node = nodeTree;
    if (key_comp(nodeTree->key, key) < 0)
    {
      nodeTree = nodeTree->right;
    } 
    else if (key_comp(nodeTree->key, key) > 0)
    {
      nodeTree = nodeTree->left;
    } 
    else  /*key is in bst, then do nothing.*/
    	return;
    }

    if (node == NULL) /*if empty tree before insertion*/
    {
        *bst = (BStree_node*) malloc(sizeof(BStree_node));
        (*bst)->data = data;
        (*bst)->key = key_gen(key->skey1, key->skey2);
        (*bst)->left = NULL;
        (*bst)->right = NULL;
    } 
    else if (key_comp(node->key, key) < 0)
    { 
        node->right = (BStree_node*) malloc(sizeof(BStree_node)); /*go to right child*/
        node->right->data = data;
        node->right->key = key_gen(key->skey1, key->skey2);
        node->right->left = NULL;
        node->right->right = NULL;
    } 
    else
    { 
        node->left = (BStree_node*) malloc(sizeof(BStree_node)); /*go to left child*/
        node->left->data = data;
        node->left->key = key_gen(key->skey1, key->skey2);
        node->left->left = NULL;
        node->left->right = NULL;
    }
}

/*A helper function for insertion to create a pointer to a tree node from key and data.*/
BStree_node *new_node(Key key, Data data)
{
  BStree_node *node = (BStree_node *) malloc(sizeof(BStree_node));
	(*node).key = key;
	(*node).data = data;
	(*node).left = NULL;
	(*node).right = NULL;
	return node;
}

/*If key is in bst, return key’s associated data. If key is not in bst, return NULL.*/
Data bstree_search(BStree bst, Key key)
{
  BStree_node* node =*bst;
  if (*bst == NULL) 
   	 return NULL;
  else if (key_comp(key, node->key) < 0)
   	 return (bstree_search(&node->left,key));
  else if ((key_comp(key, node->key) > 0))
  	  return (bstree_search(&node->right,key));
  else
   	 return node->data;
}

/*In order traversal of bst and print each node’s key and data.*/
void bstree_traversal(BStree bst)
{
  if (*bst == NULL)
	return;
  BStree_node root = **bst;		
  if (root.left != NULL)
		bstree_traversal(&root.left);
  key_print(root.key);
  data_print(root.data);
  printf("\n");
  if (root.right != NULL)	
		bstree_traversal(&root.right);
}

/*Free all the dynamically allocated memory of bst.*/
void bstree_free(BStree bst)
{
  if (*bst == NULL)
	return;
  bstree_free(&(**bst).left);	
  bstree_free(&(**bst).right);
  free(*bst);
}



	









