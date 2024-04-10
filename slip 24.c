Q.1 
#include<stdio.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<stdlib.h> 
void bubblesort(int arr[30],int n) 
{ 
 int i,j,temp; 
 for(i=0;i<n;i++) 
 { 
 for(j=0;j<n-1;j++) 
 { 
 if(arr[j]>arr[j+1]) 
 { 
 temp=arr[j]; 
 arr[j]=arr[j+1]; 
 arr[j+1]=temp; 
 } 
 } 
 } 
} 
void insertionsort(int arr[30], int n) 
{ 
 int i, j, temp; 
 for (i = 1; i < n; i++) { 
 temp = arr[i]; 
 j = i - 1; 
 
 while(j>=0 && arr[j] > temp) 

 { 
 arr[j+1] = arr[j]; 
 j --; 
 } 
 arr[j+1] = temp; 
 } 
} 
void fork1() 
{ 
 int arr[25],arr1[25],n,i,status; 
 printf("\nEnter the no of values in array :"); 
 scanf("%d",&n); 
 printf("\nEnter the array elements :"); 
 for(i=0;i<n;i++) 
 scanf("%d",&arr[i]); 
 int pid=fork(); 
 if(pid==0) 
 { 
 sleep(10); 
 printf("Child process PID = %d\n",getpid()); 
 printf("\nElements Sorted Using insertionsort:"); 
 insertionsort(arr,n); 
 printf("\n"); 
 for(i=0;i<n;i++) 
 printf("%d,",arr[i]); 
 printf("\b"); 
 printf("\nparent process id=%d\n",getppid()); 
 system("ps -x"); 
 } 
 else 
 { 
 printf("\nParent process PID = %d\n",getppid()); 
 printf("Elements Sorted Using bubblesort:"); 
 bubblesort(arr,n); 
 printf("\n"); 
 for(i=0;i<n;i++) 
 printf("%d,",arr[i]); 
 printf("\n\n\n"); 
 } 
 } 
 int main() 
 { 
 fork1(); 
 return 0; 
 } 

Q.2 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
void make_toks(char *s, char *tok[]) 
{ 
int i=0; 
char *p; 
p = strtok(s," "); 
while(p!=NULL) 
{ 
 tok[i++]=p; 
 p=strtok(NULL," "); 
} 
tok[i]=NULL; 
} 
void count(char *fn, char op) 
{ 
FILE *fh; 
int cc=0,wc=0,lc=0; 
char c; 
fh = fopen(fn, "r"); 

if (fh == NULL) 
{ 
 printf("File %s not found.\n", fn); 
 return; 
} 
while ((c = fgetc(fh)) != EOF) 
{ 
 if (c == ' ') 
 wc++; 
 else if (c == '\n') 
 { 
 wc++; 
 lc++; 
 } 
 cc++;
} 
fclose(fh); 
switch (op) 
{ 
case 'c': 
 printf("No.of characters:%d\n", cc - 1); 
 break; 
case 'w': 
 printf("No.of words:%d\n", wc); 
 break; 
case 'l': 
 printf("No.of lines:%d\n", lc + 1); 
 break; 
} 
} 
int main() 
{ 
char buff[80],*args[10]; 
int pid; 
while(1) 
{ 
 printf("myshell$ "); 
 fflush(stdin); 
 fgets(buff,80,stdin); 
 buff[strlen(buff)-1]='\0'; 
 make_toks(buff,args); 
if(strcmp(args[0],"count")==0) 
 count(args[2],args[1][0]); 
else 
 { 

 pid = fork(); 
 if(pid>0) 
 wait(); 
 else 
 { 
 if(execvp(args[0],args)==-1)
 printf("Bad command.\n"); 
 } 
 } 
} 
return 0; 
} 
