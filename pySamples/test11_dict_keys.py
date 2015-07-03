#
# py.test -s test11_dict_keys.py
#
# passed: python 3
# dict_keys cannot access by indexing method, convert to list()
# and order it by sort()
#
def get_sorted_dict_keys(keys):
    a = list(keys)
    a.sort()
    return a

def indexing_access(a):
    print(a[0])
    k = a[0]
    assert k == 'a'

def dump_array(arr, d):
    for k in arr:
        print("%s->%d" % (k, d[k]))

def test_dict_keys():
    d = {"a": 1, "b": 2, "c": 3}
    ks = d.keys()

    # returned dict_keys is not sorted
    print(ks)

    array = get_sorted_dict_keys(ks)
    assert(len(array) == 3)
    indexing_access(array)
    dump_array(array, d)
