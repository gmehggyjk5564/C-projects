#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int* Data;
typedef struct {char *skey1; char *skey2;} Key_struct;
typedef Key_struct* Key;

/*Duplicate string pointed to bystrwith dynamic memory allocation.*/
char * string_dup(char *str);

/*Generate a key with dynamic memory allocation.*/
Key key_gen(char *skey1, char *skey2);

/*Use strcmp( ) to do comparison. Ifkey1->skey1andkey2->skey1are different, thenthey determine the comparison result. Ifkey1->skey1andkey2->skey1are the same,thenkey1->skey2andkey2->skey2determine the comparison result.*/
int key_comp(Key key1, Key key2);

/*Print a key.*/
void key_print(Key key);

/*Free memory allocated for key.*/
void key_free(Key key);

/*Generate a data with dynamic memory allocation.*/
Data data_gen(int idata);

/*Assign data with idata.*/
void data_set(Data data, int idata);

/*Print a data.*/
void data_print(Data data);

/*Free memory allocated for data.*/
void data_free(Data data);





