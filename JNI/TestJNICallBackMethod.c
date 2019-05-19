/*
 *Step1: 通过GetObjectClass()获取类的引用
 *Step2: 从引用中获取MethodID,通过调用GetMethodID()。这里需要传入方法名和签名。签名的格式为"(parameters)return-type"，即(参数类型...)返回类型。你可以使用javap工具列出一个类中方法的签名，-s打印签名，-p显示私有方法
*/
#include <jni.h>
#include <stdio.h>
#include "TestJNIInstanceVariable.h"
JNIEXPORT void JNICALL Java_TestJNICallBackMethod_nativeMethod(JNIEnv *env, jobject thisObj){
	//Get a class reference for this object
    jclass thisClass = (*env)->GetObjectClass(env, thisObj);
	//Get the Method ID for method "callback", which takes no arg and return void
    jmethodID midCallBack = (*env)->GetMethodID(env, thisClass, "callback", "()V");
    if(NULL == midCallBack) return;
    printf("In C, call back Java's callback()\n");
	//Call back the method (which returns void), based on the Method ID
    (*env)->CallVoidMethod(env, thisObj, midCallBack);
    jmethodID midCallBackStr = (*env)->GetMethodID(env, thisClass, "callback", "(Ljava/lang/String;)V");
    if(NULL == midCallBackStr) return;
    printf("In C, call back Java's callback(String)\n");
    jstring message = (*env)->NewStringUTF(env, "Hello from C");
    (*env)->CallVoidMethod(env, thisObj, midCallBackStr, message);
    jmethodID midCallBackAverage = (*env)->GetMethodID(env, thisClass, "callbackAverage", "(II)D");
    if(NULL == midCallBackAverage) return;
    jdouble average = (*env)->CallDoubleMethod(env, thisObj, midCallBackAverage, 2, 3);
    printf("In C, the average is %f\n", average);
    jmethodID midCallBackStatic = (*env)->GetStaticMethodID(env, thisClass, "callbackStatic", "()Ljava/lang/String;");
    if(NULL == midCallBackStatic) return;
    jstring resultJNIStr = (*env)->CallStaticObjectMethod(env, thisObj, midCallBackStatic);
    const char *resultCStr = (*env)->GetStringUTFChars(env, resultJNIStr, NULL);
    if(NULL == resultCStr) return;
    printf("In C, the return string is %s\n", resultCStr);
    (*env)->ReleaseStringUTFChars(env, resultJNIStr, resultCStr);
}

