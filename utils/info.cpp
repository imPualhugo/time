//
// Created by hyz on 2021/1/9.
//
#include "info.h"

void error_println(const char *msg){
    printf(RED);
    printf("error:%s",msg);
    printf(COLOR_NONE);
    printf("\n");
}



void warn_println(const char *msg){
    printf(YELLOW);
    printf("warn:%s",msg);
    printf(COLOR_NONE);
    printf("\n");
}

void info_println(const char *msg){
    printf(BLUE);
    printf("info:%s",msg);
    printf(COLOR_NONE);
    printf("\n");
}

void success_println(const char *msg){
    printf(GREEN);
    printf("success:%s",msg);
    printf(COLOR_NONE);
    printf("\n");
}