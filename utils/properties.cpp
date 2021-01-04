//
// Created by hyz on 2020/12/30.
//



#include "properties.h"


properties::properties(int keyLen, int valueLen) : key_len(keyLen), value_len(valueLen) {
    this->key_len = keyLen;
    this->value_len = valueLen;
}

void properties::clear_array(){
    auto first = kv_array.begin();
    for (int i = 0; i < kv_array.size(); ++i) {
        kv_array.erase(first);
        ++first;
    }
    line_num_present = 0;
}

void properties::scan_prop_file(FILE *file) {
    file_input = file;

    if (file == nullptr) {
        perror("scan_prop_file(): 没有找到配置文件\n");
        return;
    }


    //扫描之前清空数组
    clear_array();


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

ulong properties::search_key_index(const char *key) {
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

ulong properties::get_line_num(char *key) {
    if (search_key_index(key) != -1) {
        return kv_array.at(search_key_index(key)).line_num;
    }
    return 0;
}


//返回值为插入的行
ulong properties::add(const char *key, const char *value) {
    if (scan_check()) {
        scan_prop_file(file_input);

        fprintf(file_input, "\n%s=%s\n", key, value);


        scan_prop_file(file_input);

        return line_num_present;
    }
    return 0;

}

bool properties::scan_check() {
    if (file_input == nullptr) {
        perror("还未扫描过一次配置文件");
        return false;
    }
    return true;
}

string properties::kv_array_toString() {
    string ret;
    if (scan_check()) {
        scan_prop_file(file_input);
        ret.append("{\n");
        for (auto &i : kv_array) {
            //char* 无法直接使用重载的+号
            string key = i.key;
            string value = i.value;
            ret += "{\n";
            ret += "\tline_num:" + std::to_string(i.line_num) + ",\n";
            ret += "\tkey:" + key + ",\n";
            ret += "\tvalue:" + value + "\n";
            ret += "}\n";
        }
        ret.append("}");
    }
    return ret;
}


bool properties::del(const char *key, const char *profile) {

    if (key != nullptr) {
        file_input = fopen(profile,"r");
        if (file_input != nullptr) {
            scan_prop_file(file_input);

            //删除文件中的配置需要重新写入文件

            FILE *_old = fopen(profile, "r");
            string temp = profile;
            temp += ".tmp";
            FILE *_new = fopen(temp.c_str(), "w");
//            char buf[2048];
//            fread(buf,sizeof (buf),1,_old);
//            fputs(buf,_new);
//
            char buf[512];
            while (!feof(_old)) {
                fgets(buf, sizeof(buf), _old);
                string temp0;
                for (int i = 0; buf[i] != '='; ++i) {
                    temp0 += buf[i];
                }
                if (temp0 == key) {
                    continue;
                }
                fputs(buf, _new);
            }
            fclose(_old);
            fclose(_new);

            string command = "rm " + string(profile);
            system(command.c_str());

            command = "mv " + string(profile) + ".tmp " + string(profile);

            system(command.c_str());
            scan_prop_file(file_input);
            return true;
        }
    }
    return false;
}



bool properties::update(const char *key, const char *value,const char *profile) {



    if (key != nullptr) {

        file_input = fopen(profile,"r");
        if (file_input != nullptr) {
//            printf("key:%s v:%s profile:%s\n",key,value,profile);
            scan_prop_file(file_input);

//            printf("扫描结果:%s\n",kv_array_toString().c_str());
            //已经在kv_array中修改
            //修改文件中的配置需要重新写入文件

            FILE *_old = fopen(profile, "r");
            string temp = profile;
            temp += ".tmp";
            FILE *_new = fopen(temp.c_str(), "w");



            char buf[512];
            while (!feof(_old)) {
                fgets(buf, sizeof(buf), _old);
                string temp0;
                int i;
                for (i = 0; buf[i] != '=' && buf[i] != '\0'; ++i) {
                    temp0 += buf[i];
                }

                if (temp0 != key) {
                    for (int j = i; buf[j] != '\0'; ++j) {
                        temp0 += buf[j];
                    }
                }else{
                    temp0 += '=';
                    temp0.append(value);
                    temp0 += '\n';
                }
                fputs(temp0.c_str(), _new);
            }
            fclose(_old);
            fclose(_new);

            string command = "rm " + string(profile);
            system(command.c_str());

            command = "mv " + string(profile) + ".tmp " + string(profile);

            system(command.c_str());
            scan_prop_file(file_input);
            return true;
        }
    }
    return false;
}