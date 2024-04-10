Q1
//Header File : sstack.h
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
}
//Program File
#include<stdio.h>
#include<stdlib.h>
#include"sstack.h"
main()
{
int n,i=0,ch;
init();
do
{
printf("\n1.push \n2.pop \n3.chech stack is empty or not
\n4.chech stack is full or not \n5.Peek \n0.exit");
printf("\neneter your choice ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("enter elements");
scanf("%d",&n);
push(n);
break;
case 2:printf("\ndeleted elements :%d",pop());
break;
case 3:if(isempty()==1)
printf("stack is empty");
else
printf("stack is not empty");
break;
case 4:if(isfull()==1)
printf("stack is full");
else
printf("stack is not full");
break;
case 5:printf("\ntop of elements:%d",peek());
break;
case 0: break;
}
}while(ch!=0);
}

//Q2

#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *f;
void create()
{
int i,n;
struct node *s;
printf("\nEnter no of nodes ");
scanf("%d",&n);
f=(struct node *)malloc(sizeof(struct node));
printf("\n Enter node ");
scanf("%d",&f->data);
s=f;
for(i=1;i<n;i++)
{
s->next=(struct node *)malloc(sizeof(struct node));
s=s->next;
printf("\n Enter node ");
scanf("%d",&s->data);
}
s->next=NULL;
}
void display()
{ struct node *s;
for(s=f;s!=NULL;s=s->next)
{
printf("\t %d ->",s->data);
}
}
void sort()
{
struct node *p,*q;
int temp;
for(p=f;p!=NULL;p=p->next)
{
for(q=p->next;q!=NULL;q=q->next)
{
if(p->data > q->data)
{
temp = p->data;
p->data = q->data;
q->data = temp;
}
}
}
}
main()
{
create();
printf("\n Link list is : ");
display();
printf("\n After sorting Link list is = ");
sort();
display();