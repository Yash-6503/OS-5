//Q1

#include<stdio.h>
void countingsort(int a[20],int n,int k)
{
int count[50],b[30],i;
for(i=0;i<=k;i++)
{
count[i]=0;
}
}
main()
{
int a[20],n,i,max;
printf("Enter how many elements ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
a[i]=rand()%10;
}
printf("\n Before sort array is ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
max=a[0];
for(i=1;i<n;i++)
{
if(a[i]>max)
max=a[i];
}
countingsort(a,n,max);
printf("\n Afer sorting array is ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}

//Q2


#include<stdio.h>
#include<string.h>
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
}
}
char pop()
{
char data;
if(isempty()==1)
printf("\nStack is empty ");
else
{
}
}
void postfix_eval(char str[20])
{
int i,op1,op2,val;
for(i=0;str[i]!='\0';i++)
{
switch(str[i])
{
case '+':op2=pop();
op1=pop();
push(op1+op2);
break;
case '-':op2=pop();
op1=pop();
push(op1-op2);
break;
case '*':op2=pop();
op1=pop();
push(op1*op2);
break;
case '/':op2=pop();
op1=pop();
push(op1/op2);
break;
default:printf("Enter value of %c ",str[i]);
scanf("%d",&val);
push(val);
}
}
printf("Ans =%d ",pop());
}
main()
{
char str[20];
printf("Enter postfix string ");
scanf("%s",str);
postfix_eval(str);
}