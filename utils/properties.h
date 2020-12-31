//
// Created by hyz on 2020/12/30.
//

#ifndef TIME_PROPERTIES_H
#define TIME_PROPERTIES_H
#define DEFAULT_PROP_SIZE 10

#include <cstdio>
#include <vector>
#include <string>

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

    void scan_prop_file(FILE *path);

    int size();

    ulong search_key_index(char *key);

    char *get_value(char *key);

    ulong get_line_num(char *key);

    ulong add(char *key,char *value);
};


#endif //TIME_PROPERTIES_H
