/*
 *通过NewObject方法和NewObjectArray()方法，我们可以在Native中创建jobject和jobjectArray，并将其返回给java程序
 *回调构造方法和回调成员方法类似。首先获取构造函数的Method ID.方法名为"<init>"，返回类型为"V".
 *然后就可以通过调用NewObject()方法调用构造函数来构建一个java对象。
*/
#include <jni.h>
#include <stdio.h>
#include "TestJNIInstanceVariable.h"
JNIEXPORT jobject JNICALL Java_TestJNIConstructor_getIntegerObject(JNIEnv *env, jobject thisObj, jint number){
	//Get a class reference for java.lang.Integer
    jclass cls = (*env)->FindClass(env, "java/lang/Integer");
	//Get the Method ID of the constructor which takes an int
    jmethodID midInit = (*env)->GetMethodID(env, cls, "<init>", "(I)V");
    if(NULL == midInit) return NULL;
	//Call back constructor to allocate a new instance, with an int argument
    jobject newObj = (*env)->NewObject(env, cls, midInit, number);
	//Try running the toString() on this newly create object
    jmethodID midToString = (*env)->GetMethodID(env, cls, "toString", "()Ljava/lang/String;");
    if(NULL == midToString) return NULL;
    jstring resultStr = (*env)->CallObjectMethod(env, newObj, midToString);
    const char *resultCStr = (*env)->GetStringUTFChars(env, resultStr, NULL);
    printf("In C: the number is %s\n", resultCStr);
    return newObj;
}
