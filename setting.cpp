//
// Created by hyz on 2020/12/28.
//



#include "setting.h"



void changeLanguage(language_display_strategy lds) {
    printf("%s", lds.change_lang_text[0].c_str());
    int choose = 2;
    for (int i = 0; i < lang_placeholder->size(); ++i) {
        printf("%d.%s", i + 1, lang_placeholder[i].c_str());
        if (i % 3 == 0) {
            //每三个换一行
            printf("\n");
        }
    }
    int input = 2;
    scanf("%d",&input);
//    if (input > );

}

