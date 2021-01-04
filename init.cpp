//
// Created by hyz on 2021/1/3.
//


#include "init.h"

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