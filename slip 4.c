Q.1 
#include<stdio.h> 
#define MAX 20 
int frames[MAX],ref[MAX],mem[MAX][MAX],faults, 
 sp,m,n,count[MAX]; 
void accept() 
{ 
 int i; 
 printf("Enter no.of frames:"); 
 scanf("%d", &n); 
 printf("Enter no.of references:"); 
 scanf("%d", &m); 
 printf("Enter reference string:\n"); 
 for(i=0;i<m;i++) 
 { 
 printf("[%d]=",i); 
 scanf("%d",&ref[i]); 
 } 
} 
void disp() 
{ 
 int i,j; 
 for(i=0;i<m;i++) 
 printf("%3d",ref[i]); 
 printf("\n\n"); 
 for(i=0;i<n;i++) 
 { 
 for(j=0;j<m;j++) 
 { 

 if(mem[i][j]) 
 printf("%3d",mem[i][j]); 
 else 
 printf(" "); 
 } 
 printf("\n"); 
 } 
 printf("Total Page Faults: %d\n",faults); 
} 
int search(int pno) 
{ 
 int i; 
 for(i=0;i<n;i++) 
 { 
 if(frames[i]==pno) 
 return i; 
 } 
 return -1;
} 
int get_mfu(int sp) 
{ 
 int i,max_i,max=-9999; 
 i=sp; 
do
 { 
 if(count[i]>max) 
 { 
 max = count[i]; 
 max_i = i; 
 } 
 i=(i+1)%n; 
 }while(i!=sp); 
 return max_i; 
} 
void mfu() 
{ 
 int i,j,k; 

 for(i=0;i<m && sp<n;i++) 
 { 
 k=search(ref[i]); 
 if(k==-1)
 { 
 frames[sp]=ref[i]; 
 count[sp]++; 
 faults++; 
 sp++; 
 for(j=0;j<n;j++) 
 mem[j][i]=frames[j]; 
 } 
 else 
 count[k]++; 
 
 } 
 sp=0; 
 for(;i<m;i++) 
 { 
 k = search(ref[i]); 
 if(k==-1)
 { 
 sp = get_mfu(sp); 
 frames[sp] = ref[i]; 
 count[sp]=1; 
 faults++; 
 sp = (sp+1)%n; 
 for(j=0;j<n;j++) 
 mem[j][i] = frames[j]; 
 } 
 else 
 count[k]++; 
 } 
} 
 
int main() 
{ 
 accept(); 
 mfu(); 
 disp(); 
 return 0; } 

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
void search(char *fn, char op, char *pattern) 
{ 
FILE *fh; 
int count = 0; 
char line[80]; 
fh = fopen(fn, "r"); 
if (fh == NULL) 
{ 
printf("File %s not found.\n", fn); 
return; 
} 
while (fgets(line, 80, fh) != NULL) 
{ 

if (strstr(line, pattern) != NULL) 
{ 
count++; 
if (op == 'a') 
printf("%s", line); 
} 
} 
fclose(fh); 
if (op == 'c') 
printf("Number of occurrences: %d\n", count); 
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
if (strcmp(args[0], "search") == 0) 
search(args[2], args[1][0], args[3]); 
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