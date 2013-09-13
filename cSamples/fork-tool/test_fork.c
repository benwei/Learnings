/*
 * This is a demo code for process fork, written by ben6
 * License: BSD License
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int test_fork()
{
    int rc = 0;
    pid_t pid = getpid();
    int child_cost = 2;
    
    fprintf(stdout, "parent %ld\n", (unsigned long) getpid());
    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork failure\n");
    } else if (pid > 0) { 
        int status = 0;
        fprintf(stdout, "parent %ld waiting child(%ld) %d seconds\n", (unsigned long) getpid(), (unsigned long)pid, child_cost);
        waitpid(pid, &status, WUNTRACED);
        fprintf(stdout, "parent %ld caught child exit-code (%d)\n", (unsigned long) getpid(), WEXITSTATUS(status));
    } else if (pid == 0) {
        fprintf(stdout, "fork child %ld\n", (unsigned long) getpid());
        sleep(child_cost);
        fprintf(stdout, "child %ld exited\n", (unsigned long) getpid());
        rc = 101;
    }

    return rc;
}

int main(int argc, char **argv)
{
    int rc = 0;
    rc = test_fork();
    return rc;
}
