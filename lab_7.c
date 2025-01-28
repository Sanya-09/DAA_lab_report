/*Q. Implement the algorithm for solving 0/1 knapsack problem
using dynamic programming approach.
->User input of weight, profit and knapsack size.
->Write separate methods for profit calculation and item
selection.
->Output :
Table with weight, profit and selection.
Print the maximum profit that can be obtained by taking
knapsack size as user input.
*/
#include <stdio.h>
#include <stdlib.h>
// Structure to represent an item
typedef struct {
int weight;
int profit;
} Item;
// Function to calculate the maximum profit
int calculateProfit(Item items[], int n, int knapsackSize, int
dp[n+1][knapsackSize + 1]) {
for (int i = 1; i <= n; i++) {
for (int w = 1; w <= knapsackSize; w++) {
if (items[i - 1].weight <= w) {
dp[i][w] = (items[i - 1].profit + dp[i - 1][w -
items[i - 1].weight] > dp[i - 1][w]) ?
items[i - 1].profit + dp[i - 1][w -
items[i - 1].weight] : dp[i - 1][w];
} else {
dp[i][w] = dp[i - 1][w];
}
}
}
return dp[n][knapsackSize];
}
// Function to select items
void selectItems(Item items[], int n, int knapsackSize, int dp[]
[knapsackSize + 1], int selected[]) {
int w = knapsackSize;
for (int i = n; i > 0; i--) {
if (dp[i][w] != dp[i - 1][w]) {
selected[i - 1] = 1;
w -= items[i - 1].weight;
} else {
selected[i - 1] = 0;
}
}
}
int main() {
int n, knapsackSize;
printf("Enter the number of items: ");
scanf("%d"
, &n);
printf("Enter the weights and profits of each item (separated
by comma): ");
Item items[n];
for (int i = 0; i < n; i++) {
scanf("%d,%d"
, &items[i].weight, &items[i].profit);
}
printf("Enter the knapsack size: ");
scanf("%d"
, &knapsackSize);
int dp[n + 1][knapsackSize + 1]; // dp is dynamic
programming table ( PROFIT TABLE )
for (int i = 0; i <= n; i++) { // NUMBER OF ROWS
for (int j = 0; j <= knapsackSize; j++) { // NUMBER OF
COLUMN
dp[i][j] = 0;
}
}
int maxProfit = calculateProfit(items, n, knapsackSize, dp);
printf("Maximum profit: %d\n"
, maxProfit);
int selected[n];
selectItems(items, n, knapsackSize, dp, selected);
printf("Item selection:\n");
printf("Weight\tProfit\tSelected\n");
for (int i = 0; i < n; i++) {
printf("%d\t%d\t%d\n"
, items[i].weight, items[i].profit,
selected[i]);
}
return 0;
}
