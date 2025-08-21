from django.urls import path
from . import views

urlpatterns = [
    path('hello/', views.HelloView.as_view(), name ='hello'),
    path('signup/',views.SignUp.as_view(), name="signup"),
    path('todo/',views.List.as_view(),name='todo'),
    path('todo/status/', views.TodoOperations.as_view(),name = "todoOps")
]