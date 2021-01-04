//
// Created by hyz on 2020/12/28.
//

#ifndef TIME_SETTING_H
#define TIME_SETTING_H


#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "language/language_display_strategy.h"
#include "language/SC_CN_lang_display.h"
#include "language/TC_CN_lang_display.h"
#include "language/EN_US_lang_display.h"

extern vector<string> lang_placeholder;

language_display_strategy *language_load(language_display_strategy *lds);

language_display_strategy *changeLanguage(language_display_strategy *lds);



#endif //TIME_SETTING_H
