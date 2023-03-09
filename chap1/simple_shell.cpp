#include "../include/lib.hpp"

#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
    string command;
    pid_t pid;
    int status;

    cout << "%% ";
    while (getline(std::cin, command)) {
        if ((pid = fork()) < 0) {
            err_sys({"fork error"});
        } else if (pid == 0) {
            execlp(command.c_str(), command.c_str(), nullptr);
            err_ret({"couldn't execute:", command});
            exit(127);
        }

        if((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys({"waitpid error"});
        }
        cout << "%% ";
    }
    exit(0);
}