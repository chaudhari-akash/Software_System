/*
============================================================================
Name : 30.c
Author : Akash Chaudhari
Description : Write a program to run a script at a specific time using a Daemon process.

Date: 31th Aug, 2024.
============================================================================
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{

    time_t current, deadline;
    time_t currentEpoch;
    struct tm *dl;

    time(&current);
    dl = localtime(&current);

    int hour = atoi(argv[1]);
    int minute = atoi(argv[2]);
    int second = atoi(argv[3]);

    dl->tm_hour = hour;
    dl->tm_min = minute;
    dl->tm_sec = second;

    deadline = mktime(dl);

    if (deadline == -1)
    {
        printf("mktime failed");
        exit(1);
    }

    if (fork() == 0)
    {

        if (setsid() == -1)
        {
            printf("setsid failed");
            exit(1);
        }
        if (chdir("/") == -1)
        {
            printf("chdir failed");
            exit(1);
        }

        umask(0);

        do
        {
            time(&currentEpoch);

            printf("Running the script of child pid %d\n", getpid());
        } while (difftime(deadline, currentEpoch) > 0);

        printf("Done running the script\n");
        exit(0);
    }

    exit(0);
}


/*
============================================================================
akash@akash-Inspiron-16-5630:/$ ps aux|grep 20887
akash      20887 84.3  0.0   2684   768 ?        Rs   12:35   1:14 ./30 12 37 0
akash      21034  0.0  0.0   9144  2176 pts/1    S+   12:36   0:00 grep --color=auto 20887
============================================================================
*/