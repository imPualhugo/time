//
// Created by hyz on 2020/12/30.
//

#ifndef TIME_EN_US_LANG_DISPLAY_H
#define TIME_EN_US_LANG_DISPLAY_H
#include "language_display_strategy.h"
#include "../time.h"
#include "../setting.h"
#include "cstdio"
class EN_US_lang_display : public virtual language_display_strategy{
public:

    std::string change_lang_text[5] = {
            "Type the language number you want to change and press Enter.\n"};

    void time_show() override{
        weekdays = (char**)weekdays_en;
        show_now_time();
        if (open_tips){
            printf("Type time -h for more instructions help.\n");
        }
    }
    void help_show() override{
        printf("Time is a simple fuction - you can get time easily.\n");
        printf("\tUsage: time [options] [args...]\n");
        printf("Include instructions:\n");
        printf("\n");
        printf("\ttime (-now) Get local time string.\n");
        printf("\ttime (-now) Get help information.\n");
        printf("\ttime (-now) Get setting-related information.\n");
        printf("\ttime -lang Language setting\n");
    }

};


#endif //TIME_EN_US_LANG_DISPLAY_H
