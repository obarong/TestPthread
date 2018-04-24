#include <jni.h>
#include <string>
#include "hello.h"

extern "C" JNIEXPORT jstring

JNICALL
Java_com_obarong_testpthread_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_obarong_testpthread_MainActivity_testPthread(JNIEnv *env, jobject instance, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);

    sayhello(str);

    env->ReleaseStringUTFChars(str_, str);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_obarong_testpthread_MainActivity_stop(JNIEnv *env, jobject instance) {

    stophello();

}