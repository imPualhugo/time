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


char **weekdays = (char **) weekdays_en;

//返回一个现在时间的字符串
void show_now_time() {
    time_t now;
    time(&now);//获取系统时间
    char time_str[100];
    struct tm *p;


//    p = localtime(&now);

    p = gmtime(&now);

//    p->tm_year = 2001 - 1900;
//    p->tm_mon = 10 - 1;
//    p->tm_mday = 31;

    int upto = 0;

    double time_zone_integer = 0;

    double *time_zone_int = &time_zone_integer;

    if (p->tm_min + 60 * modf(time_zone, time_zone_int) > 60) {
        upto++;
        p->tm_min = (p->tm_min + (int) (60 * modf(time_zone, time_zone_int))) % 60;
    } else {
        p->tm_min = (p->tm_min + (int) (60 * modf(time_zone, time_zone_int)));
    }

    p->tm_hour += upto;
    //进位后归零
    upto = 0;

    if (p->tm_hour + *time_zone_int > 23) {
        upto = (p->tm_hour + (int) *time_zone_int) / 24;
        p->tm_hour = (p->tm_hour + (int) *time_zone_int) % 24;
    } else {
        p->tm_hour = p->tm_hour + (int) *time_zone_int;
    }

//    printf("time_zone:%lf\n", time_zone);
//    printf("time_zone_int:%lf\n", *time_zone_int);
//    printf("upto:%d\n", upto);

    year_month_Upto(p, upto);

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

void year_month_Upto(struct tm *p, int upto) {
    if (upto == 0) {
        return;
    }

    //计算闰年2月
    int year_feb = 28;


    if ((p->tm_year + 1900) % 100 == 0) {
        if ((p->tm_year + 1900) % 400 == 0) {
            year_feb = 29;
        }
    } else if ((p->tm_year + 1900) % 4 == 0) {
        year_feb = 29;
    }

//    printf("year_feb:%d\n", year_feb);


    p->tm_mday += upto;
    //进日,最终进月的upto
    switch (p->tm_mon) {
        case 0:
        case 2:
        case 4:
        case 6:
        case 7:
        case 9:
        case 11:
            upto = p->tm_mday / 32;
            if (p->tm_mday > 31) {
                p->tm_mday = p->tm_mday % 31;
            }
            break;
        case 3:
        case 5:
        case 8:
        case 10:
            upto = p->tm_mday / 31;
            if (p->tm_mday > 30) {
                p->tm_mday = p->tm_mday % 30;
            }
            break;
        case 1:
            upto = p->tm_mday / (year_feb + 1);
            if (p->tm_mday > year_feb) {
                p->tm_mday = p->tm_mday % year_feb;
            }

    }

    //进月
    p->tm_mon += upto;
    if (p->tm_mon > 11) {
        p->tm_year += p->tm_mon / 11;
        p->tm_mon = p->tm_mon % 12;
    }

}