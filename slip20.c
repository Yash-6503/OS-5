//Q1
//header file
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
//programfile

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
struct node *next,*prev;
};
struct node *f;
void create()
{
struct node *s;
int i,n;
printf("enter how many nodes");
scanf("%d",&n);
f=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&f->data);
s=f;
for(i=1;i<n;i++)
{
s->next=(struct node*)malloc(sizeof(struct node));
s=s->next;
printf("enter data");
scanf("%d",&s->data);
}
s->next=f;
}
void display()
{
struct node *s;
printf("\nCircular linked list is::");
s=f;
do
{
printf("%d->",s->data);
s=s->next;
}
while(s!=f);
}
void append()
{
struct node *nw,*s;
int n,i;
printf("\nenter how many new nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
nw=(struct node*)malloc(sizeof(struct node));
printf("\nenter new node of data");
scanf("%d",&nw->data);
s=f;
do
{
s=s->next;
}while(s->next!=f);
s->next=nw;
nw->next=f;
}
}
main()
{
create();
display();
append();
display();
}