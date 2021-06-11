//
// Created by Mi on 2021/6/10.
//

#ifndef IENV_STRUTILS_H
#define IENV_STRUTILS_H

#include <cstring>
#include <vector>

typedef int          __argc__;
typedef std::string* __argv__;

bool start_with(std::string src, std::string val)
{
    return !src.compare(0, val.size(), val);
}

void split(const std::string& value, char flag, __argc__& argc, __argv__& argv)
{
    std::string temp;
    std::vector<std::string> vec;
    std::stringstream iss(value);

    while(getline(iss, temp, flag))
    {
        vec.push_back(temp);
    }

    argc = vec.size();
    argv = vec.data();
}

#endif //IENV_STRUTILS_H
