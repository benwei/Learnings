from django.db import models

class notes(models.Model):
    creator_id = models.PositiveIntegerField(0);
    comments = models.CharField(max_length=200)
    pub_date = models.DateTimeField('date published')
