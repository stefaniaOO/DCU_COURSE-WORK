# Generated by Django 5.1.6 on 2025-02-13 17:10

import django.db.models.deletion
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pizza_app', '0003_alter_account_details_payment_info_and_more'),
    ]

    operations = [
        migrations.AlterField(
            model_name='account_details',
            name='payment_info',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='pizza_app.payment_info'),
        ),
    ]
