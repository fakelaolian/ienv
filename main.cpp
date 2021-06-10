/*! ************************************************************************
 *
 * Copyright (C) 2020 dahan All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/6/9. <=== */

/*!
 * @author 2B键盘
 */
#include "commands.h"

#include <sstream>
#include <vector>

/**
 * 最新版本
 */
#define HIGHEST "highest"

typedef void (*__function__)(__argc__, __argv__);

using namespace std;

static map<string, __function__> commands;

/**
 * 初始化命令函数
 */
void init_commands_function();

/**
 * @return 字符串前缀
 */
bool start_with(string src, string val);

/**
 * 解析命令
 *
 * @param item    命令字符串
 * @param command 解析后的命令字符串，例如：--pack=java, 那么这个值就是 --pack
 * @return 如果是带有参数的命令，那么就解析参数并 return 掉参数。
 */
void parse_command(string item, string& command, __argc__& argc, __argv__& argv);

/**
 * 字符串分割
 */
void split(const string& value, char flag, __argc__& argc, __argv__& argv);

int main(int argc, char **argv)
{
    if (argc <= 1)
        return 0;

    // 初始化命令
    init_commands_function();

    string item;
    for (size_t i = 1; i < argc; i++)
    {
        item = argv[i];

        string command;
        __argc__ _argc;
        __argv__ _argv;

        parse_command(item, command, _argc, _argv);

        if(commands[command] != NULL)
        {
            commands[command](_argc, _argv);
        }
    }

    return 0;
}

void init_commands_function()
{
    commands.insert(pair<string, __function__>(VERSION, version));
    commands.insert(pair<string, __function__>(DEFAULT_EXEC, default_exec));
    commands.insert(pair<string, __function__>(PACKAGE, package_for_version));
}

bool start_with(string src, string val)
{
    return !src.compare(0, val.size(), val);
}

void parse_command(string item, string& command, __argc__& argc, __argv__& argv)
{
    if (start_with(item, "-"))
    {
        if (start_with(item, "--"))
        {
            if (strstr(item.c_str(), "="))
            {
                int find_index = item.find('=');
                command = item.substr(0, find_index);

                string value;
                value = item.substr(find_index + 1, item.size());

                split(value, ';', argc, argv);
                return;
            } else
            {
                command = item;
                argc = 0;
                argv = __empty__;
            }
        }
    } else
    {
        command = DEFAULT_EXEC;
        split(item, ';', argc, argv);
    }
}

void split(const string& value, char flag, __argc__& argc, __argv__& argv)
{
    string temp;
    vector<string> vec;
    istringstream iss(value);

    while(getline(iss, temp, flag))
    {
        vec.push_back(temp);
    }

    argc = vec.size();
    argv = vec.data();
}