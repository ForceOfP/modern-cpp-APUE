#include <cstdlib>
#include <dirent.h>
#include "../include/lib.hpp"
#include <iostream>
#include <string_view>
#include <vector>
// #include <format>

using namespace std;

const string usage = "usage: ls directory_name";
const string cannot_open = "can't open";

int main(int argc, char** argv) {
    DIR* dp;
    struct dirent* dirp;
    vector<string_view> msg(argv+1, argv+argc);


    if (argc != 2) {
        err_quit({usage});
    }

    if ((dp = opendir(argv[1])) == nullptr) {
        err_sys({cannot_open, argv[1]});
    }
    while((dirp = readdir(dp)) != nullptr) {
        cout << dirp->d_name << '\n';
    }

    closedir(dp);
    exit(0);
}