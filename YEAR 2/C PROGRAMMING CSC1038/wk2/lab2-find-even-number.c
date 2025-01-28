#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  int lenght = 10;
    int arr[lenght];
      int count;

        for(int i = 0; i < argc - 1; ++i)
          {
              arr[i] = atoi(argv[i + 1]);
                }

                  for(int j = 0; j < argc - 1; ++j)
                    {

                        if((arr[j]%2) == 0)
                            {
                                  printf("%d - %d\n",j, arr[j]);
                                        ++count;
                                            }
                                              }
                                                if(count == 0){puts("No even numbers!");}

                                                  return(0);
                                                  }
                                                  
