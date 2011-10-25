from django.http import HttpResponse, HttpResponseRedirect
from django.template import Context, loader
from django import forms
from django.core.context_processors import csrf
from demo.models import notes
import datetime

class MyForm(forms.Form):
    creator_id = forms.IntegerField();
    comments = forms.CharField()

def writeComments(cid, data):
    print cid, data
    p = notes(creator_id = cid, comments=data, pub_date=datetime.datetime.now())
    p.save()

def show(request):
    return HttpResponseRedirect('/')

def new(request):
    comments = ''
    if request.method == 'POST':
        form = MyForm(request.POST)
        if form.is_valid():
            cid = form.cleaned_data['creator_id']
            comments = form.cleaned_data['comments']

    if len(comments) > 0:
       writeComments(cid, comments)

       # redirect to avoid repeat submit while page reloads
       return HttpResponseRedirect('/post/show')
    elif request.method == 'POST':
       # redirect to avoid warning re-submit while comments is empty
       return HttpResponseRedirect('/post/show')

    userDict = {'1': 'Bill Gates', '2': 'Steve Jobs'}
    c = {'form_action': '/post/new',\
         'comments':notes.objects.order_by('-pub_date'), 'userInfo': userDict}
    c.update(csrf(request))
    t = loader.get_template('index.html')
    ctx = Context(c)
    return HttpResponse(t.render(ctx))
