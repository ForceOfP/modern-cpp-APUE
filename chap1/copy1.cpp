#include "../include/lib.hpp"


int main() {
    int n {0};
    std::array<char, 4096> buff;

    while((n = read(STDIN_FILENO, buff.data(), 4096)) > 0) {
        if (write(STDOUT_FILENO, buff.data(), n) > n) {
            err_sys({"write error"});
        }
    }

    if (n < 0) {
        err_sys({"read error"});
    }

    exit(0);
}