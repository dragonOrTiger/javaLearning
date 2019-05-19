/*
 *Step1: 通过GetObjectClass()方法获取该对象的类的引用;
 *Step2: 通过GetFieldID()方法从类引用中(Step1得到该引用)获取FieldID;调用该方法需要传入成员变量的名称和对应field的描述(descriptor)(或者签名(signature)):
 *描述的内容具体如下:
 *对于一个java类而言，Field的描述格式为"L<fully-qualified-name>;",以(/)代替包名中的(.)。比如String类型的descriptor为"Ljava/lang/String;"。(分号不能漏!!!)
 *对于基本类型，"I"-->int, "B"-->byte, "S"-->short, "J"-->long, "F"-->float, "D"-->double, "C"-->char, "Z"-->boolean
 *对于数组而言，对象数组以"["作为前缀，比如"[Ljava/lang/Object;"作为一个Object数组的描述，[I为int的描述
 *基于FieldID，我们可以通过GetObjectField()或者Get<primitive-type>Field()方法访问势力的成员变量。
 *更新实例中成员变量的值，可以通过SetObjectField()或Set<primitive-type>Field()来修改内容，这里需要传入参数FieldID
*/
#include <jni.h>
#include <stdio.h>
#include "TestJNIInstanceVariable.h"

JNIEXPORT void JNICALL Java_TestJNIInstanceVariable_modifyInstanceVariable(JNIEnv *env, jobject thisObj){
	//Get a reference to this object's class
	jclass thisClass = (*env)->GetObjectClass(env, thisObj);

	//int
	//Get the Field ID of the instance variables "number"
	jfieldID fidNumber = (*env)->GetFieldID(env, thisClass, "number", "I");
	if(NULL == fidNumber) return;

	//Get the int given the Field ID
	jint number = (*env)->GetIntField(env, thisObj, fidNumber);
	printf("In C, the int is %d\n", number);

	//Change the variable
	number = 99;
	(*env)->SetIntField(env, thisObj, fidNumber, number);

	//Get the Field ID of the instance variables "message"
	jfieldID fidMessage = (*env)->GetFieldID(env, thisClass, "message", "Ljava/lang/String;");
	if(NULL == fidMessage) return;

	//String
	//Get the object given the Field ID
	jstring message = (*env)->GetObjectField(env, thisObj, fidMessage);

	//Create a C-string with the JNI String
	const char *cStr = (*env)->GetStringUTFChars(env,  message, NULL);
	if(NULL == cStr) return;

	printf("In C, the string is %s\n", cStr);
	(*env)->ReleaseStringUTFChars(env, message, cStr);
	//Create a new C-String and assign to the JNI string
	message = (*env)->NewStringUTF(env, "Hello from C");
	if(NULL == message) return;

	//modify the instance variables
	(*env)->SetObjectField(env, thisObj, fidMessage, message);
}
