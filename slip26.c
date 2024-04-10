Q1
Header File : sstack.h
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
Program File :
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

Q2
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct OrderedList {
    struct Node* head;
    int ascending;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insert(struct OrderedList* orderedList, int data) {
    struct Node* new_node = createNode(data);

    if (!orderedList->head) {
        orderedList->head = new_node;
    } else {
        struct Node* current = orderedList->head;
        struct Node* prev = NULL;

        while (current && ((data < current->data) == orderedList->ascending)) {
            prev = current;
            current = current->next;
        }

        if (prev) {
            prev->next = new_node;
        } else {
            new_node->next = orderedList->head;
            orderedList->head = new_node;
        }
    }
}

int search(struct OrderedList* orderedList, int data) {
    struct Node* current = orderedList->head;

    while (current && (data != current->data)) {
        current = current->next;
    }

    return (current != NULL);
}
void display(struct OrderedList* orderedList) {
    struct Node* current = orderedList->head;

    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct OrderedList* orderedList) {
    struct Node* current = orderedList->head;
    struct Node* next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    orderedList->head = NULL;
}

int main() {
    struct OrderedList orderedList;
    orderedList.head = NULL;
    orderedList.ascending = 1; 
    insert(&orderedList, 5);
    insert(&orderedList, 3);
    insert(&orderedList, 8);
    insert(&orderedList, 1);

    printf("Original ordered list:\n");
    display(&orderedList);


    int elementToSearch = 3;
    printf("Is %d in the list? %s\n", elementToSearch, search(&orderedList, elementToSearch) ? "Yes" : "No");


    freeList(&orderedList);

    return 0;
}