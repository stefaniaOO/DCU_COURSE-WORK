#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int tries, conversion, penalty, drop_goal;
  int i = 0;
  printf("insert points");
  scanf("%d",&tries, &conversion, &penalty,&drop_goal);
  if(tries < 0){
  printf("insert non negative tries");
  scanf("%d",&tries);
  }
  else if(conversion < 0){
  printf("insert non negative conversion");
  scanf("%d",&conversion);
  }
  else if(penalty < 0){
  printf("insert non negative penalty");
  scanf("%d",&penalty);
  }
  else if(drop_goal < 0){
  printf("insert non negative drop goal");
  scanf("%d",&drop_goal);
  }

  conversion = conversion * 2;
  penalty = penalty * 3;
  drop_goal = drop_goal * 3;
  printf("%d\n", tries+conversion+penalty+drop_goal);


return (0);
}



