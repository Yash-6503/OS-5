Q1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
char name[20];
int age;
}emp[10];
int readfile(struct employee a[10])
{
int i=0;
FILE*fp;
if((fp=fopen("empl.txt","r"))!=NULL)
{
while(!feof(fp))
{
fscanf(fp,"%s%d",a[i].name ,&a[i].age);
i++;
}
}
return i-1;
}
void writefile(struct employee a[],int n)
{
int i;
FILE *fp;
if((fp=fopen("bsort.txt","w"))!=NULL)
{
for(i=0;i<n;i++)
{
fprintf(fp,"%s %d \n",a[i].name ,a[i].age);
}
}
}
void bubblesort(struct employee a[],int n)
{
int i,j;
struct employee temp;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-1;j++)
{
if(strcmp(a[j].name,a[j+1].name)>0)
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
main()
{
int n;
n=readfile(emp);
if(n==-1)
printf("File is not found");
else
{
bubblesort(emp,n);
writefile(emp,n);
printf("File is found");
}
}


Q2

#include<stdio.h>
struct node
{
int data;
struct node *next;
};
struct node* create();
void display(struct node*);
struct node* create()
{
int n,i;
struct node *s,*f;
printf("Enter how many nodes ");
scanf("%d",&n);
f=
(struct node *)malloc(sizeof(struct node));
printf("Enter data ");
scanf("%d",&f->data);
s=f;
for(i=1;i<n;i++)
{
s->next=(struct node*)malloc(sizeof(struct node));
s=s->next;
printf("Enter data ");
scanf("%d",&s->data);
}
s->next=NULL;
return f;
}
void display(struct node *f)
{
struct node *s;
for(s=f;s!=NULL;s=s->next)
{
printf("| %d |-> ",s->data);
}
}
struct node* merge(struct node *f1,struct node *f2)
{
struct node *s;
for(s=f1;s->next!=NULL;s=s->next)
{
}
s->next=f2;
return f1;
}
main()
{
struct node *f1,*f2,*f3;
f1=create();
f2=create();
printf("1st linked list ");
display(f1);
printf("\n2nd linked list ");