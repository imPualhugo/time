//
// Created by hyz on 2020/12/28.
//


#include "setting.h"


vector<string> lang_placeholder = {
        "简体中文", "繁體中文", "English"
};

language_display_strategy *language_load(language_display_strategy *lds) {
    init_prop();
    if (0 == strcmp(lang, "sc_cn")) {
        lds = new SC_CN_lang_display();
        return lds;
    } else if (0 == strcmp(lang, "tc_cn")) {
        lds = new TC_CN_lang_display();
        return lds;
    } else {
        lds = new EN_US_lang_display();
        return lds;
    }
}


language_display_strategy *changeLanguage(language_display_strategy *lds) {
    printf("%s\n", lds->change_lang_tips(0).c_str());

    for (int i = 0; i < lang_placeholder.size(); ++i) {
        printf("%d.%s\t", i + 1, lang_placeholder[i].c_str());
        if ((i + 1) % 3 == 0) {
            //每三个换一行
            printf("\n");
        }
    }
    int input = 3;
    scanf("%d", &input);
    printf("input: %d\n", input);
    if (input > lang_placeholder.size() || input <= 0) {
        perror(lds->change_lang_tips(1).c_str());

    } else {
        string language;

        switch (input) {
            case 1:
                language = "sc_cn";
                break;
            case 2:
                language = "tc_cn";
                break;
            default:
                language = "en_us";
                break;
        }
//        printf("language: %s\n",language);
//        printf("profile_path:%s\n",profile_path.c_str());

        bool ret = props->update("lang", language.c_str(), profile_path.c_str());
//        printf("ret:%d\n",ret);

        if (ret) {

            lds = language_load(lds);
            printf("%s\n", lds->change_lang_tips(2).c_str());
            return lds;
        }
    }

    return lds;
}

