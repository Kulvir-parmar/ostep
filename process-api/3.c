#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) {
        printf("Hello \n");
    } else {
        sleep(1); // If parent process proceeds to execute first, sleep this
                  // process so that child process can print "hello" first,
                  // since we cannot use wait().
        // wait(NULL);
        printf("good bye\n");
    }
    return 0;
}
