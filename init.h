//
// Created by hyz on 2021/1/3.
//

#ifndef TIME_INIT_H
#define TIME_INIT_H
#include "./utils/properties.h"
#include <cstring>

#define MAX_PROPS_SIZE 256

#define MAX_PROP_LEN 128

using namespace std;

extern char lang[];
extern double time_zone;
extern char version[];
extern bool open_tips;
extern string profile_path;

extern unsigned int lang_index;

extern properties *props;

void init_prop();

void lang_index_load(string basicString);

#endif //TIME_INIT_H
