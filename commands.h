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
#pragma once

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <stdio.h>
#include <io.h>

#ifdef WIN32
#   include <windows.h>
#endif

/*!
 * 安装所有当前文件夹下的包
 */
#define ALL "-a"

/*!
 * 安装指定环境
 * <code>
 *     // 单个安装包
 *     ienv --pack=java=1.8;
 *
 *     // 多个安装包
 *     ienv --pack=java=11;python=3.1
 * </code>
 */
#define PACKAGE "--pack"

/*!
 * 获取当前版本号
 */
#define VERSION         "-v"
#define VERSION_NUMBER  "1.0"

/**
 * 默认执行
 */
#define DEFAULT_EXEC    "-default"

std::string __empty__[] = {};

typedef int          __argc__;
typedef std::string* __argv__;
typedef unsigned long filesize;

/**
 * 环境安装包
 */
struct package
{
    std::string filename;
    std::string version;
};

struct file
{
    std::string filename;
    filesize    size;
};

void load_local_package()
{
    std::string path;
#ifdef WIN32
    TCHAR _path[MAX_PATH + 1] = {0};
    GetModuleFileName(NULL, _path, MAX_PATH);
    path = _path;
#endif

    int index = 0;
#ifdef WIN32
    index = path.rfind('\\');
#endif

    std::string directory = path.substr(0, index);

#ifdef WIN32
    long handle; // 句柄
    struct _finddata_t fileinfo;

    // 第一次查找
    handle = _findfirst(directory.c_str(), &fileinfo);
    if(handle == -1)
        return;

    do
    {
        std::cout << fileinfo.name << std::endl;
    } while (!_findnext(handle, &fileinfo));

    _findclose(handle);

#endif

}

/**
 * 默认执行
 */
void default_exec(__argc__ argc, __argv__ argv)
{
    load_local_package();

    for(int i = 0; i < argc; i++)
    {
        if(strstr(argv[i].c_str(), "="))
        {

        } else
        {

        }
    }
}

/**
 * 根据版本号选择安装
 */
void package_for_version(__argc__ argc, __argv__ argv)
{
    default_exec(argc, argv);
}

/**
 * 获取当前 ienv 版本号
 */
void version(__argc__, __argv__)
{
    printf("current version: %s\n", VERSION_NUMBER);
}