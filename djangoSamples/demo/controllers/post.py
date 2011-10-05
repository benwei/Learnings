
from django.http import HttpResponse
from django.template import Context, loader
from django import forms

class handleForm(forms.Form):
    comments=forms.CharField(max_length=100)    

def new(request):
    if request.method == 'POST':
        form = handleForm(requst.POST)
    else:
        form = handleForm()

    comments = ''
    if form.is_valid():
        comments=form.clean_data['comments']

    t = loader.get_template('index.html')
    c = Context({'comments':comments})
    return HttpResponse(t.render(c))
