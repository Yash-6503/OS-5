//Q1

#include<stdio.h>
main()
{
int i,a[10],n,min,pos,j,temp;
printf("Enter how many elements ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
a[i]=rand()%100;
}
printf("\nBefore array sorting ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
for(j=0;j<n-1;j++)
{
min=a[j];
pos=j;
for(i=j+1;i<n;i++)
{
if(a[i]<=min)
{
min=a[i];
pos=i;
}
}
temp=a[j];
a[j]=min;
a[pos]=temp;
}
printf("\nSorted array is ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}

//Q2
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insert(struct Node** head, int data, int ascending) {
    struct Node* newNode=createNode(data);
    struct Node* current = *head;


    if (*head == NULL) {
        *head = newNode;
        return;
    }

   
    while (current != NULL) {
        if ((ascending && data < current->data) || (!ascending && data > current->data)) {
            break;
        }
        current = current->next;
    }

  
    if (current == NULL) {
      
        newNode->prev = current->prev;
        current->prev->next = newNode;
        newNode->next = current;
        current->prev = newNode;
    } else if (current->prev == NULL) {
       
        newNode->next = current;
        current->prev = newNode;
        *head = newNode;
    } else {
       
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}


struct Node* search(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return head; 
        } else if (key < head->data) {
            return NULL; 
        }
        head = head->next;
    }
    return NULL; 
}


void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* myList = NULL;


    insert(&myList, 5, 1);
    insert(&myList, 3, 1);
    insert(&myList, 8, 1);
    insert(&myList, 1, 1);

    printf("Ascending Order: ");
    display(myList);

   
    int searchKey = 3;
    struct Node* result = search(myList, searchKey);
    if (result != NULL) {
        printf("%d found in the list.\n", searchKey);
    } else {
        printf("%d not found in the list.\n", searchKey);
    }


    insert(&myList, 7, 0);
    insert(&myList, 2, 0);

    printf("Descending Order: ");
    display(myList);


    while (myList != NULL) {
        struct Node* temp = myList;
        myList = myList->next;
        free(temp);
    }

    return 0;
}

