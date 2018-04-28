#include <jni.h>
#include <string>
#include <malloc.h>
#include "hello.h"

pthread_attr_t pthreadAttr; // 线程属性

extern "C" JNIEXPORT jstring

JNICALL
Java_com_obarong_testpthread_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

void *printHello(void *args) {
    LOGE("enter printHello");
    LOGE("(char *)args=%s", (char *) args);

    char *str = (char *) malloc(strlen((char *) args) + 1);
    strcpy(str, (char *) args);
    sayhello(str);
    // 不要忘了malloc后要free
    free(args);
    free(str);

    // 释放线程资源
    pthread_attr_destroy(&pthreadAttr);
    pthread_exit(NULL); //！！！自动释放
}

extern "C"
JNIEXPORT void JNICALL
Java_com_obarong_testpthread_MainActivity_testPthread(JNIEnv *env, jobject instance, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);

    char *temp = (char *) malloc(strlen(str) + 1);
    strcpy(temp, str);
    pthread_t pthread;

    pthread_attr_init(&pthreadAttr);  //初始化线程属性
    pthread_attr_setdetachstate(&pthreadAttr, PTHREAD_CREATE_DETACHED);

    // 创建线程
    int err = pthread_create(&pthread, &pthreadAttr, printHello, (void *) temp);
    if (err != 0)
        LOGE("can't create thread: %s\n", strerror(err));

//    sayhello(str);

    env->ReleaseStringUTFChars(str_, str);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_obarong_testpthread_MainActivity_stop(JNIEnv *env, jobject instance) {

    stophello();

}