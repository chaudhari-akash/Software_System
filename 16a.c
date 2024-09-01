/*
============================================================================
Name : 16a.c
Author : Akash Chaudhari
Description : Write a program to perform mandatory locking.
                a. Implement write lock
                b. Implement read lock

Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argv, char *argc[])
{

    char *file;
    struct flock lock;
    int fd;

    file = argc[1];

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    fd = open(file, O_RDWR);

    printf("Before Entering the critical section.\n");

    fcntl(fd, F_SETLK, &lock);

    printf("File is now locked for writing.\n");
    printf("Press Enter to Unlock.\n");

    getchar();

    lock.l_type = F_UNLCK;

    printf("Unlocked....\n");

    fcntl(fd, F_SETLK, &lock);

    return 0;
}
