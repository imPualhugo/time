//
// Created by hyz on 2020/12/29.
//

#ifndef TIME_SC_CN_LANG_DISPLAY_H
#define TIME_SC_CN_LANG_DISPLAY_H


#include <cstdio>
#include <string>
#include "language_display_strategy.h"
#include "../time.h"
#include "../setting.h"


class SC_CN_lang_display : public virtual language_display_strategy {
public:
    std::string change_lang_text[5] = {"键入需要更改语言的序号并回车\n"};

    void time_show() override{
        weekdays = (char**)weekdays_sc;
        show_now_time();
        if (open_tips){
            printf("输入 time -h 获取更多帮助信息\n");
//            printf("Input time -h to get instructions help information.");
        }
    }
    void help_show() override{
        printf("Time 是一个简单的时间获取程序\n");
        printf("\t使用方法： time [options] [args...]\n");
        printf("包含的指令：\n");
        printf("\n");
        printf("\ttime (-now) 直接获取本地时间字符串\n");
        printf("\ttime -h 获取帮助信息\n");
        printf("\ttime -info 获取设置相关信息\n");
        printf("\ttime -lang 更改语言\n");
    }




};




#endif //TIME_SC_CN_LANG_DISPLAY_H
