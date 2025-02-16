from django.contrib import admin
from pizza_app.models import Pizza, Sauce, Size, Cheese, Crust, Toppings, ManageOrders
# Register your models here.
admin.site.register(Pizza)
admin.site.register(Sauce)
admin.site.register(Size)
admin.site.register(Cheese)
admin.site.register(Crust)
admin.site.register(Toppings)
admin.site.register(ManageOrders)