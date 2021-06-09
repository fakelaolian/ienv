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
#include <string>

/*!
 * 安装所有当前文件夹下的包
 */
#define ALL "-a"

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

/*!
 * 安装指定版本（需要配合 --pack 使用）
 */
#define FOR_VERSION "--fv"

/*!
 * 解析所有预编写好的文本，并全部安装
 */
#define PRE_TEXT "-pre"

/*!
 * 获取当前版本号
 */
#define VERSION         "-v"
#define VERSION_NUMBER  "1.0"

std::string __empty__[] = {};

typedef int          __argc__;
typedef std::string* __argv__;

/**
 * 根据版本号选择安装
 */
void package_for_version(__argc__, __argv__)
{

}

/**
 * 获取当前 ienv 版本号
 */
void version(__argc__, __argv__)
{
    printf("current version: %s\n", VERSION_NUMBER);
}