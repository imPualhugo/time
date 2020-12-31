//
// Created by hyz on 2020/12/31.
//
#include <string>
#include "properties.h"


int main(){

    FILE *file = fopen("../utils/test.prop","a+");

    properties props = properties(64, 64);
    props.scan_prop_file(file);

    printf("search key index:%ld\n",props.search_key_index("b"));

    printf("b line_num: %lu\n",props.get_line_num("b"));

    printf("size:%d\n",props.size());

    printf("value:%s\n",props.get_value("c"));

    printf("c line_num: %lu\n",props.get_line_num("c"));
    return 0;
}