#pragma once

#include <unistd.h>
#include <cerrno>
#include <concepts>
#include <cstdio>
#include <cstdlib>
#include <error.h>
#include <cstdarg>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string_view>
#include <string>
#include <vector>
#include <array>

using Strings = std::vector<std::string_view>;

std::stringstream vec_to_ss(const Strings& msg) {
    std::stringstream ss;
    for(const auto& s: msg) {
        ss << s << ' ';
    }
    return ss;
}

void err_doit(bool errno_flag, int error, const Strings& msg) {
    auto ss = vec_to_ss(msg);
    if (errno_flag) {
        ss << ": " << strerror(error) << '\n';
    }
    std::cerr << ss.str();
    ss.clear();
}

void err_sys(const Strings& msg) {
    err_doit(true, errno, msg);
    exit(1);
}

void err_quit(const Strings& msg) {
    err_doit(false, 0, msg);
    exit(1);
}

void err_ret(const Strings& msg) {
    err_doit(true, errno, msg);
}