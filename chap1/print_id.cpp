#include "../include/lib.hpp"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main() {
    printf("uid = %d, gid = %d", getuid(), getgid());
    exit(0);
}