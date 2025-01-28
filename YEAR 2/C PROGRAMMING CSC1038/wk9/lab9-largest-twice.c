#include<stdio.h>
#include<stdlib.h>

int findMax(int *list, int length);
int checkMax(int *list, int position, int length);

int main(int argc, char * argv[])
{
	int *list = (int*)calloc(argc - 1, sizeof(int));
	int length = argc - 1;
	for (int i = 0; i < argc - 1; ++i)
	{
		*(list + i) = atoi(argv[i+1]);
	}

	int maxPos = findMax(list, length);

	if(checkMax(list, maxPos, length))
	{
		printf("%d\n", *(list + maxPos));
	}
	else
	{
		printf("0\n");
	}

	return 0;
}

int findMax(int *list, int length)
{
	int max = *list;
	int position = 0;

	for(int i = 1; i < length; ++i)
	{
		if(max < *(list + i))
		{
			max = *(list + i);
			position = i;
		}
	}

	return position;
}

int checkMax(int *list, int position, int length)
{
	for(int i = 0; i < length; ++i)
	{
		if(i != position)
		{
			if(*(list + i) <= 0.5* *(list+position))
			{
				return 1;
			}
		}
	}

	return 0;
}