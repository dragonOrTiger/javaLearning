/*
 *jint JNI_OnLoad(JavaVM* vm, void* reserved)
 *该方法在Jni so被加载时调用。该方法告诉VM此C组件使用高级的JNI版本。
 *如果你的*.so文件没有使用JNI_OnLoad()函数，VM会默认该*.so使用最老的JNI1.1版本。
 *新版的JNI做了许多扩充，如果需要使用新版的功能，如JNI 1.4 java.nio.ByteBUffer, 就必须借由JNI_OnLoad()函数来告知VM。
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <jni.h>
#include <assert.h>

jstring getString(JNIEnv *env, jclass clazz)
{
	printf("hello in c native code.\n");
	return (*env)->NewStringUTF(env, "This is Natvie String!");
}
 
#define JNIREG_CLASS "NativeLib"//指定要注册的类
 
/**
* Table of methods associated with a single class.
*/
static JNINativeMethod gMethods[] = {
	{ "getNativeString", "()Ljava/lang/String;", (void*)getString },//绑定
};
 
/*
* Register several native methods for one class.
*/
static int registerNativeMethods(JNIEnv* env, const char* className, JNINativeMethod* gMethods, int numMethods)
{
	jclass clazz;
	clazz = (*env)->FindClass(env, className);
	if (clazz == NULL) {
		return JNI_FALSE;
	}
	if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0) {
		return JNI_FALSE;
	}
 
	return JNI_TRUE;
}
 
/*
* Register native methods for all classes we know about.
*/
static int registerNatives(JNIEnv* env)
{
	if (!registerNativeMethods(env, JNIREG_CLASS, gMethods, sizeof(gMethods) / sizeof(gMethods[0])))
		return JNI_FALSE;
 
	return JNI_TRUE;
}
 
/*
* Set some test stuff up.
*
* Returns the JNI version on success, -1 on failure.
*/
jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv* env = NULL;
	jint result = -1;
 
	if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		return -1;
	}
	assert(env != NULL);
 
	if (!registerNatives(env)) {//注册
		return -1;
	}	
/* success -- return valid version number */
	result = JNI_VERSION_1_4;
 
	return result;
}
