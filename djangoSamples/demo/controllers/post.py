
from django.http import HttpResponse
from django.template import Context, loader
from django import forms
from django.core.context_processors import csrf
from demo.models import notes
import datetime

class MyForm(forms.Form):
    comments = forms.CharField()

def writeComments(data):
    p = notes(comments=data, pub_date=datetime.datetime.now())
    p.save()

def new(request):
    print request.method
    comments = ''
    if request.method == 'POST':
        form = MyForm(request.POST)
        #comments=request.POST.get('comments', '')
        if form.is_valid():
            comments = form.cleaned_data['comments']
        if len(comments) > 0:
           writeComments(comments)
    else:
        pass
    print comments

    c = {'form_action': '/post/new', 'comments':notes.objects.all()}
    c.update(csrf(request))
    t = loader.get_template('index.html')
    ctx = Context(c)
    return HttpResponse(t.render(ctx))
