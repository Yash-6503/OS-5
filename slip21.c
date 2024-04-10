//Q1
//header file stack.h
#include<stdio.h>
char s[20];
int top;
void init()
{
top==-1;
}
int isempty()
{
if(top==-1)
return 1;
else
return 0;
}
int isfull()
{
if(top==19)
return 1;
else
return 0;
}
void push(char ch)
{
if(isfull()==1)
printf("Stack is full");
else
{
top++;
s[top]=ch;
}
}
char pop()
{
char ch;
if(isempty()==1)
printf("Stack is empty");
else
{
ch=s[top];
top--;
return ch;
}
}

//programfile
#include<stdio.h>
#include"stack.h"
int main()
{
init();
char str[20];
int i;
printf("Enter String: ");
scanf("%s",&str);
for(i=0;str[i]!='\0';i++)
{
push(str[i]);
}
printf("Reversed string: ");
while(!isempty())
{
printf("%c",pop());
}
}

//Q2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
char name[20];
int age;
}emp[10];
int readfile(struct employee a[])
{
int i=0;
FILE*fp;
if((fp=fopen("emp.txt","r"))!=NULL)
{
while(!feof(fp))
{
fscanf(fp,"%s%d",&a[i].name,&a[i].age);
i++;
}
}
return i-1;
}
void InsertionSort(struct employee a[],int n)
{ int i,j;
struct employee key;
for(i=1; i<n; i++)
{
key=a[i];
for(j=i-1; j>=0; j--)
{
if(strcmp(a[j].name,key.name)>0)
{
a[j+1]=a[j];
}
else
break;
}
a[j+1]=key;
}
}
void writefile(struct employee a[],int n)
{
int i=0;
FILE*fp;
if((fp=fopen("insertionsort.txt","w"))!=NULL)
{
for(i=0;i<n;i++)
{
fprintf(fp,"%s %d\n",a[i].name,a[i].age);
}
}
}
int main()
{
int n;
n=readfile(emp);
if(n==-1)
printf("File Not Found");
else
{
InsertionSort(emp,n);
writefile(emp,n);
printf("File Sorted");
}
}

