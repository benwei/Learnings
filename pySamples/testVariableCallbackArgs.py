#!/usr/bin/env python
# -*- coding: utf-8 -*-
import logging
import time

level = logging.DEBUG
logging.basicConfig(format='%(asctime)s.%(msecs)d [%(levelname)s] %(message)s',level=level)

class VariableCallbackArgs:
    def __init__(self):
        self.apiRetCode = 0
        self.max_retry_times = 2
        self.base_retry_idletime = 1

    def wait_retry_action(self, retry_times):
        if retry_times != 0:
            idletime = self.base_retry_idletime * retry_times
            logging.error("error upload, retry %s after %s sec" % (retry_times, idletime))
            time.sleep(idletime)

    def genericVarCallback(self, cb, args=()):
        argc = len(args)
        if argc == 0:
           return cb()
        elif argc == 1:
           arg1 = args
           return cb(arg1)
        elif argc == 2:
           arg1, arg2 = args
           return cb(arg1, arg2)
        logging.error("unsupport retry callback %s" % argc)
        return None 

    def retryCB(self, cb, args=()):
        self.apiRetCode = 1
        retry_times = 0

        while self.apiRetCode != 0 and retry_times <= self.max_retry_times:
            self.wait_retry_action(retry_times)
            dic=self.genericVarCallback(cb, args)
            if self.apiRetCode == 0:
                return dic
            retry_times+=1
        return dic 

class Testcase(VariableCallbackArgs):
    def testnoargs(self):
        print "no arg"
        return None

    def testa(self, mydata):
        print "msg:%s" % mydata
        return None

    def sum(self, a, b):
        print "%s + %s = %s" %(a,b, a+b) 
        return None

    def run(self):
        self.retryCB(self.testa, ('test1',))
        self.retryCB(self.sum, (2,3))
        self.retryCB(self.testnoargs)

v = Testcase()
v.run()
