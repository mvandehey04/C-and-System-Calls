#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    char name[25];
    FILE* file;
    int display;
    
    pid_t pid;
    pid = fork();
    
    if (pid == 0)
    {
        printf("Child process begins...\n");
        printf("Input a file name: ");
        
        scanf("%s", name);
        file = fopen(name, "r");
        while(1)
        {
            display = fgetc(file);
            if(feof(file))
                break;
            
            printf("%c", display);
        }
        
        printf("Child process ends...\n");
        
        fclose(file);
    }
    else
    {
        printf("Parent process begins...\n");
        printf("child id: %d \n", pid);
        printf("parent id: %d \n", getpid());
        wait(NULL);
        
        printf("Parent process ends...\n");
    }
    
    return 0;
}
