/*
 *export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
 *gcc HelloJNI.c -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" -fPIC -shared -o libhello.so
 */
//jni.h是什么？里面存储了大量的函数和对象，它有个很好的方法就是通过native方法名，获取C函数。
#include <jni.h>
#include <stdio.h>
#include "HelloJNI.h"
//Implementation of native method sayHello() of HelloJNI class
//JNIEnv *env这个env可以看作是JNI接口本身的一个对象，jni.h头文件中存在大量被封装好的函数，这些函数也是JNI编程中经常被使用到的。要想使用这些函数就需要使用JNIEnv这个对象。
//jobject obj:代表native方法的调用者; 
//如果native的sayHello方法实际上运行C的Java_HelloJNI_sayHello()方法，我们是不能随意写函数名的，只能这样写。
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject obj){
	printf("Hello World!\n");
	return;
}
