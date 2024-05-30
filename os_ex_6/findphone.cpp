//
// Created by guy on 5/15/24.
//
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <name>" << std::endl;
        return 1;
    }

    int fd[2];
    if (pipe(fd) == -1) {
        std::cerr << "Failed to create pipe." << std::endl;
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "Failed to fork." << std::endl;
        return 1;
    }

    if (pid == 0) { // Child process
        // Redirect STDOUT to the write end of the pipe, then close the read end.
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        execlp("grep", "grep", argv[1], "phonebook.txt", NULL);
        std::cerr << "Failed to execute grep." << std::endl;
        exit(1);
    } else { // Parent process
        // Close the write end, redirect STDIN from the read end of the pipe.
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        // Wait for the child process to finish before executing cut.
        wait(NULL);
        execlp("cut", "cut", "-d,", "-f2", NULL);
        std::cerr << "Failed to execute cut." << std::endl;
        exit(1);
    }

    return 0;
}
