//Q1
#include<stdio.h>
void linearsearch(int a[10],int n,int sr)
{
int i,p,cnt=0;
for(i=0;i<n;i++)
{
if(a[i]==sr)
{
p=i; //store position
cnt++;
break;
}
}
if(cnt>=1)
printf("element found at %d position",p);
else
printf("element NOT found ");
}
main()
{
int n,i,sr,a[10];
printf("enter how many values");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter values");
scanf("%d",&a[i]);
}
printf("\n enter search element");
scanf("%d",&sr);
linearsearch(a,n,sr);
}

Q2
#include "dstqueue.h"


int isFull(struct CircularQueue* Q) {
    return (Q->size == MAX_SIZE);
}

void addFront(struct CircularQueue* Q, int item) {
    if (isFull(Q)) {
        printf("Queue is full. AddFront operation failed.\n");
        return;
    }

    Q->front = (Q->front - 1 + MAX_SIZE) % MAX_SIZE;
    Q->array[Q->front] = item;
    Q->size++;
}


int getRear(struct CircularQueue* Q) {
    if (Q->size == 0) {
        printf("Queue is empty. GetRear operation failed.\n");
        return -1;  // indicating an error
    }

    return Q->array[Q->rear];
}


int deleteRear(struct CircularQueue* Q) {
    if (Q->size == 0) {
        printf("Queue is empty. DeleteRear operation failed.\n");
        return -1;  // indicating an error
    }

    int item = Q->array[Q->rear];
    Q->rear = (Q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    Q->size--;

    return item;
}
