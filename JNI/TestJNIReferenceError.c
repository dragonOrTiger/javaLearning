#include <jni.h>
#include <stdio.h>
#include "TestJNIReference.h"

/*
 *JNI将对象引用(针对jobject)根据Native中的使用情况分为两类: 本地应用(local)和全局引用(global):
 *1.本地引用在Native方法中创建，方法结束时释放，仅在方法内失效。当然也可以直接调用DeleteLocalRef()方法使本地引用失效，这样可以马上GC
 *2.所有java程序传递到Native方法的引用都是本地引用。所有JNI方法返回的jobject也是本地引用。
*/
//Global Reference to the Java class "java.lang.Integer"
static jclass classInteger;
static jmethodID midIntegerInit;
jobject getInteger(JNIEnv *env, jobject thisObj, jint number){
	
	//Get a class reference for java.lang.Integer if missing
	//通过FindClass()方法获取java.lang.Integer类的引用，并将它存储到全局的静态变量中
	//然而，在下一次调用时，这个引用将不可用(而且不为NULL), 因为FindClass()返回的是一个局部变量，当方法结束时就会失效
	if(NULL == classInteger){
		printf("Find java.lang.Integer\n");
		classInteger = (*env)->FindClass(env, "java/lang/Integer");
	}
	if(NULL == classInteger) return NULL;
	
	//Get the Method ID of the Integer's constructor if missing
	if(NULL == midIntegerInit){
		printf("Get Method ID for java/lang/Integer's constructor\n");
		midIntegerInit = (*env)->GetMethodID(env, classInteger, "<init>", "(I)V");
	}
	if(NULL == midIntegerInit) return NULL;

	//Call back constructor to allocate a new instance, with an int argument
	jobject newObj = (*env)->NewObject(env, classInteger, midIntegerInit, number);
	printf("In C, constructed java.lang.Integer with number %d\n", number);
	return newObj;
}

JNIEXPORT jobject JNICALL Java_TestJNIReference_getIntegerObject(JNIEnv *env, jobject thisObj, jint number){
	getInteger(env, thisObj, number);
}
JNIEXPORT jobject JNICALL Java_TestJNIReference_anotherGetIntegerObject(JNIEnv *env, jobject thisObj, jint number){
	getInteger(env, thisObj, number);
}
