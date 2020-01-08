/* This program displays integer in seven-segment
display format. */
#include <stdio.h>
#include <string.h>
/*
 * Main function 
 */
int main() {
  /* Declare variables */
  char cont = 'Y';
  char chars[453]; 
  int toDisplay = 0;
  
  const char segments[10][3][3] =
  { { {' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'} }, { {' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'} }, { {' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '} }, { {' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'} }, { {' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'} }, { {' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'} }, { {' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'} }, { {' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'} }, { {' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'} }, { {' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'} } }; //3D array of char-s to store 10 digits

  printf("\t\tWelcome! This program displays integer in seven-segment display format!\n\n");
  while (cont == 'Y') {
    printf("\nEnter an integer that you want to display: ");
    	scanf(" %d", &toDisplay);
		sprintf(chars, "%d", toDisplay);
		int i;
    int row;
    int j;

    if (chars[0] == '-') {
			for (row = 0; row < 3; row ++) { //Print first rows for each 2D array then their second and third rows
        if (row == 0)
          printf("  ");
				if (row == 1) 
					printf("_ ");
				if (row == 2)
          printf("  ");
			  for (i = 1; i < strlen(chars); i ++) {
					for (j = 0; j < 3; j ++) {
						printf("%c", segments [chars[i] - '0'] [row] [j]);
					}
				} printf("\n");
			}
		}
    else {
      for (row = 0; row < 3; row ++) {
        for (i = 0; i < strlen(chars); i ++) {
					for (j = 0; j < 3; j ++) {
						printf("%c", segments [chars[i] - '0'] [row] [j]);
					}
				} printf("\n");
			}
    }
    
    printf("\n\nEnter 'Y' to continue or 'N' to quit: ");
    scanf(" %c", &cont);
    }
}
  