#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "token.h"
#include "scanner.h"

int main ()
{
    FILE *filePtr;

    // open program.txt
    if ((filePtr = fopen("program.txt", "r")) == NULL)
    {
        printf("Cannot open program.txt");
        exit(1);
    }

    // check if program.txt is empty
    fseek(filePtr, 0, SEEK_END);
    if (ftell(filePtr) == 0)
    {
        printf("Program.txt is empty");
        exit(1);
    }

    else
    {
        rewind(filePtr);
    }

    // begin
    rewind(filePtr);

    TokenType tokenType = UNDEFINED;

    while ((tokenType = getTokenType(filePtr)) != EOT){}

    fclose(filePtr);
    return 0;
}