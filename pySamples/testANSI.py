#!/usr/bin/python
class BGColors:
    def __init__(self):
        print '''
        \033[43m    \033[44m    \033[45m    
        \033[43m    \033[44m    \033[45m    
        \033[43m    \033[44m    \033[45m    
        \033[43m    \033[44m    \033[45m    
        \033[0m
        '''
    def show(self):
        for i in range(20):
            print "%d -> \033[%dm    \033[0m" % (i, 20+i)

bc = BGColors()

bc.show()

'''
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
'''
