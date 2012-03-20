import logging
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render_to_response
from django.template import Context, loader
from django import forms
from django.core.context_processors import csrf

logger = logging.getLogger(__name__)

def show(request):
    return render_to_response('upload/show.html',request)

def redirect(request):
    return HttpResponseRedirect('/upload/show')

def handle_uploaded_file(f):
    destination = open('upload/name.txt', 'wb+')
    for chunk in f.chunks():
        destination.write(chunk)
    destination.close()

def create(request):
    postText = ''
    if request.method == 'POST':
        file = request.FILES['uploadfile']

    if not file == None:
        # redirect to avoid repeat submit while page reloads
        print file.name
        handle_uploaded_file(file)
        return HttpResponse(file)
    elif request.method == 'POST':
        # redirect to avoid warning re-submit while comments is empty
        return HttpResponseRedirect('/upload/redirect')
    return HttpResponseRedirect('/upload/show')

def new(request):
    c = {'form_action': '/upload/create'}
    c.update(csrf(request))
    t = loader.get_template('upload/new.html')
    ctx = Context(c)
    return HttpResponse(t.render(ctx))

def gallery(request, file_id):
    t = loader.get_template('upload/show.html')
    ctx = Context(c)
    return HttpResponse(t.render(ctx))

