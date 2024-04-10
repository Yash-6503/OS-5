//Q.1 
#include <stdio.h> 
#define MAX 20 
int frames[MAX], ref[MAX], mem[MAX][MAX], faults, sp, m, n, time[MAX]; 
void accept() 
{ 
 int i; 
 printf("Enter the number of frames: "); 
 scanf("%d", &n); 
 printf("Enter the number of references: "); 
 scanf("%d", &m); 
 printf("Enter the reference string:\n"); 
 for (i = 0; i < m; i++) 
 { 
 printf("[%d] = ", i); 
 scanf("%d", &ref[i]); 
 } 
} 
void disp() 
{ 
 int i, j; 
 for (i = 0; i < m; i++) 
 printf("%3d", ref[i]); 
 printf("\n\n"); 
 for (i = 0; i < n; i++) 
 { 
 for (j = 0; j < m; j++) 
 { 
 if (mem[i][j]) 
 printf("%3d", mem[i][j]); 
 else 
 printf(" "); 
 } 

 printf("\n"); 
 } 
 printf("Total Page Faults: %d\n", faults); 
} 
int search(int pno) 
{ 
 int i; 
 for (i = 0; i < n; i++) 
 { 
 if (frames[i] == pno) 
 return i; 
 } 
 return -1;
} 
void lfu() 
{ 
 int i, j, k, count[20]; 
 for (i = 0; i < m && sp < n; i++) 
 { 
 k = search(ref[i]); 
 if (k == -1)
 { 
 frames[sp] = ref[i]; 
 time[sp] = 1; 
 count[sp] = 1; 
 faults++; 
 sp++; 
 for (j = 0; j < n; j++) 
 mem[j][i] = frames[j]; 
 } 
 else 
 { 
 time[k] = i; 
 count[k]++; 
 } 
 } 
 for (; i < m; i++) 
 { 
 k = search(ref[i]); 
 if (k == -1)
 { 
 int min_i = 0, min = 9999; 
 for (j = 0; j < n; j++) 
 { 

 if (count[j] < min) 
 { 
 min = count[j]; 
 min_i = j; 
 } 
 } 
 sp = min_i; 
 frames[sp] = ref[i]; 
 time[sp] = i; 
 count[sp] = 1; 
 faults++; 
 for (j = 0; j < n; j++) 
 mem[j][i] = frames[j]; 
 } 
 else 
 { 
 time[k] = i; 
 count[k]++; 
 } 
 } 
} 
int main() 
{ 
 accept(); 
 lfu(); 
 disp(); 
 return 0; 
} 
Q.2. 
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
if (strcmp(args[0], "typeline") == 0) 
{ 
 // Check if the '+n' option is specified 
 if (args[1][0] == '+') 
 { 
 // Read the line count 
 int n = atoi(args[1] + 1); 
 // Open the file 
 FILE *fp = fopen(args[2], "r"); 
 if (fp == NULL) 
 { 
 printf("Error opening file %s.\n", args[2]); 
 return 1; 
 } 
 // Read and print the first n lines 
 char line[80]; 
 int count = 0; 
 while (count < n && fgets(line, 80, fp) != NULL) 
 { 
 printf("%s", line); 

 count++; 
 } 
 // Close the file 
 fclose(fp); 
 } 
 // If the '-a' option is specified 
 else if (strcmp(args[2], "-a") == 0) 
 { 
 // Open the file 
 FILE *fp = fopen(args[2], "r"); 
 if (fp == NULL) 
 { 
 printf("Error opening file %s.\n", args[2]); 
 return 1; 
 } 
 // Read and print the entire file 
 char line[80]; 
 while (fgets(line, 80, fp) != NULL) 
 printf("%s", line);  
 fclose(fp); 
 } 
 else 
 { 
 printf("Invalid option.\n"); 
 } 
} 
} 
} 
