/*
 *访问静态变量与访问成员变量类似，只是调用的方法不同
 *比如GetStaticFieldID(),Get|SetStaticObjectField(), Get|SetStatic<primitive-type>Field()
*/
#include <jni.h>
#include <stdio.h>
#include "TestJNIInstanceVariable.h"
JNIEXPORT void JNICALL Java_TestJNIStaticVariable_modifyStaticVariable(JNIEnv *env, jobject thisObj){
	//Get a reference to this object's class
    jclass cls = (*env)->GetObjectClass(env, thisObj);

	//Read the int static variable and modify its value
    jfieldID fidNumber = (*env)->GetStaticFieldID(env, cls, "number", "D");
    if(NULL == fidNumber) return;
    jdouble number = (*env)->GetStaticDoubleField(env, cls, fidNumber);
    printf("In C, the int is %f\n", number);
    number = 77.88;
    (*env)->SetStaticDoubleField(env, cls, fidNumber, number);
}
