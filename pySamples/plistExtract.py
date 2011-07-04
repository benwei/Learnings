#!/usr/bin/python
import plistlib

pl = plistlib.Plist()

file="./com.benapps.test.plist"
dict = pl.fromFile(file)
print dict

print dict['CFBundleShortVersionString']
dict['CFBundleShortVersionString'] = "1.1.1001"

dict.write("my.plist")
