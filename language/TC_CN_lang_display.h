//
// Created by hyz on 2020/12/30.
//

#ifndef TIME_TC_CN_LANG_DISPLAY_H
#define TIME_TC_CN_LANG_DISPLAY_H
#include "language_display_strategy.h"
#include "../time.h"
#include "../setting.h"
#include "cstdio"

class TC_CN_lang_display:public virtual language_display_strategy{
    void time_show() override{
        weekdays = (char**)weekdays_tc;
        show_now_time();
        if (open_tips){
            printf("鍵入 time -h 獲取更多幫助資訊\n");
//            printf("Input time -h to get instructions help information.");
        }
    }
    void help_show() override{
        printf("Time 是一個簡單的時間獲取程式\n");
        printf("\t使用方法： time [options] [args...]\n");
        printf("包含的指令：\n");
        printf("\n");
        printf("\ttime (-now) 直接獲取本地時間字串\n");
        printf("\ttime -h 獲取幫助資訊\n");
        printf("\ttime -info 獲取設置相關資訊\n");
    }
};


#endif //TIME_TC_CN_LANG_DISPLAY_H
