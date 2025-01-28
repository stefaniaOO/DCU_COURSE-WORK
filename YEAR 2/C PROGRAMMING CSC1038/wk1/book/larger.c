#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  int number_1, number_2;

  scanf("%d",&number_1);
  scanf("%d",&number_2);

  if(number_1 > number_2)
  {
  	printf("%d is larger\n",number_1);
  } 
  else if(number_2 > number_1)
  {
  	printf("%d is larger\n",number_2);
  }
  else
  {
    puts("these numbers are equal");
  }
}
