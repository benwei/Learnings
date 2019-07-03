package org.juluos.sample;

public class HelloJNI {
 static {
     //System.load("/Users/ben_wei/src/github/Learnings/javaSamples/AndoridJNI/libhellolib.so");
     System.loadLibrary("hellolib");
 }
 public native int add(int x ,int y);
 public native String sayHelloInC(String s);
 public native int[] intMethod(int[] iNum);
}
