/*Write an algorithm/pseudocode for matrix multiplication. Calculate the time and space complexity
NAME = SANYA AGARWAL
ROLL NO.= R2142230839 
SAP_ID = 500120145
DATE= 13-08-24
*/

#include <stdio.h>

void matrixMultiply(int A[][10], int B[][10], int C[][10], int rowA, int colA, int colB) {
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int rowA, colA, rowB, colB;

    printf("Enter number of rows in matrix A: ");
    scanf("%d", &rowA);
    printf("Enter number of columns in matrix A: ");
    scanf("%d", &colA);

    printf("Enter number of rows in matrix B: ");
    scanf("%d", &rowB);
    printf("Enter number of columns in matrix B: ");
    scanf("%d", &colB);

    if (colA != rowB) {
        printf("Error: Number of columns in A must be equal to number of rows in B\n");
        return 1;
    }

    int A[10][10];
    int B[10][10];
    int C[10][10];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    matrixMultiply(A, B, C, rowA, colA, colB);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}