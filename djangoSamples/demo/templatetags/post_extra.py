from django import template
from django.template.defaultfilters import stringfilter

register = template.Library()

# sample for stringfilter for template
@stringfilter
def getName(value): 
    if value == "1":
       return "userA" 
    return "userB"

register.filter("getName", getName)
