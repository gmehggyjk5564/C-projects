#include "matrix.h"

/*Matrix construction*/
Matrix matrix_construction(void)
{
  Matrix matrix = bstree_ini();
  return matrix;
}

/*If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.*/
unsigned char matrix_isin(Matrix m, Index index1, Index index2)
{
Key key = key_gen(index1, index2);
  Data data = bstree_search(m, key);
  if (data == NULL) 
      return 0;
  else 
    return 1;
}

/*If location (index1, index2) is defined in Matrix m, then return a pointer to the associated value. Otherwise, return NULL.*/
Value *matrix_get(Matrix m, Index index1, Index index2)
{
  Key key = key_gen(index1, index2);
	return bstree_search(m, key);
}

/*Assign value to Matrix m at location (index1, index2). If that location already has value,then overwrite.*/
void matrix_set(Matrix m, Index index1, Index index2, Value value)
{
  if (matrix_get(m, index1, index2) == NULL) {
    Key key = key_gen(index1, index2);
    Data data = data_gen(value);
    bstree_insert(m, key, data); 
  }
  else 
    *matrix_get(m, index1, index2) = value;
}

/*If location (index1, index2) is defined in Matrix m, then increase the associated value by value. Otherwise, report error.*/
void matrix_inc(Matrix m, Index index1, Index index2, Value value)
{
  Data data = matrix_get(m, index1, index2);
  if (data != NULL) {
    matrix_set(m, index1, index2, *data + value);
  }
  else {
    printf("This matrix location is not defined!");
  }
}

/*Print indices and values in the Matrix m(with bstree_traversal()).*/
void matrix_list(Matrix m)
{
  bstree_traversal(m);
}

/*Free allocated space (with bstree_free()).*/
void matrix_destruction(Matrix m)
{
  bstree_free(m);
}

	


