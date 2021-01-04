cmake_minimum_required(VERSION 3.17)
project(time CXX)

set(CMAKE_CXX_STANDARD 11)



add_executable(time init.h init.cpp main.cpp main.h time.cpp time.h  language/language_display_strategy.cpp language/language_display_strategy.h setting.cpp setting.h language/SC_CN_lang_display.h language/EN_US_lang_display.h language/SC_CN_lang_display.h language/TC_CN_lang_display.h utils/properties.cpp utils/properties.h utils/prop_test.cpp )