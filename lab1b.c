/*Write an algorithm to print the sum of the digits of a given number.
NAME = SANYA AGARWAL
ROLL NO.= R2142230839 
SAP_ID = 500120145
DATE= 06-08-24
*/

#include<stdio.h>
int main(){
    int x;
    printf("Enter a number: ");
    scanf("%d" , &x);
    int num = 0 , sum = 0;
    while (x>0)
    {
        sum += x%10;
        x=x/10;
    }
    printf("Sum of digits of given number is %d." , sum);
    return 0;
}