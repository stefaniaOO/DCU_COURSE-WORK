from django.shortcuts import render, redirect, get_object_or_404
from .models import ManageOrders, Pizza, Account_details
from .forms import CreateUserForm, LoginForm, PizzaForm, PaymentForm
from django.contrib.auth.decorators import login_required
from django.contrib.auth.models import auth
from django.contrib.auth import authenticate, login, logout
from django.contrib import messages
from django.http import Http404, JsonResponse

def index(request):
    return render(request, 'index.html')

@login_required(login_url="my_login")
def order_time(request):
    latest_order = ManageOrders.objects.filter(user=request.user).order_by('-id').first()
    if not latest_order:
        raise Http404("No orders found.")
    creation_time = latest_order.order_date
    return render(request, 'order_time.html', {'creation_time': creation_time})

def register(request):
    form = CreateUserForm()
    if request.method == "POST":
        form = CreateUserForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('my_login')
    context = {'registerform': form}
    return render(request, 'register.html', context=context)

def my_login(request):
    form = LoginForm()
    if request.method == 'POST':
        form = LoginForm(request, data=request.POST)
        if form.is_valid():
            username = request.POST.get('username')
            password = request.POST.get('password')
            user = authenticate(request, username=username, password=password)
            if user is not None:
                auth.login(request, user)
                return redirect("dashboard")
    context = {'loginform': form}
    return render(request, 'my_login.html', context=context)

def user_logout(request):
    auth.logout(request)
    return redirect("index")

@login_required(login_url="my_login")
def dashboard(request):
    return render(request, 'dashboard.html')

@login_required(login_url="my_login")
def make_pizza(request):
    return render(request, 'make_pizza.html')

@login_required(login_url="my_login")
def PizzaOrders(request):
    pizza_orders = ManageOrders.objects.filter(user=request.user).order_by('-order_date')
    return render(request, 'dashboard.html', {'PizzaOrders': pizza_orders})

@login_required(login_url="my_login")
def details(request):
    return render(request, 'details.html')

@login_required(login_url="my_login")
def create_pizza(request):
    if request.method == "POST":
        form = PizzaForm(request.POST)
        if form.is_valid():
            pizza = form.save()
            new_order = ManageOrders(user=request.user, pizza=pizza)
            new_order.save()
            return redirect('details')
        else:
            return render(request, 'create_pizza.html', {'form': form})
    else:
        form = PizzaForm()
        return render(request, 'create_pizza.html', {'form': form})

def my_view(request):
    current_user = request.user
    context = {
        'user': current_user,
    }
    return render(request, 'dashboard.html', context)

@login_required(login_url="my_login")
def order_review(request):
    latest_order = ManageOrders.objects.filter(user=request.user).order_by('-id').first()
    if not latest_order:
        raise Http404("No orders found.")
    return render(request, 'order_review.html', {'order': latest_order})

@login_required(login_url="my_login")
def Payment(request):
    if request.method == "POST":
        form = PaymentForm(request.POST)
        if form.is_valid():
            latest_order = ManageOrders.objects.filter(user=request.user).order_by('-id').first()
            if latest_order:
                payment_info = form.save(commit=False)
                payment_info.save()
                latest_order.payment = payment_info
                latest_order.save()
                account_details = Account_details.objects.filter(user=request.user).first()
                if account_details:
                    account_details.payment_info = payment_info
                    account_details.save()
                return redirect('order_review')
    else:
        form = PaymentForm()
    return render(request, 'details.html', {'form': form})


@login_required(login_url="my_login")
def cancel_order(request):
    if request.method == "POST":
        latest_order = ManageOrders.objects.filter(user=request.user).order_by('-id').first()
        if latest_order:
            pizza = latest_order.pizza
            latest_order.delete()
            pizza.delete()
            messages.success(request, "Order has been canceled.")
            return redirect('dashboard')
        messages.error(request, "No order found to cancel.")
        return redirect('order_review')
    return redirect('order_review')