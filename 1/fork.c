#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    /* fork another process */
    pid = fork();
    if(pid < 0)
    {
        /* erroe ocurred */
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if(pid == 0) /* Child process */
    {
        printf("I'm a child\n");
    }
    else /* parent process */
    {
        /* Parent will wait for the child to complete */
        //wait(NULL);
        printf("I'm a parent\n");
        exit(0);
    }
    return 0;
}
