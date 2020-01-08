/*
This program implements binary search trees encoded using arrays.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

/*
This function constructs a key with specified name and id to be stored in a node.
*/
// Input: ’in_name’: a string ends with ’\0’
// ’in_id’: an integer
// Output: a pointer of type pointer to Key,
// pointing to an allocated memory containing a Key
// Effect: dynamically allocate memory to hold a Key and allocate memory for the Key’s name
Key *key_construct(char *in_name, int in_id) 
{
  Key *aKey;
  aKey = (Key *)malloc(sizeof(Key)); /* Allocate bytes */
  aKey->name = strdup(in_name);
  aKey->id = in_id;
  return aKey;
}

/*
This function will decide which key is less or larger by first looking at the name and then at the ids of keys.
*/
// Input: ’key1’ and ’key2’ are two Keys
// Output: if key1 is less than key2 the return -1, if more than return 1, if names of key1 and key2 are equal then compare their ids
int key_comp(Key key1, Key key2) 
{
  int returnVal;
  returnVal = strcmp(key1.name, key2.name); //  strcmp() to compare the strings in keys
   if (returnVal < 0)
  {
    return -1;
  }
  if (returnVal > 0)
  {
    return 1;
  }
  if (returnVal == 0)
  {
    if (key1.id < key2.id)
    {
      return -1;
    }
    if (key1.id == key2.id)
    {
      return 0;
    }
    if (key1.id > key2.id)
    {
      return 1;
    }
  }
}

// Input: ’key’: a pointer to Key
// Effect: name and id of the key is printed
void print_key(Key *key)
{
  printf("(%s       %d)",key->name,key->id);
}

// Input: ’node’: a node
// Effect: key of the node is printed and then the data of the node is printed
void print_node(Node node) 
{
  print_key(node.key);
  printf("    %d\n",node.data);
}

