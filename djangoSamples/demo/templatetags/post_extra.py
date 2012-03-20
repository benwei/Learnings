from django import template
from django.template.defaultfilters import stringfilter

register = template.Library()

# sample for stringfilter for template
@stringfilter
def getName(value, userInfo): 
    try:
       name = userInfo[value]
       return name
    except:
       pass
    return "Anonymous"

register.filter("getName", getName)
