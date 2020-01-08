#include "datatype.h"

/*Duplicate string pointed to by str with dynamic memory allocation.*/
char * string_dup(char *str)
{
  char *dup;
  dup = (char *)malloc((strlen(str) + 1)*sizeof(char));
	dup = strcpy(dup, str);
	return dup;
}

/*Generate a key with dynamic memory allocation.*/
Key key_gen(char *skey1, char *skey2)
{
  Key aKey;
  aKey = (Key)malloc(sizeof(Key_struct)); /* Allocate bytes */
  aKey->skey1 = string_dup(skey1);
  aKey->skey2 = string_dup(skey2);
  return aKey;
}

/*Use strcmp( ) to do comparison. If key1->skey1 and key2->skey1 are different, then they determine the comparison result. If key1->skey1 and key2->skey1 are the same,then key1->skey2 and key2->skey2 determine the comparison result.*/
int key_comp(Key key1, Key key2)
{
  if (strcmp(key1->skey1, key2->skey1) != 0)
    {
        return strcmp(key1->skey1, key2->skey1);
    } 
  else
    {
        return strcmp(key1->skey2, key2->skey2);
    }
}

/*Print a key.*/
void key_print(Key key)
{
  printf("%-20s\t%-20s\t", key->skey1, key->skey2);
}


/*Free memory allocated for key.*/
void key_free(Key key)
{
  free(key->skey1);
  free(key->skey2);
  free(key);
}

/*Generate a data with dynamic memory allocation.*/
Data data_gen(int idata)
{
  Data data;
  data = (Data)malloc(sizeof(int)); /* Allocate bytes */
  
  *data = idata;
  return data;
}

/*Assign data with idata.*/
void data_set(Data data, int idata)
{
  *data = idata;
}

/*Print a data */
void data_print(Data data)
{
  printf("%d", *data);
}

/*Free memory allocated for data.*/
void data_free(Data data)
{
  free(data);
}








