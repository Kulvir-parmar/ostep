#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("(pid: %d) hello world\n", (int)getpid());

    pid_t rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork command failed");
    } else if (rc == 0) {
        printf("(pid: %d) child process\n", (int)getpid());
        sleep(1);
    } else {
        pid_t wc = waitpid(rc, NULL, 0);
        printf("(pid: %d) parent process waiting for %d\n", (int)getpid(), wc);
    }

    return 0;
}
