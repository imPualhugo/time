//
// Created by hyz on 2020/12/29.
//

#ifndef TIME_LANGUAGE_DISPLAY_STRATEGY_H
#define TIME_LANGUAGE_DISPLAY_STRATEGY_H
#include <cstdio>
#include <string>
#include "../init.h"


class language_display_strategy {

public:

    virtual void time_show(){}

    virtual void help_show(){}



    virtual void info_show(){


        printf("lang:%s\n"
               "time_zone:%.2lf\n"
               "version:%s\n", lang, time_zone, version);
    }
    std::string change_lang_text[5];

private:

};


#endif //TIME_LANGUAGE_DISPLAY_STRATEGY_H
