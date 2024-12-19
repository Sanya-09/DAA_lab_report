/*Write an algorithm to determine a student’s final grade and indicate whether it is passing or failing. If final grade is less than 40, student is considered as fail. The final grade is calculated as the average of four marks.
NAME = SANYA AGARWAL
ROLL NO.= R2142230839 
SAP_ID = 500120145
*/

#include<stdio.h>
int main(){
    int s1 , s2 , s3 , s4;
    printf("Enter the marks of 4 subjects");
    scanf("%d %d %d %d",&s1,&s2,&s3,&s4);
    // to calculate average s1+s2+s3+s4/4
    int grade;
    grade = s1 + s2 + s3 + s4 /4;
    if(grade<40){
        printf("FAIL");
    }
    else {
        printf("PASS");
    }
    return 0;
}
