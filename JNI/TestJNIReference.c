#include <jni.h>
#include <stdio.h>
#include "TestJNIReference.h"
/*
 *一个全局引用在程序员将它释放之前会一直存在。JNI提供的释放方法为DeleteGlobalRef()。
 *同时，JNI也提供了通过本地引用创建全局引用的方法NewGlobalRef()。
*/

static jclass classInteger;
static jmethodID midIntegerInit;
//Global Reference to the Java class "java.lang.Integer"
jobject getInteger(JNIEnv *env, jobject thisObj, jint number){
	
	//Get a class reference for java.lang.Integer if missing
	if(NULL == classInteger){
		printf("Find java.lang.Integer\n");
		//FindClass returns a local reference
		jclass classIntegerLocal = (*env)->FindClass(env, "java/lang/Integer");
		//Create a global reference from the local reference
		classInteger = (*env)->NewGlobalRef(env, classIntegerLocal);
		//No longer need the local reference, free it
		(*env)->DeleteLocalRef(env, classIntegerLocal);
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
