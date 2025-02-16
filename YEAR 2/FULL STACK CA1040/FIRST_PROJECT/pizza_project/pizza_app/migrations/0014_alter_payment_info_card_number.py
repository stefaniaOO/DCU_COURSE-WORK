# Generated by Django 5.1.6 on 2025-02-16 10:33

import django.core.validators
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pizza_app', '0013_alter_payment_info_card_number'),
    ]

    operations = [
        migrations.AlterField(
            model_name='payment_info',
            name='card_number',
            field=models.IntegerField(validators=[django.core.validators.MaxValueValidator(9999999999999999)]),
        ),
    ]
