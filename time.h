//
// Created by hyz on 2020/12/28.
//

#ifndef TIME_TIME_H
#define TIME_TIME_H
#define UTC 0
//#define PS
#define CST 8

void show_now_time();

void year_month_Upto(struct tm *p, int upto);

extern const char *weekdays_sc[];
extern const char *weekdays_tc[];
extern const char *weekdays_en[];

extern char **weekdays;



#endif //TIME_TIME_H
