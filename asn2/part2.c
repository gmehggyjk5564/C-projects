/* This program implements an exponential number calculator */
#include <stdio.h>

/*
 *  * Function takes a positive float number 'a' for the base and integer number 'b' for the exponent, then returns float number 'a'^'b'
 *   * Function calculates the exponential number using recursion.
 *    */
float expNum(float a, int b) {
    /* Make 2 base cases */
    if(b == 0) return 1;
    else if(b == 1) return a;

    /* Recursive cases: */
    /* If n is even */
    else if(b % 2 == 0) {
      if (b > 0) {
        float aNum;
        aNum = expNum(a,b/2);
        return aNum*aNum;
      }
      else if (b < 0) {
        float aNum;
        aNum = expNum(a,b/2*-1);
        return 1/(aNum*aNum);
      }
    }
    /* If n is odd */
    else {
      if (b > 0) {
        float aNum;
        aNum = expNum(a,b/2);
        return aNum*aNum*a;
      }
      else if (b < 0) {
        float aNum;
        aNum = expNum(a,b/2*-1);
        return 1/(aNum*aNum*a);
      }
    }
} 

/**
 *  * Main function
 *   */
int main() {

    /* Declare variables */
    float a;
    int b;

    printf("\t\tWelcome! This is the Exponential Number Calculator!\n\n");
    do {
        /* Ask to input the base*/
        printf("Enter the base: ");
        scanf(" %f",&a);
        /* Check if input for the base is positive*/
        if(a < 0) printf("\nPlease enter a positive number for the base!\n\n");
    } while(a < 0);
       
    /* Ask to input the exponent */
    printf("\nEnter the exponent: ");
    scanf(" %d",&b);
    
    /* Display result */
    printf("\n\nThe exponential number with base %f and exponent %d is %f.\n\n", a, b, expNum(a,b));

    return 0;
} 
