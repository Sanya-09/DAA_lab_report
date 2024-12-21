/*Write an algorithm / pseudocode and program for binary search
-> calculate the complexity
-> write the recurrence relation
NAME = SANYA AGARWAL
ROLL NO.= R2142230839 
SAP_ID = 500120145
DATE = 23-08-24
*/

#include<stdio.h>

int binary(int a[], int start, int end, int x)
{
    int t=0;
    if(start<=end)
    {
        int mid=(start +end)/2; 
        if(a[mid]==x)  
           t=1;
        else if(a[mid]>x) 
          return binary(a,start,mid-1,x);
        else if(a[mid]<x)
          return binary(a,mid+1,end,x); 
    }
    return t;
}

int main()
{
    int n,x,result;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter %d elements (sorted):\n",n);
    for(int i =0; i<n; i++)
        scanf("%d",&array[i]);
    printf("Enter the element to be searched:\n");
    scanf("%d",&x);
    
    result = binary(array,0,n-1,x);
    if(result==1)
        printf("\nElement found");
    else
        printf("\nElement not found");
    return 0;
}