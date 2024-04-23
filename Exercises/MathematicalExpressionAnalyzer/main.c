#include <stdio.h>
#include "expressionAnalysis.h"


int main()
{   
    int fails = 0;
    if (!isCorrect("Files/Case1.txt"))
    {
        fails++;
    }
    if (isCorrect("Files/Case2.txt"))
    {
        fails++;
    }

    printf("Process terminated with status 0\n%d error(s)", fails);
    return 0;
}
