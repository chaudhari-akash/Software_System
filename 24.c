/*
============================================================================
Name : 24.c
Author : Akash Chaudhari
Description : Write a program to create an orphan process.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{

    int pid = fork();

    if (pid > 0)
    {
        printf("Currently in Parent Process.\n");
        printf("Child PID : %d\n", pid);
        printf("Parent PID : %d\n", getpid());
        exit(0);
    }
    else if (pid == 0)
    {
        printf("Currently in Child Process.\n");
        printf("Child PID : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        printf("Putting child to sleep for 100s!\n");
        sleep(100);
        printf("Exiting child!\n");
        printf("Child PID : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        exit(0);
    }

    return 0;
}

/*
============================================================================
~/Documents/Software System/Hands On List/Hands On List 1/24 ❯ ./24 &
[1] 15270
Currently in Parent Process.
Child PID : 15271
Parent PID : 15270
Currently in Child Process.
Child PID : 15271
[1]  + 15270 done       ./24
Parent PID : 2226
Putting child to sleep for 100s!
============================================================================
*/