from django.urls import path
from pizza_app import views

urlpatterns = [
    path('',views.index, name="index"),
    path('register',views.register, name="register"),
    path('my_login',views.my_login, name="my_login"),

    path('user_logout',views.user_logout, name="user_logout"),
 
    path('dashboard/create_pizza',views.create_pizza, name="create_pizza"),
    path('dashboard',views.PizzaOrders, name='dashboard'),
  
    path('create_pizza/details',views.Payment,name="details"),
    path('create_pizza/details/order_review',views.order_review,name="order_review"),
    path('cancel_order',views.cancel_order,name="cancel_order"),
    path('order_time',views.order_time,name="order_time"),
   
]
