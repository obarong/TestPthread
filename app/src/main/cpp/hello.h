//
// Created by obarong on 2018-04-24.
//

#ifndef TESTPTHREAD_HELLO_H
#define TESTPTHREAD_HELLO_H

#include <stdio.h>
#include <string.h>
#include <android/log.h>

#define LOG_TAG "hello"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

void sayhello(const char *str);
void stophello();

#endif //TESTPTHREAD_HELLO_H
