from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.contrib.auth.models import User
from django import forms
from django.forms.widgets import PasswordInput, TextInput
from .models import Toppings, Pizza, Account_details 


class CreateUserForm(UserCreationForm):

    class Meta:

        model = User
        fields = ['username', 'email', 'password1', 'password2']



class LoginForm(AuthenticationForm):

    username = forms.CharField(widget=TextInput())
    password = forms.CharField(widget=PasswordInput())


class PizzaForm(forms.ModelForm):
    toppings = forms.ModelMultipleChoiceField(
        queryset=Toppings.objects.all(),  
        widget=forms.CheckboxSelectMultiple,
        required=False


    )

    class Meta:
        model = Pizza
        fields = ['size', 'crust', 'sauce', 'cheese', 'toppings']
        labels = {}


class PaymentForm(forms.ModelForm):
    card_number = forms.IntegerField(label="Card Number")
    expiration_month = forms.IntegerField(label="Expiry Month")
    expiration_year = forms.IntegerField(label="Expiry Year")
    cvc = forms.IntegerField(label="CVC",widget=forms.PasswordInput())
   
    class Meta:
        model = Account_details
        fields = ['name', 'phone_number', 'address1', 'address2', 'city', 'state', 'country', 'zip_code']
        labels = {
            'name': 'Full Name',
            'phone_number' : 'phone number',
            'address1': 'Address Line 1',
            'address2': 'Address Line 2',
            'zip_code': 'Zip/Area Code'
        }