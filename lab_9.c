/*Implement the N Queen problem
Take user input of the grid size (number of cells)
Take user input of the number of queens
*/
#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int board[MAX][MAX];
// Function to print the chessboard
void printBoard(int n) {
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
printf("%d ", board[i][j]);
}
printf("\n");
}
printf("\n");
}
// Check if it's safe to place a queen at board[row][col]
bool isSafe(int n, int row, int col) {
// Check column
for (int i = 0; i < row; i++) {
if (board[i][col] == 1)
return false;
}
// Check left diagonal
for (int i = row, j = col; i >= 0 && j >= 0; i--
, j--) {
if (board[i][j] == 1)
return false;
}
// Check right diagonal
for (int i = row, j = col; i >= 0 && j < n; i--
, j++) {
if (board[i][j] == 1)
return false;
}
return true;
}
// Recursive backtracking function to solve the problem
bool solveNQueens(int n, int row, int queensToPlace) {
if (queensToPlace == 0) { // All queens placed
printBoard(n);
return true;
}
if (row >= n) // No more rows to place queens
return false;
bool success = false;
for (int col = 0; col < n; col++) {
if (isSafe(n, row, col)) {
// Place the queen
board[row][col] = 1;
// Recur for the next row with one less queen to place
success = solveNQueens(n, row + 1, queensToPlace - 1)
|| success;
// Backtrack by removing the queen
board[row][col] = 0;
}
}
return success;
}
int main() {
int n, k;
// Take input for grid size (n) and number of queens (k)
printf("Enter the grid size (N): ");
scanf("%d"
, &n);
printf("Enter the number of queens (K): ");
scanf("%d"
, &k);
if (k > n) {
printf("Number of queens cannot exceed grid size.\n");
return 0;
}
// Initialize the board to 0
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
board[i][j] = 0;
}
}
// Solve the problem and print solutions
if (!solveNQueens(n, 0, k)) {
printf("No solution exists.\n");
}
return 0;
}
