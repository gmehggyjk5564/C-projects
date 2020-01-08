/* This program implements a converter, which converts values from metric system to imperial system and the other way around. */
#include <stdio.h>

/*
 *  * Function takes 2 units and a multiplier for converting and shows converted value
 *   */
int convert(char unit1[], char unit2[], float multiplier) {
    /* Declare variables */
    float value;
    float entered;
    
    printf("\nEnter %s value: ", unit1);  //asks input value
    scanf("%f",&value);
    entered = value;
    value = value*multiplier;  //converts value 
    printf("\n\t\tResult: %f %s is equal to: %f %s.", entered, unit1, value, unit2);
    return 1;
} 

/*
 *  * Here the function asks for the conversion direction and input values, then displays the result.
 *   */
int doAction(char action) {

    /* Declare variables */
    char unit;
    int done = 0;

    /* Ask for the conversion direction */
    while(done != 1) {
        if(action == 1) {
            printf("Enter 'K' for conversion from Kilometer to Mile: ");
            printf("Enter 'M' for conversion from Mile to Kilometer: ");
            scanf(" %c",&unit);

            if(unit == 'K') {
                done = convert("km","mi",0.621371); 
            }
            else if(unit == 'M') {
                done = convert("mi","km",1.609344);
            } 
            else {
              printf("\nYou entered an invalid character!\n\n");
            }
        }
        else if(action == 2) {
            printf("Enter 'M' for conversion from Meter to Feet: ");
            printf("Enter 'F' for conversion from Feet to Meter: ");
            scanf(" %c",&unit);

            if(unit == 'M') {
                done = convert("m","ft",3.28084);
            }
            else if(unit == 'F') {
                done = convert("ft","m",0.3048);
            }
            else {
              printf("\nYou entered an invalid character!\n\n");
            }
        }
        else if(action == 3) {
            printf("Enter 'C' for conversion from Centimetre to Inch: ");
            printf("Enter 'I' for conversion from Inch to Centimetre: ");
            scanf(" %c",&unit);

            if(unit == 'C') {
                done = convert("cm","in",0.393701);
            }
            else if(unit == 'I') {
                done = convert("in","cm",2.54);
            }
            else {
              printf("\nYou entered an invalid character!\n\n");
            }
        }
        else if(action == 4) {
             /* Declare variables */
            float value;
            float entered;
            
            printf("Enter 'C' for conversion from Celsius to Fahrenheit: ");
            printf("Enter 'F' for conversion from Fahrenheit to Celsius: ");
            scanf(" %c",&unit);

            if(unit == 'C') {
                printf("\nEnter Celsius value: ");
                scanf("%f",&value);
                entered = value;
                value = value*1.8 + 32;
                printf("\n\t\tResult: %f Celsius is equal to %f Fahrenheit.", entered, value);
                done = 1;
            }
            else if(unit == 'F') {
                printf("\nEnter Fahrenheit value: ");
                scanf("%f",&value);
                entered = value;
                value = (value-32)/1.8;
                printf("\n\t\tResult: %f Fahrenheit is equal to %f Celsius.", entered, value);
                done = 1;
            }
            else {
              printf("\nYou entered an invalid character!\n\n");
            }
        }
        
    }

    return 0;
} 

/*
 *  * Main function 
 *   */
int main () {
    /* Declare variables */
    int action;
    float value;

    printf("\t\tWelcome! This converter helps to convert between imperial and metric values!");
    while(action != 5) {
        printf("\n\n\nEnter 1-5 to choose an action:\n\n");
        printf("1 for conversion between Kilometer and Mile\n");
        printf("2 for conversion between Meter and Feet\n");
        printf("3 for conversion between Centimetre and Inch\n");
        printf("4 for conversion between Celsius and Fahrenheit\n");
        printf("5 for quit\n\n");

        do {
            printf("Enter action number: ");
            scanf("%d",&action);
           
            printf("\n");
            switch(action) {
                case 1: doAction(1);break;
                case 2: doAction(2);break;
                case 3: doAction(3);break;
                case 4: doAction(4);break;
            }
        } while(action < 1 || action > 5);
    } 
    return 0;
} 


