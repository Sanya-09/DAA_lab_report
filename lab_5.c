/*Given 10 activities along with their start and finish time as
Si = {1, 2, 3, 4, 7, 8, 9, 9, 11, 12}
fi = {3, 5, 4, 7, 10, 9, 11, 13, 12, 14}
Compute a schedule where the greatest no. of activities takes place. (greedy algorithm)
Name-Sanya Agarwal
Roll no. - R2142230839
Sap id. - 500120145
Date - 20-09-24
*/

#include<stdio.h>
 
void activity_selection(int start[], int finish[],int n)
{
    int i,j;
    printf("Selected Activities:\n");
    i=0;
    printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);
    for(j=1; j<n; j++)
    {
        if (start[j]>=finish[i])
        {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, start[j], finish[j]);
            i=j;
        } 
    }
}
 
int main()
{
    int start[] = {1, 2, 3, 4, 7, 8, 9, 9, 11, 12};
    int finish[] = {3, 5, 4, 7, 10, 9, 11, 13, 12, 14};
    int n = 10;
    activity_selection(start, finish, n);
    return 0;
}