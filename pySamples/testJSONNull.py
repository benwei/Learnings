import json

a = { "b": None}
print a

js = json.dumps(a)
print js
#'{"b": null}'

b = json.loads(js)
print b
#{u'b': None}

