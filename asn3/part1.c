/*This program implements a simple calculator, called ”evaluate”, to evaluate simple arithmetic expression.*/
#include <stdio.h>
#include <stdlib.h>

// Effect: get the next operator of the expression
// this operator can be +, -, *, /, or ’\n’
// ’\n’ indicates the end of the expression input
// leading spaces should skipped
// Output: return the next operator of the expression.
char get_op() {
  char nextOp = ' ';
  while (nextOp == ' ') {
    scanf("%c", &nextOp);
  }
  return nextOp;
}

// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.
float get_num() {
  float aNum;
  scanf(" %f", &aNum);
  return aNum;
}

/*
 * m_exp() function evaluates an m_exp
 */
float m_exp(float sub_exp, char op) {
  if (op == '+' || op == '-' || op == '\n') {
    ungetc(op, stdin);
    return sub_exp;
  } 
  if (op == '*' || op == '/') {
    float next_num = get_num();
    char next_op = get_op();
    if (op == '*') {
      return m_exp(sub_exp*next_num, next_op);
    }
    if (op == '/') {
      return m_exp(sub_exp/next_num, next_op);
    }
    else {
      printf("You entered a non-valid operator!");
      exit(EXIT_FAILURE);
    }
  }
}


/*
 * s_exp() function evaluates an s_exp
 */
float s_exp(float sub_exp, char op){
  if(op == '\n'){
    return sub_exp;
  }
  float next_num;
  char next_op;
  if(op == '*' || op == '/'){
    next_num = m_exp(sub_exp, op);
    next_op = get_op();
    return s_exp(next_num, next_op);
  }
  if (op == '+') {
    next_num = get_num();
    next_op = get_op();
    return sub_exp + s_exp(next_num, next_op);
  }
  if (op == '-') {
    next_num = get_num();
    next_op = get_op();
    return sub_exp + s_exp(-next_num, next_op);
  }
  else {
    printf("You entered a non-valid operator!");
    exit(EXIT_FAILURE);
  }
}

/*
 * Main function 
 */
int main() {
  /* Declare variables */
  //char str[]; //a string as an array of characters
  char cont = 'Y';

  printf("\t\tCalculator 'Evaluate' \n\n");
  printf("Welcome! This calculator, called 'Evaluate' helps to evaluate simple arithmetic expressions!\n\n");
  while (cont == 'Y') {
    printf("Enter a simple arithmetic expression: ");
    float endExpr = s_exp(0, '+');
    printf("The result is: %f\n\n", endExpr);
    printf("Enter 'Y' to continue or 'N' to quit: ");
    scanf(" %c", &cont);
  }
}      
            
