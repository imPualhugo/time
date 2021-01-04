#include "main.h"


int main(int argc, char *argv[]) {


    //初始化配置
    init_prop();
    language_display_strategy *lds = nullptr;

    lds = language_load(lds);


    if (argc == 1 || 0 == strcmp(argv[1], "-now")) {
        lds->time_show();
    } else if (0 == strcmp(argv[1], "-h")) {
        lds->help_show();
    } else if (0 == strcmp(argv[1], "-info")) {
        lds->info_show();
    }else if (0 == strcmp(argv[1], "-lang")){
        changeLanguage(lds);
    }else{
        lds->time_show();
    }

    return 0;
}

