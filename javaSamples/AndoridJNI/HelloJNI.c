#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "org_juluos_sample_HelloJNI.h"
#ifndef LOGI
#define LOGI printf
#endif

#ifndef LOGD
#define LOGD printf
#endif

// java's jstring class to c char array
char* Jstring2CStr(JNIEnv* env, jstring jstr)
{
	char* rtn = NULL;
	jclass clsstring = (*env)->FindClass(env,"java/lang/String");
	jstring strencode = (*env)->NewStringUTF(env,"GB2312");
	jmethodID mid = (*env)->GetMethodID(env,clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr= (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode);
	jsize alen = (*env)->GetArrayLength(env,barr);
	jbyte* ba = (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
	if(alen > 0)
	{
		rtn = (char*)malloc(alen+1); //new char[alen+1]; "\0"
		memcpy(rtn,ba,alen);
		rtn[alen]=0;
	}
	(*env)->ReleaseByteArrayElements(env,barr,ba,0);
	return rtn;
}

JNIEXPORT jint JNICALL Java_org_juluos_sample_HelloJNI_add
(JNIEnv *env, jobject caller, jint x, jint y) {
	LOGI("log from c code %s: ", __FILE__);
	LOGI("x= %d y= %d\n",x, y);
	return x+y;
}

JNIEXPORT jstring JNICALL Java_org_juluos_sample_HelloJNI_sayHelloInC
(JNIEnv *env, jobject caller, jstring str) {
	char* p = Jstring2CStr(env,str);
	char* newstr = "append string";
	return (*env)->NewStringUTF(env, strcat(p,newstr));
}

JNIEXPORT jintArray JNICALL Java_org_juluos_sample_HelloJNI_intMethod
(JNIEnv *env, jobject caller, jintArray arr) {
	int len = (*env)->GetArrayLength(env, arr);
	if(len==0){
		return arr;
	}
	jint* p = (*env)-> GetIntArrayElements(env,arr,0);
	int i=0;
	for(;i<len;i++){
		*(p+i) += 5;
	}
	return arr;
}

