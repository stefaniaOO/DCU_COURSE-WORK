/*Further practice
Experimentation with data types

Write another version of this application with the input from the keyboard.

You should now experiment with different types of number. What happens, for example, if you declare both inches and centimetres as int? Does it make any difference when you declare inches as int and centimetres as float? What happens if you reverse the process?

This is important because in a few weeks we will be looking at how computers store numbers of different types so it’s good for you to get an idea of the effects that the type something is, has on it in terms of arithmetic properties etc.

Printing Multiple Values

Okay, now modify your program. You need to remove the line which asks the user for input. Then do the following:

Set a lower bound of 30CM.

Set an upper bound of 50 centimetres.

Print the value in inches of every number starting at 30 and finishing at 49 inclusive. You should print them 5 per line. You should format your output so that the numbers appear in 4 rows of 5 columns.

If you have attempted further practice, name your new solution: lab1-convert-units-further.c and remember to upload to Einstein so that I can consider when evaluting your lab practice performance.

Note that this is for monitoring purpose only and will not be automatically marked by Einstein. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int centimetres = 30;
    float inches = centimetres;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            inches = centimetres / 2.54;
            printf("%dcm = %.2finches\t", centimetres, inches);
            centimetres++;
        }
        printf("\n");
    }
    return 0;

}
