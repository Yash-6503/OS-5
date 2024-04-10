    .1 
#include<stdio.h> 
#define MAX 20 
int frames[MAX],ref[MAX],mem[MAX][MAX],faults, 
sp,m,n,time[MAX]; 
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
int get_lru() 
{ 
int i,min_i,min=9999; 
for(i=0;i<n;i++) 
{ 
if(time[i]<min) 
{ 
min = time[i]; 
min_i = i; 
} 
} 
return min_i; 
} 
void lru() 
{ 
int i,j,k; 
for(i=0;i<m && sp<n;i++) 
{ 
k=search(ref[i]); 
if(k==-1)
{ 
frames[sp]=ref[i]; 
time[sp]=i; 
faults++; 
sp++; 
for(j=0;j<n;j++) 
mem[j][i]=frames[j]; 
} 
else 
time[k]=i; 
} 
for(;i<m;i++) 
{ 

k = search(ref[i]); 
if(k==-1)
{ 
sp = get_lru(); 
frames[sp] = ref[i]; 
time[sp] = i; 
faults++; 
for(j=0;j<n;j++) 
mem[j][i] = frames[j]; 
} 
else 
time[k]=i; 
} 
} 
int main() 
{ 
accept(); 
lru(); 
disp(); 
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