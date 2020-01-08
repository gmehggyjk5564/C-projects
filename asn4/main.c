// Main program
#include <stdio.h>
#include "bst.h"

int main(void) {
BStree bst;
int id, data, size;
char name[312];
printf("\nPlease enter size of a tree:");
scanf("%d", &size);
bst = bstree_ini(size);
printf("\nTo STOP inserting triples enter 's 1 1'");
printf("\n\nPlease enter triples of name, id and data: \n");
while (scanf("%s %d %d", name, &id, &data) == 3)
{
  if (name[0] == 's' && id == 1 && data == 1)
  {
    break;
  } 
  bstree_insert(bst, key_construct(name, id), data);
}
bstree_traversal(bst);
bstree_free(bst);
}

