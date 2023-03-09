#include "../include/lib.hpp"
#include <cstdio>

int main() {
    printf("hello world from process ID %ld", (long)getpid());
    return 0;
}