#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/*
    wait: return the PID of the child process that was spawned from parent.
    if we run wait() for child process it will return -1
*/
int main(int argc, char **argv) {
    printf("hello from PID %d\n", (int)getpid());

    int rc = fork();
    int more = fork();
    if (rc < 0) {
    } else if (rc == 0) {
        printf("child process %d & fork return %d, %d\n", (int)getpid(), rc,
               more);
    } else {
        int wc = wait(NULL);
        printf("(PID: %d) parent of %d or %d\n---waiting for %d\n",
               (int)getpid(), rc, more, wc);
    }
    return 0;
}
