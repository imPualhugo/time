#include "main.h"


int main(int argc, char *argv[]) {


    //初始化配置
    init_prop();
    language_display_strategy *lds = nullptr;

    lds = language_load(lds);


    if (argc == 1 || strcmp(argv[1], "-now") == 0) {
        lds->time_show();
    } else if (strcmp(argv[1], "-h") == 0) {
        lds->help_show();
    } else if (strcmp(argv[1], "-info") == 0) {
        lds->info_show();
    } else if (strcmp(argv[1], "-lang") == 0) {
        changeLanguage(lds);
    } else if (strcmp(argv[1], "-tips") == 0) {
        if (argc < 3) {
            return 0;
        }
        if (strcmp(argv[2], "on") == 0) {
            tips_switch(true);
            printf("Tips now on\n");
        } else if (strcmp(argv[2], "off") == 0) {
            tips_switch(false);
            printf("Tips now off\n");
        }
    } else {
        lds->time_show();
    }

    return 0;
}

