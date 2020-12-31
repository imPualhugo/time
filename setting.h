//
// Created by hyz on 2020/12/28.
//

#ifndef TIME_SETTING_H
#define TIME_SETTING_H
#define MAX_PROPS_SIZE 256

#define MAX_PROP_LEN 128
extern char lang[];
extern double time_zone;
extern char version[];
extern bool open_tips;
//int *p_lang = &lang;
//float *p_time_zone = &time_zone;

void init_prop();




//struct prop[]  read_prop(FILE *prop_file);

#endif //TIME_SETTING_H
