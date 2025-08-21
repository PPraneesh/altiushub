from django.db import models


class Todo(models.Model):
    title = models.CharField(max_length=200)
    completed = models.BooleanField(default=False)
    username = models.CharField(max_length=100)

    def __str__(self):
        return self.title