#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/*
    When fork() command is run, exactly similar process with its own memory,
   variables and parameters is created. Now whatever changes happens, it happens
   in each process's memory and thier memory isn't shared.
*/
int main(int argc, char **argv) {
    int x = 100;
    printf("(pid: %D) value of x %d\n", (int)getpid(), x);

    int rc = fork();
    if (rc < 0) {
        printf("fork command failed.\n");
    } else if (rc == 0) {
        x++;
        printf("(pid: %d) value of x %d\n", (int)getpid(), x);
    } else {
        int wc = wait(NULL);
        x += 2;
        printf("(pid: %d) value of x %d\n", (int)getpid(), x);
    }
    return 0;
}
