from django.http import HttpResponse
from django.template import Context, loader

def index(request):
    return HttpResponse("Hello world!!django!")

def detail(request, poll_id):
    t = loader.get_template('index.html')
    c = Context({'name': 'David is rd. following words truncated', 'title':'Personal Detial ID:%s' % poll_id })
    return HttpResponse(t.render(c))
