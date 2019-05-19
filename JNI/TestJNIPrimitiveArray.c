/*
 *在Java中，数组是一个引用类型，像一个类。Java数组有9种，除了8种基本类型的数组外，还有一个对象数组，即java.lang.Object类型的数组。
 *在JNI中定义了8种基本类型的数组对应java的8种基本类型数组:
 *jintArray, jbyteArray, jshortArray, jlongArray, jfloatArray, jdoubleArray, jcharArray, jbooleanArray
 *和一种对象数组jobjectArray对应java中的对象数组。
 *
 *因此，你需要在数组传递时处理JNI数组和Native数组之间的转换，比如jintArray <-> jint[], jdoubleArray <-> jdouble[]等
 *JNI环境已经提供了一些转换方法，以jintArray为例:
 *1.jintArray(JNI)-->(Native)jint[]: jint* GetIntArrayElements(JNIEnv *env, jintArray a, jboolean *isCopy)
 *2.jint[]-->jintArray: 调用jintArray NewIntArray(JNIEnv *env, jsize len)分配内存，然后调用SetIntArrayRegion(JNIEnv *env, jintArray a, jsize start, jsize len, const jint *buf)将jint[]拷贝到jintArray
 *
*/
#include <jni.h>
#include <stdio.h>
#include "TestJNIPrimitiveArray.h"
JNIEXPORT jdoubleArray JNICALL Java_TestJNIPrimitiveArray_sumAndAverage(JNIEnv *env, jobject thisobj, jintArray inJNIArray){
	//1.Convert the incoming JNI jintarray to C's jint[]
	jint *inCArray = (*env)->GetIntArrayElements(env, inJNIArray, NULL);
	if(NULL == inCArray) return NULL;
	jsize length = (*env)->GetArrayLength(env, inJNIArray);
	//2.Perform its intended operations
	jint sum = 0;
	int i;
	for(i=0;i<length;i++){
		sum += inCArray[i];
	}
	jdouble average = (jdouble)sum / length;
	(*env)->ReleaseIntArrayElements(env, inJNIArray, inCArray, 0);
	jdouble outCArray[] = {sum, average};
	//3.Convert the C's Native jdouble[] to JNI jdoublearray and return
	//3.1 为jdoublearray分配内存，2个元素
	jdoubleArray outJNIArray = (*env)->NewDoubleArray(env, 2);
	if(NULL == outJNIArray) return NULL;
	//3.2  copy C's jdouble[] outCArray to JNI's jdoublearray outJNIArray 
	(*env)->SetDoubleArrayRegion(env, outJNIArray, 0, 2, outCArray);
	return outJNIArray;
}
