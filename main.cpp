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
#include <iostream>
#include <string>
#include <map>

typedef char* __param;
typedef void (*__command)(__param);

/*!
 * 安装所有当前文件夹下的包
 */
#define ALL "-a"
typedef void (*install_all_p)(__param);
install_all_p all = NULL;

/*!
 * 安装指定环境
 * <code>
 *     // 单个安装包
 *     installer --pack=java --v=1.8
 *
 *     // 多个安装包
 *     installer --pack=java;python; --v=1.8;3.1
 * </code>
 */
#define PACKAGE "--pack"
typedef void (*install_package_p)(__param);
install_package_p package = NULL;

/*!
 * 安装指定版本（需要配合 --pack 使用）
 */
#define FOR_VERSION "--fv"
typedef void (*install_package_for_version_p)(__param);
install_package_for_version_p package_for_version = NULL;

/*!
 * 解析所有预编写好的文本，并全部安装
 */
#define PRE_TEXT "-pre"
typedef void (*install_pre_text_p)(__param);
install_pre_text_p pre_text = NULL;

/*!
 * 获取当前版本号
 */
#define VERSION "-v"
typedef void (*install_version_p)(__param);
install_version_p version = NULL;

using namespace std;

/**
 * 环境安装包
 */
struct env
{
    string file;
    string version;
};

map<const char*, __command> functions;

/**
 * 初始化命令函数
 */
void init_commands_function();

int main(int argc, char** argv)
{
    if(argc <= 1)
        return 0;

    // 初始化命令
    init_commands_function();

    return 0;
}

void init_commands_function()
{
    version = [](__param){ printf("current version: 1.0\n"); };
    functions.insert(pair<const char*, __command>("v", version));
}