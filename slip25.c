Q1
#include <stdio.h>
#include <stdlib.h>

#define MAX_AGE 100

// Function to perform Count Sort on age
void countSort(int ages[], int n) {
    int count[MAX_AGE + 1] = {0};

    // Count the occurrences of each age
    for (int i = 0; i < n; i++) {
        count[ages[i]]++;
    }

    // Update count to store the position of each age in the sorted order
    for (int i = 1; i <= MAX_AGE; i++) {
        count[i] += count[i - 1];
    }

    // Create a new array to store the sorted order
    int *sortedAges = (int *)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        sortedAges[count[ages[i]] - 1] = ages[i];
        count[ages[i]]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < n; i++) {
        ages[i] = sortedAges[i];
    }

    free(sortedAges);
}

int main() {
    FILE *inputFile, *outputFile;
    int maxEmployees = 1000; // Change this based on your requirement
    int ages[maxEmployees];
    int n = 0; // Number of employees

    // Open the input file for reading
    inputFile = fopen("employee.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read ages from the file
    while (fscanf(inputFile, "%d", &ages[n]) == 1) {
        n++;
    }

    fclose(inputFile);

    // Perform Count Sort on ages
    countSort(ages, n);

    // Open the output file for writing
    outputFile = fopen("sortedemponage.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the sorted ages to the output file
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d\n", ages[i]);
    }

    fclose(outputFile);

    printf("Sorting and writing to 'sortedemponage.txt' completed.\n");

    return 0;
}

//Q2
Header File : stack.h
#include<stdio.h>
char s[20];
int top;
void init()
{
top=-1;
}
int isempty()
{
if(top==-1)
return 1;
else return 0;
}
int isfull()
{
if(top==19)
return 1;
else
return 0;
}
void push(char data)
{
if(isfull()==1)
printf("\nStack is full ");
else
{
    top++;
s[top]=data;
}
}
char pop()
{
char data;
if(isempty()==1)
printf("\nStack is empty ");
else
{
    data=s[top];
top--;
return data;
}
}
int peek()
{
return s[top];
}Program File :
#include<stdio.h>
#include "stack.h"
int priority(char ch)
{
switch(ch)
{
case '(':return 0;
case '+':
case '-':return 1;
case '*':
case '/':return 2;
case '^':
case '$':return 3;
}
return 0;
}
void convert(char str[20])
{
int i,j=0;
char post[20],ch,ch1;
init();
for(i=0;str[i]!='\0';i++)
{
ch=str[i];
switch(ch)
{
case '(':push(ch);
break;
case '+':
case '-':
case '*':
case '/':
case '$':
case '^':
while(!isempty() && (priority(peek())>=priority(ch)))
{
    post[j]=pop();
    j++;
    }
push(ch);
break;
case ')':while((ch1=pop())!='(')
{
post[j]=ch1;
j++;
}
break;
default:post[j]=ch;
j++;
}
}
while(!isempty())
{
post[j]=pop();
j++;
}
post[j]='\0';
printf("\n Postfix string = %s ",post);
}
main()
{
char infix[20];
printf("\nEnter the infix expression ");
scanf("%s",infix);
convert(infix);
}
