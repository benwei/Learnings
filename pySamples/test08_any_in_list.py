
some_list = ['abc-123', 'def-456', 'ghi-789', 'abc-456']

def string_in_list(token, alist):
    if any(token in s for s in some_list):
        print("%s in" % token)
        return 1

    print("%s not in" % token)
    return 0



string_in_list('abc', some_list)
string_in_list('546', some_list)
string_in_list('ooo', some_list)
