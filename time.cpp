//
// Created by hyz on 2020/12/28.
//
#include <ctime>
#include "time.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "init.h"

using namespace std;

const char *weekdays_sc[] = {"周一", "周二", "周三", "周四", "周五", "周六", "周日"};
const char *weekdays_tc[] = {"禮拜一", "禮拜二", "禮拜三", "禮拜四", "禮拜五", "禮拜六", "禮拜日"};
const char *weekdays_en[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};


char **weekdays = (char**)weekdays_en;

//返回一个现在时间的字符串
void show_now_time() {
    time_t now;
    time(&now);//获取系统时间
    char time_str[100];
    struct tm *p;
    p = localtime(&now);

//    int upto = 0;
//    if (p->tm_min + 60 * modf(time_zone, nullptr) > 60){
//        p->tm_min = p->tm_min + 60 * modf(time_zone, nullptr) - 60;
//        upto++;
//    }
//    p->tm_hour += upto;
//    if (p->tm_min + time_zone > 23){
//        p->tm_min = p->tm_min + 60 * modf(time_zone, nullptr) - 60;
//        upto++;
//    }


    sprintf(time_str, "%04d-%02d-%02d %02d:%02d:%02d %s\n",
            p->tm_year + 1900,
            p->tm_mon + 1,
            p->tm_mday,
            p->tm_hour,
            p->tm_min,
            p->tm_sec,
            weekdays[p->tm_wday - 1]);
    printf("%s", time_str);

//    printf("lang:%s time zone:%f\n",lang,time_zone);
}

