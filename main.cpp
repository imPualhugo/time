#include "main.h"


int main(int argc, char *argv[]) {


    //初始化配置
    init_prop();
    language_display_strategy *lds;


    if (0 == strcmp(lang, "sc_cn")) {
        lds = new SC_CN_lang_display();
    } else if (0 == strcmp(lang, "tc_cn")) {
        lds = new TC_CN_lang_display();
    } else {
        lds = new EN_US_lang_display();
    }

    if (argc == 1 || 0 == strcmp(argv[1], "-now")) {
        lds->time_show();
    } else if (0 == strcmp(argv[1], "-h")) {
        lds->help_show();
    } else if (0 == strcmp(argv[1], "-info")) {
        lds->info_show();
    }else if (0 == strcmp(argv[1], "-lang"))

    return 0;
}

