// Q.1
#include <stdio.h>
#define MAX 20
int frames[MAX], ref[MAX], mem[MAX][MAX], faults, sp, m, n;
void accept()
{
    int i;
    printf("Enter no.of frames:");
    scanf("%d", &n);
    printf("Enter no.of references:");
    scanf("%d", &m);
    printf("Enter reference string:\n");
    for (i = 0; i < m; i++)
    {
        printf("[%d]=", i);
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
void fifo()
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        if (search(ref[i]) == -1)
        {
            frames[sp] = ref[i];
            sp = (sp + 1) % n;
            faults++;
            for (j = 0; j < n; j++)
                mem[j][i] = frames[j];
        }
    }
}
int main()
{
    accept();
    fifo();
    disp();
    return 0;
}
Q .2

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
    void
    make_toks(char *s, char *tok[])
{
    int i = 0;
    char *p;
    p = strtok(s, " ");
    while (p != NULL)
    {
        tok[i++] = p;
        p = strtok(NULL, " ");
    }
    tok[i] = NULL;
}
void list(char *dirname, char op)
{
    DIR *dir;
    struct dirent *entry;
    int count = 0;
    // Open the directory
    dir = opendir(dirname);
    if (dir == NULL)
    {
        printf("Directory %s not found.\n", dirname);
        return;
    }
    // Iterate through the entries in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        switch (op)
        {
        case 'f':
            // Display the filename
            printf("%s\n", entry->d_name);
            break;
        case 'n':
            // Increment the count
            count++;
            break;
        }
    }
    // Close the directory
    closedir(dir);
    // If the 'n' option was specified, print the count
    if (op == 'n')
    {
        printf("Number of entries: %d\n", count);
    }
}
int main()
{
    char buff[80], *args[10];
    int pid;
    while (1)
    {
        printf("myshell$ ");
        fflush(stdin);
        fgets(buff, 80, stdin);
        buff[strlen(buff) - 1] = '\0';
        make_toks(buff, args);
        if (strcmp(args[0], "list") == 0)
        {
            list(args[2], args[1][0]);
        }
        else
        {
            pid = fork();
            if (pid > 0)
                wait();
            else
            {
                if (execvp(args[0], args) == -1)
                    printf("Bad command.\n");
            }
        }
    }
    return 0;
}
