/* 
 * File:   main.c
 * Author: Jake Day
 * Class: COEN 20
 * Instructor: Lewis
 * Created on April 12, 2017, 11:51 AM
 * Description: This program takes an integer from -128 to 255 as an input and
 * displays its 8-bit binary representation as unsigned, 2's complement, or both.
 */

#include <stdio.h>
#include <stdlib.h>

void PrintBinary(int binary[8]);
void Dec2Bin(int num, int binary[8]);

int main() {
    int input, bin[8];
    
    //prompt for a decimal integer from -128 to 255
    printf("Enter a decimal integer (-128 to 255): ");
    
    //read integer from the keyboard
    scanf("%d", &input);
    
    //checks which range the input is in
    if (input < -128 || input > 255) {
        printf("out of range\n");
        exit(EXIT_FAILURE);
    } else if (input > 127) {
        printf("+128 to +255\nUnsigned: ");
        Dec2Bin(input, bin);
    } else if (input > -1) {
        printf("0 to +127\nUnsigned and 2's complement: ");
        Dec2Bin(input, bin);
    } else {
        printf("-128 to -1\n2's complement: ");
        Dec2Bin(input + 256, bin);
    }
    
    PrintBinary(bin);

    return (EXIT_SUCCESS);
}

//prints the contents of the array storing the 8-bit binary representation
void PrintBinary(int binary[8]) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

//takes the decimal number and inserts its binary representation into an array
void Dec2Bin(int num, int binary[8]) {
    int i = 0;
    
    while (num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }
}