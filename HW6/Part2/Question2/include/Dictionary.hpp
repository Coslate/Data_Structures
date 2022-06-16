//Dictionary.hpp
#include <Dictionary.h>

std::string GenRandomString(const int len) {
    static const char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

