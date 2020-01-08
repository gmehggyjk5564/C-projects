#include "matrix.h"

/*Main program*/
int main(void) {
/*Initialize variables*/
char str1[401];
char str2[379];
/*Create a new Matrix*/
Matrix m = matrix_construction();
printf("\n\nPlease enter a pair of 1st string and 2nd string  : \n");
while (scanf("%s %s", str1, str2) == 2)
{
  /*Calculate occurences of each string pair*/
  unsigned char exists = matrix_isin(m, str1, str2);
        /*set the 1st occurence*/
        if (exists == 0) 
            matrix_set(m, str1, str2, 1);
        /*increment if such string pair already exists*/
        if (exists == 1) 
            matrix_inc(m, str1, str2, 1);
}
/*Print the data in the Matrix*/
printf("String 1                String 2                Occurrence\n");
matrix_list(m);
matrix_destruction(m);
return 0;
}      




