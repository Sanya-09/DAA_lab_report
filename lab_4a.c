/*Write an algorithm / pseudocode and program to matrix
multiplication using strassen's method. Compare the performance
of this method with the regular method for matrix multiplication
NAME = SANYA AGARWAL
ROLL NO.= R2142230839
SAP_ID = 500120145
DATE = 16-09-24*/
#include<stdio.h>
#define MAX 100
int main(){
int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], i, j;
int m1, m2, m3, m4 , m5, m6, m7;
int n;
printf("Enter the elements of matrix: ");
scanf("%d"
,&n);
printf("Enter the %d elements of first matrix: " , n);
for(i = 0;i < n/2; i++)
for(j = 0;j < n/2; j++)
scanf("%d"
, &a[i][j]);
printf("Enter the %d elements of second matrix: " ,n);
for(i = 0; i < n/2; i++)
for(j = 0;j < n/2; j++)
scanf("%d"
, &b[i][j]);
printf("\nThe first matrix is\n");
for(i = 0; i < n/2; i++){
printf("\n");
for(j = 0; j < n/2; j++)
printf("%d\t"
, a[i][j]);
}
printf("\nThe second matrix is\n");
for(i = 0;i <n/2; i++){
printf("\n");
for(j = 0;j < n/2; j++)
printf("%d\t"
, b[i][j]);
}
/*M1 = (A11 + A22) × (B11 + B22)
M2 = (A21 + A22) × B11
M3 = A11 × (B12 - B22)
M4 = A22 × (B21 - B11)
M5 = (A11 + A12) × B22
M6 = (A21 - A11) × (B11 + B12)
M7 = (A12 - A22) × (B21 + B22)*/
// MATRICES ARE SPLIT INTO 7 SUB-MATRICES
m1= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
m2= (a[1][0] + a[1][1]) * b[0][0];
m3= a[0][0] * (b[0][1] - b[1][1]);
m4= a[1][1] * (b[1][0] - b[0][0]);
m5= (a[0][0] + a[0][1]) * b[1][1];
m6= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
m7= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
c[0][0] = m1 + m4- m5 + m7;
c[0][1] = m3 + m5;
c[1][0] = m2 + m4;
c[1][1] = m1 - m2 + m3 + m6;
printf("\nAfter multiplication using Strassen's algorithm
\n");
for(i = 0; i < n/2 ; i++){
printf("\n");
for(j = 0;j < n/2; j++)
printf("%d\t"
, c[i][j]);
}
return 0;
}
