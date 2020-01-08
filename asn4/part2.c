/* This is a C program that approximates pi */
#include <stdio.h>
#include <math.h>

/* This is a helper function toc calculate pi by iterating values until n 
Input: n as the smallest integer based on the formula with epsilon and n.
Effect: return pi*/
double pi_calc(long long n) 
{
  double pi = 0;
  long long i;
  for (i = 1; i < n; i++)
   {
        if (i % 2) //if iterator is even
        {
          pi += 4.0/(2.0*i - 1.0);
        }
        else //if iterator is odd
        {
          pi -= 4.0/(2.0*i - 1.0);
        }
    }
    return pi;
}

/*Main
Input: void
Effect: prints approximation of the value of pi */
int main()
{
    double eps; //epsilon
    long long n = 0;
    double pi = 0;

    printf("Enter epsilon: ");
    scanf(" %lf", &eps);
    
    while (4.0/(2.0*(n + 1.0) - 1.0) >= eps) //to calculate n as the smallest integer such that this formula is true if an user entered small epsilon
    {
      n++;
    }
    pi = pi_calc(n);
    printf("%.16f \n", pi);
    return 0;
}
   



