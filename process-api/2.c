#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/*
I have no idea about this.
I wrote a program to write to the same file in both child and parent process.
Writes of both of them were successful.
 */

int main(int argc, char **argv) {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(-1);
    }

    pid_t rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) {
        for (int i = 0; i < 10; i++) {
            char buffer[50];
            sprintf(buffer, "Child writing line %d\n", i);
            write(fd, buffer, strlen(buffer));
        }
        printf("(pid: %d)\n", (int)getpid());
    } else {
        for (int i = 0; i < 10; i++) {
            char buffer[50];
            sprintf(buffer, "Parent writing line %d\n", i);
            write(fd, buffer, strlen(buffer));
        }
        printf("(pid: %d)\n", (int)getpid());
    }
    close(fd);
    return 0;
}
