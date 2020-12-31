#include <cstdio>
#include "main.h"
#include <cstring>
#include "setting.h"
#include "language/language_display_strategy.h"
#include "language/SC_CN_lang_display.h"
#include "language/EN_US_lang_display.h"
#include "language/TC_CN_lang_display.h"
//
//int main(int argc, char *argv[]) {
//
//
//    //初始化配置
//    init_prop();
//    language_display_strategy *lds;
//
//
//    if (0 == strcmp(lang, "SC_CN")) {
//        lds = new SC_CN_lang_display();
//    } else if (0 == strcmp(lang, "TC_CN")) {
//        lds = new TC_CN_lang_display();
//    } else {
//        lds = new EN_US_lang_display();
//    }
//
//    if (argc == 1 || 0 == strcmp(argv[1], "-now")) {
//        lds->time_show();
//    } else if (0 == strcmp(argv[1], "-h")) {
//        lds->help_show();
//    } else if (0 == strcmp(argv[1], "-info")) {
//        lds->info_show();
//    }
//
//    return 0;
//}
//
