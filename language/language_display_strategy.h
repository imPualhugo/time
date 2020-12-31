//
// Created by hyz on 2020/12/29.
//

#ifndef TIME_LANGUAGE_DISPLAY_STRATEGY_H
#define TIME_LANGUAGE_DISPLAY_STRATEGY_H
#include <cstdio>

#include "../setting.h"

class language_display_strategy {
public:

    virtual void time_show(){}

    virtual void help_show(){}

    virtual void info_show(){
        printf("lang:%s\n"
               "time_zone:%.2lf\n"
               "version:%s\n", lang, time_zone, version);
    }
};


#endif //TIME_LANGUAGE_DISPLAY_STRATEGY_H
