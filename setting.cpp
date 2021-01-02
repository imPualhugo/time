//
// Created by hyz on 2020/12/28.
//






#include "setting.h"


#include "./utils/properties.h"

char lang[MAX_PROP_LEN];
double time_zone = 0.0f;
bool open_tips = true;
string profile_path = "../setting.properties";

char version[] = "0.0.1";

char props_key[MAX_PROPS_SIZE][MAX_PROP_LEN] = {
        "lang",
        "time_zone",
        "open_tips"
};

string lang_placeholder[] = {
        "简体中文", "繁體中文", "English"
};

void init_prop() {

    FILE *prop_file = fopen(profile_path.c_str(), "r+");

    auto *props = new properties(MAX_PROP_LEN, MAX_PROP_LEN);

    props->scan_prop_file(prop_file);

    strcpy(lang, props->get_value(props_key[0]));
    time_zone = strtod(props->get_value(props_key[1]), nullptr);
    open_tips = strcmp(props->get_value(props_key[2]), "false") != 0;

    fclose(prop_file);

}

//void changeLanguage(language_display_strategy *lds) {
//    printf("%s", lds->change_lang_text[0].c_str());
//    int choose = 2;
//    for (int i = 0; i < lang_placeholder->size(); ++i) {
//        printf("%d.%s", i + 1, lang_placeholder[i].c_str());
//        if (i % 3 == 0) {
//            //每三个换一行
//            printf("\n");
//        }
//    }
//    int input = 2;
//    scanf("%d",&input);
////    if (input > );
//
//}

