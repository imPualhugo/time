//
// Created by hyz on 2021/1/9.
//

#ifndef TIME_INFO_H
#define TIME_INFO_H
#include <cstdio>

#define COLOR_NONE "\033[0m" //表示清除前面设置的格式
#define RED "\033[1;31;40m" //40表示背景色为黑色, 1 表示高亮
#define BLUE "\033[1;34;40m"
#define GREEN "\033[1;32;40m"
#define YELLOW "\033[1;33;40m"


void error_println(const char *msg);
void warn_println(const char *msg);
void info_println(const char *msg);
void success_println(const char *msg);
#endif //TIME_INFO_H
