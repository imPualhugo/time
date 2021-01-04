//
// Created by hyz on 2020/12/30.
//

#ifndef TIME_PROPERTIES_H
#define TIME_PROPERTIES_H
#define DEFAULT_PROP_SIZE 10

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

//#include "../setting.h"


typedef unsigned long ulong;

using namespace std;


class kv_entity {

public:
    ulong line_num = 0;
    char key[128]{};
    char value[256]{};
};

class properties {

    int key_len = 128;
    int value_len = 256;

    ulong line_num_present = 0;

    std::vector<kv_entity> kv_array;

    FILE *file_input = nullptr;

public:
    properties(int keyLen, int valueLen);

    ~properties() = default;

    void scan_prop_file(FILE *path);

    int size();

    ulong search_key_index(const char *key);

    char *get_value(char *key);

    ulong get_line_num(char *key);

    string kv_array_toString();

    ulong add(const char *key,const char *value);

    bool del(const char *key,const char *profile);

    bool update(const char *key,const char *value,const char *profile);
private:

    bool scan_check();

    void clear_array();
};


#endif //TIME_PROPERTIES_H
