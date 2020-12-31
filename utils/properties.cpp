//
// Created by hyz on 2020/12/30.
//


#include <cstring>
#include "properties.h"


properties::properties(int keyLen, int valueLen) : key_len(keyLen), value_len(valueLen) {
    this->key_len = keyLen;
    this->value_len = valueLen;
}

void properties::scan_prop_file(FILE *file) {
    file_input = file;

    if (file == nullptr) {
        perror("没有找到配置文件");
        return;
    }
    char buf[key_len + value_len + 3];



    while (!feof(file)) {
        memset(buf, 0, sizeof(buf));
        fgets(buf, key_len + value_len + 3, file);
        line_num_present++;

        //去掉空行与注释
        if (buf[0] == '\n' || buf[0] == '\0' || buf[0] == '#') {
            continue;
        }

        kv_entity entity{};
        char temp_str[key_len];
        memset(temp_str, 0, sizeof(temp_str));//清空缓冲区
        int i = 0; //buf当前的index
        //读取key
        for (int j = 0; '=' != buf[i]; ++i, ++j) {
            temp_str[j] = buf[i];
        }
//        printf("第%d个%s\n",line_num_present,temp_str);
        strcpy(entity.key, temp_str);

        //读取value
        i++;
        memset(temp_str, 0, sizeof(temp_str));
        for (int j = 0; '\n' != buf[i] && '\0' != buf[i]; ++i, ++j) {
            temp_str[j] = buf[i];
        }
        strcpy(entity.value, temp_str);

//        printf("第%d个的value:%s\n",line_num_present,temp_str);
//        printf("写入的value:%s\n",entity.value);

        entity.line_num = line_num_present;
//        printf("当前行数:%d\n",line_num_present);
//        printf("录入行数:%d\n",entity.line_num);
        kv_array.push_back(entity);
    }

}//tested

ulong properties::search_key_index(char *key) {
    ulong index = 0;
    auto first = kv_array.begin();
    auto end = kv_array.end();
    while (first != end) {
        if (0 == strcmp(first->key, key)) {
            break;
        }
        ++index;
        ++first;
    }
    if (index >= kv_array.size()) { //查找到最后都没有
        return -1;
    }
    return index;
}

char *properties::get_value(char *key) {
    if (kv_array.empty() || search_key_index(key) == -1) {
        return nullptr;
    }
    return kv_array.at(search_key_index(key)).value;
}


int properties::size() {
    return kv_array.size();
}

ulong properties::get_line_num(char *key){
    if (search_key_index(key) != -1){
        return kv_array.at(search_key_index(key)).line_num;
    }
    return 0;
}




//返回值为插入的行
ulong properties::add(char *key,char *value){
    if (file_input == nullptr){
        perror("还未扫描过一次配置文件");
    }
    scan_prop_file(file_input);

    fprintf(file_input,"%s=%s\n",key,value);

    scan_prop_file(file_input);

    return line_num_present;
}