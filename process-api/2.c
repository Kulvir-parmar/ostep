#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);

    if (fd == -1) {
        perror("Error opening file");
        exit(-1);
    }

    pid_t rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) {
        printf("fd in child: %d\n", fd);
    } else {
        printf("fd in parent: %d\n", fd);
        wait(NULL);
    }
    close(fd);
    return 0;
}
