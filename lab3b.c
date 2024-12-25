/*Write an algorithm / pseudocode and program for generating 'n' terms of the fibonacci series
-> calculate the complexity
-> write the recurrence relation
NAME = SANYA AGARWAL
ROLL NO.= R2142230839 
SAP_ID = 500120145
DATE = 23-08-24
*/

#include <stdio.h>

void printFibonacci(int n) {
    int first = 0, second = 1, third, i;

    if (n <= 0) {
        printf("Number of terms should be positive.\n");
        return;
    }

    printf("Fibonacci Series: ");

    for (i = 0; i < n; i++) {
        if (i <= 1)
            third = i; 
        else {
            third  = first + second; 
            first = second; 
            second = third;
        }
        printf("%d ", third);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);

    printFibonacci(n);

    return 0;
}

