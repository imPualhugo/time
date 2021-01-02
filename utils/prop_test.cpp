//
// Created by hyz on 2020/12/31.
//
#include <string>
#include <iostream>
#include "properties.h"


//int main() {
//    char *profile = "../utils/test.prop";
//    FILE *file = fopen(profile, "r+");
//
//    properties props = properties(64, 64);
//    props.scan_prop_file(file);
//
////    printf("search key index:%ld\n",props.search_key_index("b"));
////
////    printf("b line_num: %lu\n",props.get_line_num("b"));
////
////    printf("size:%d\n",props.size());
////
////    printf("value:%s\n",props.get_value("c"));
////
////    printf("c line_num: %lu\n",props.get_line_num("c"));
//
////    printf("%ld",props.add("啦啦啦","5"));
//
//
//
//
////    printf("kv_tostring:%s\n", props.kv_array_toString().c_str());
////
////    printf("%ld\n",props.search_key_index("啦啦啦"));
////    printf("%ld\n",props.search_key_index("啦啦"));
////
////    printf("delete 测试: %d\n",props.del("啦啦啦", profile));
////    printf("%d\n",props.update("x","23",profile));
//
//
//    props.add("a","1");
//
//    fclose(file);
//    return 0;
//}