include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *phrase[] = argv[1];
    int lenght = strlen(phrase);
    char reverse_phrase[lenght];
    
    int j = 0;

    for(int i = lenght; i >= 0; --i)
    {

        reverse_phrase[j] = phrase[i];
        ++j;
        printf("%d", lenght);
    }

    return 0;
}
