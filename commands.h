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
#include <utility>
#include <cstdio>
#include <io.h>
#include <vector>

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

struct fileinfo_t;

/**
 * 遍历所有文件
 */
std::vector<fileinfo_t> each_files(const std::string& path);

/**
 * 环境安装包
 */
struct package
{
    std::string filename;
    std::string version;
};

struct fileinfo_t
{
    std::string filename;
    filesize    size;
    unsigned    attrib;
    std::string asb_path;
    fileinfo_t(std::string _filename_, filesize _size_, unsigned _attrib_)
        : filename(std::move(_filename_)), size(_size_), attrib(_attrib_)
    {
    }
};

/**
 * 安装包文件
 */
struct packfile_t
{
private:
    std::vector<fileinfo_t> subdir_list;

public:
    std::string filename;
    filesize    size;
    packfile_t(std::string name, filesize _size) : filename(std::move(name)), size(_size)
    {

    }

    /**
     * @return 当前文件夹下的所有子目录
     */
    std::vector<fileinfo_t> subdir()
    {
        return this->subdir_list;
    }

};

std::map<std::string, packfile_t> packages;

/**
 * 加载本地安装包并校验
 * 符合标准的文件夹需要具备以下条件：
 *      1. 是文件夹
 *      2. 存在 description 描述文件
 *
 * @param allfiles 文件列表
 */
void load_local_packages(const std::vector<fileinfo_t>& allfiles)
{
    std::vector<packfile_t> packfiles;
    for(auto& item : allfiles)
    {
        // 是文件夹
        if(item.attrib != _A_SUBDIR)
            continue;

        // 存在 description 描述文件

    }
}

std::vector<fileinfo_t> each_files(std::string& path)
{
    path.append("\\*");
    std::vector<fileinfo_t> subdir;
#ifdef WIN32
    long handle; // 句柄
    struct _finddata_t fileinfo {};

    // 第一次查找
    handle = _findfirst(path.c_str(), &fileinfo);
    if(handle == -1)
        goto end;

    do
    {
        std::string name;
        name = fileinfo.name;

        //
        // 忽略 . 和 .. 文件夹, 如果文件不是文件夹那么就忽略掉
        //
        if(name == "." || name =="..")
            continue;

        fileinfo_t file(fileinfo.name, fileinfo.size, fileinfo.attrib);
        subdir.push_back(file);
    } while (!_findnext(handle, &fileinfo));

    _findclose(handle);

#endif

end:
    return subdir;
}

/**
 * 默认执行
 */
void default_exec(__argc__ argc, __argv__ argv)
{

    std::string current_directory;

    char _path_[MAX_PATH];
    getcwd(_path_, MAX_PATH); // 获取当前程序所在目录

    current_directory = _path_;
    current_directory = current_directory.substr(0, current_directory.rfind('/'));

    std::vector<fileinfo_t> files = each_files(current_directory);

    // 加载本地安装包
    load_local_packages(files);

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