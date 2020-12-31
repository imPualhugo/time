//
// Created by hyz on 2020/12/28.
//





#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "setting.h"


#include "./utils/properties.h"

char lang[MAX_PROP_LEN];
double time_zone = 0.0f;
bool open_tips = true;


char version[] = "0.0.1";

char props_key[MAX_PROPS_SIZE][MAX_PROP_LEN]={
        "lang",
        "time_zone",
        "open_tips"
};



//int props_index = -1;
//
//struct prop {
//    char key[MAX_PROP_LEN];
//    char value[MAX_PROP_LEN];
//};

void init_prop() {
    FILE *prop_file = fopen("../setting.properties", "r+");

    auto *props = new properties(MAX_PROP_LEN, MAX_PROP_LEN);

    props->scan_prop_file(prop_file);

    strcpy(lang, props->get_value(props_key[0]));
    time_zone = strtod(props->get_value(props_key[1]), nullptr);
    open_tips = strcmp(props->get_value(props_key[2]), "false") != 0;

    fclose(prop_file);

//    struct prop props[MAX_PROPS_SIZE];  //size 16
//    //读取每一行的数据，并且写入结构体中
//    char buf[MAX_PROP_LEN * 2 + 3];
//    while (!feof(prop_file)) {
//        props_index++;
//        memset(buf, 0, sizeof(buf));//清空缓冲区
//        fgets(buf, sizeof(buf), prop_file);
//        //去掉空行与注释
//        if (buf[0] == '\n' || buf[0]=='\0' || buf[0]=='#'){
//            continue;
//        }
//        char temp_str[MAX_PROP_LEN];
//        memset(temp_str, 0, sizeof(temp_str));//清空缓冲区
//        int i = 0; //buf当前的index
//        for (int j = 0; '=' != buf[i]; ++i, ++j) {
//            temp_str[j] = buf[i];
//        }
//        strcpy(props[props_index].key, temp_str);
//        //读取value
//        i++;
//        memset(temp_str, 0, sizeof(temp_str));
//        for (int j = 0; '\n' != buf[i] && '\0' != buf[i]; ++i, ++j) {
//            temp_str[j] = buf[i];
//        }
//        strcpy(props[props_index].value, temp_str);
//    }
//
//    fclose(prop_file);
//
//    for (int i = 0; i <= props_index; ++i) {
//        if (0 == strcmp(props[i].key, "lang")) {
//            strcpy(lang, props[i].value);
//        }
//
//        if (0 == strcmp(props[i].key, "time_zone")) {
//            time_zone = strtod(props[i].value, nullptr);
////            time_zone = atof(props[i].value);
//        }
//
//        if (0 == strcmp(props[i].key, "open_tips")) {
//            open_tips = strcmp(props[i].value, "false") != 0;
//        }
//    }

}

