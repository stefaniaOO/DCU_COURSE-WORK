from django.urls import path
from app import views #from the current directory import views
#. might have problem, just put directly app name
urlpatterns = [
   path('',views.index, name='index'),
]