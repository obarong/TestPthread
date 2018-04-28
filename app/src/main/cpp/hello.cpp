//
// Created by obarong on 2018-04-24.
//

#include "hello.h"

bool run;

void sayhello(const char *str) {
    int32_t i = 0;
    uint32_t num = 0;
    run = 1;
    while (run) {
        if (i > 100000000) {
            i = 0;
            num++;
            LOGE("I am hello in hello.cpp from %s. num=%d", str, num);
        }
        i++;
    }
}

void stophello() {
    LOGE("stophello");
    run = 0;
}
