
from django.db import models
from django.contrib.auth.models import User
from django.core.validators import RegexValidator
from django.core.exceptions import ValidationError
from django.core.validators import MaxValueValidator, MinValueValidator
from datetime import datetime
from django.forms import ModelForm, ModelChoiceField, ModelMultipleChoiceField, CheckboxSelectMultiple


class Pizza(models.Model):
  id = models.AutoField(primary_key=True)
  size = models.ForeignKey('Size', on_delete=models.CASCADE, default=1)
  crust = models.ForeignKey('Crust', on_delete=models.CASCADE, default=2)
  sauce = models.ForeignKey('Sauce', on_delete=models.CASCADE, default=1)
  cheese = models.ForeignKey('Cheese', on_delete=models.CASCADE, default=1)
  toppings = models.ManyToManyField('Toppings')


class Size(models.Model):#week 4 code
  id = models.AutoField(primary_key=True)
  size = models.CharField(max_length=30)
  def __str__(self):
    return self.size

class Crust(models.Model):
  id = models.AutoField(primary_key=True)
  crust = models.CharField(max_length=30)
  def __str__(self):
    return self.crust


class Sauce(models.Model):
  id = models.AutoField(primary_key=True)
  sauce = models.CharField(max_length=30)
  def __str__(self):
    return self.sauce

class Cheese(models.Model):
  id = models.AutoField(primary_key=True)
  cheese = models.CharField(max_length=30)
  def __str__(self):
    return self.cheese

class Toppings(models.Model):
  id = models.AutoField(primary_key=True)
  topping = models.CharField(max_length=30) #many to many relationship
  def __str__(self):
    return self.topping



class ManageOrders(models.Model):
  id = models.AutoField(primary_key=True)
  user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='pizza_orders', null=True, blank=True) #many to one relationship 
  order_date = models.DateTimeField(auto_now_add=True)
  pizza = models.ForeignKey('Pizza', on_delete=models.CASCADE)
  payment = models.ForeignKey('Account_details', on_delete=models.CASCADE, null=True, blank=True) #many to one relationship
  



  
class Account_details(models.Model):
  id = models.AutoField(primary_key=True)
  user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='account_details', null=True, blank=True)
  name = models.CharField(max_length=100)
  payment_info = models.ForeignKey('Payment_info', on_delete=models.CASCADE, null=True, blank=True) 
  phone_number = models.CharField(max_length=15, validators=[RegexValidator(regex=r'^\+?1?\d{9,15}$')])
  address1 = models.CharField(max_length=100, blank=False)
  address2 = models.CharField(max_length=100, blank=True)
  city = models.CharField(max_length=50)
  state = models.CharField(max_length=50)
  country = models.CharField(max_length=50)
  zip_code = models.CharField(max_length=10)

def dynamic_min_year():
    return datetime.now().year
def dynamic_max_year():
    return datetime.now().year + 21



class Payment_info(models.Model):
  id = models.AutoField(primary_key=True)
  card_number = models.IntegerField(validators=[MaxValueValidator(9999999999999999)]) #max 16 numbers
  expiration_month = models.IntegerField(validators=[MaxValueValidator(12), MinValueValidator(1)])
  expiration_year = models.IntegerField(validators=[MaxValueValidator(dynamic_max_year), MinValueValidator(dynamic_min_year)])
  cvc = models.IntegerField(validators=[MaxValueValidator(999), MinValueValidator(000)]) #looking online it seems 000 is a valid cvc/cvv number


