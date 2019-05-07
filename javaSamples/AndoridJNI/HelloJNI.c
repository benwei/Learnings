#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "org_juluos_sample_HelloJNI.h"

// java中的jstring, 轉化為c的一個字元陣列
char* Jstring2CStr(JNIEnv* env, jstring jstr)
{
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env,"java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env,clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env,barr);
    jbyte* ba = (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
    if(alen > 0)
    {
    rtn = (char*)malloc(alen+1); //new char[alen+1]; "\0"
    memcpy(rtn,ba,alen);
    rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env,barr,ba,0); //釋放記憶體
    return rtn;
}

/*
 * Class:     HelloJNI
 * Method:    add
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_org_juluos_sample_HelloJNI_add
  (JNIEnv *env, jobject caller, jint x, jint y) {
  //列印 java 傳遞過來的 jstring ;
//  LOGI("log from c code ");
//  LOGI("x= %ld",x);
//  LOGD("y= %ld",y);
  return x+y;
}

/*
 * Class:     HelloJNI
 * Method:    sayHelloInC
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_juluos_sample_HelloJNI_sayHelloInC
  (JNIEnv *env, jobject caller, jstring str) {
  char* p = Jstring2CStr(env,str);
//  LOGI("%s",p);
  char* newstr = "append string";
  //strcat(dest, sorce) 把sorce字串添加到dest字串的後面
//  LOGI("END");
  return (*env)->NewStringUTF(env, strcat(p,newstr));
}

/*
 * Class:     HelloJNI
 * Method:    intMethod
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_org_juluos_sample_HelloJNI_intMethod
  (JNIEnv *env, jobject caller, jintArray arr) {
  // 1.獲取到 arr的大小
  int len = (*env)->GetArrayLength(env, arr);
 // LOGI("len=%d", len);
  if(len==0){
  return arr;
  }
  //取出陣列中第一個元素的記憶體位址
  jint* p = (*env)-> GetIntArrayElements(env,arr,0);
  int i=0;
  for(;i<len;i++){
  //LOGI("len=%ld", *(p+i));//取出的每個元素
  *(p+i) += 5; //取出的每個元素加五
  }
  return arr;
}

