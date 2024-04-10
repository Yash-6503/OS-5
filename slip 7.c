Q.1  
 #include<stdio.h> 
int main() 
{ 
 int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, 
flag3, i, j, k, pos, max, faults = 0; 
 printf("Enter number of frames: "); 
 scanf("%d", &no_of_frames); 
 
 printf("Enter number of pages: "); 
 scanf("%d", &no_of_pages); 
 
 printf("Enter page reference string: "); 
 
 for(i = 0; i < no_of_pages; ++i){ 
 scanf("%d", &pages[i]); 
 } 
 
 for(i = 0; i < no_of_frames; ++i){ 
 frames[i] = -1;
 } 
 
 for(i = 0; i < no_of_pages; ++i){ 
 flag1 = flag2 = 0; 
 
 for(j = 0; j < no_of_frames; ++j){ 
 if(frames[j] == pages[i]){ 
 flag1 = flag2 = 1; 
 break; 
 } 
 } 
 
 if(flag1 == 0){ 

 for(j = 0; j < no_of_frames; ++j){ 
 if(frames[j] == -1){ 
 faults++; 
 frames[j] = pages[i]; 
 flag2 = 1; 
 break; 
 } 
 } 
 } 
 
 if(flag2 == 0){ 
 flag3 =0; 
 
 for(j = 0; j < no_of_frames; ++j){ 
 temp[j] = -1;
 
 for(k = i + 1; k < no_of_pages; ++k){ 
 if(frames[j] == pages[k]){ 
 temp[j] = k; 
 break; 
 } 
 } 
 } 
 
 for(j = 0; j < no_of_frames; ++j){ 
 if(temp[j] == -1){ 
 pos = j; 
 flag3 = 1; 
 break; 
 } 
 } 
 
 if(flag3 ==0){ 
 max = temp[0]; 
 pos = 0; 
 
 for(j = 1; j < no_of_frames; ++j){ 
 if(temp[j] > max){ 
 max = temp[j]; 
 pos = j; 

 } 
 } 
 } 
frames[pos] = pages[i]; 
faults++; 
 } 
 
 printf("\n"); 
 
 for(j = 0; j < no_of_frames; ++j){ 
 printf("%d\t", frames[j]); 
 } 
 } 
 
 printf("\n\nTotal Page Faults = %d", faults); 
 
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
 if (op == 'f') 
 { 
 // Search for the first occurrence of the pattern 
 while (fgets(line, 80, fh) != NULL) 
 { 
 if (strstr(line, pattern) != NULL) 
 { 
 // Print the line and exit the loop 
 printf("%s", line); 
 break; 
 } 
 } 
 } 
 else 
 { 
 // Continue with the existing search implementation 
 while (fgets(line, 80, fh) != NULL) 
 { 
 if (strstr(line, pattern) != NULL) 
 { 
 count++; 
 if (op == 'a') 
 printf("%s", line); 

 } 
 } 
 if (op == 'c') 
 printf("Number of occurrences: %d\n", count); 
 } 
 fclose(fh); 
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
 
