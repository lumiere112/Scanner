#include <stdio.h>
#include "token.h"
#include "scanner.h"
#include "symdef.h"

TokenType getTokenType(FILE *filePtr)
{
    int lineNum = 1;
    char ch;

    while ((ch = fgetc(filePtr)) != EOF)
    {
        if (ch == '\n')
        {
            lineNum++;
        }

        if (isalpha(ch))
        {
            words[wordi][wordj++] = ch;
            while (isalpha(ch = fgetc(filePtr)))
            {
                words[wordi][wordj++] = ch;
            }
            words[wordi][wordj] = '\0';
            wordLineNums[wordi] = lineNum;
            wordi++;
            wordj = 0;
            fseek(filePtr, -1, SEEK_CUR);
        }

        else if (isdigit(ch))
        {
            nums[numi][numj++] = ch;
            while (isdigit(ch = fgetc(filePtr)))
            {
                nums[numi][numj++] = ch;
            }
            nums[numi][numj] = '\0';
            numLineNums[numi] = lineNum;
            numi++;
            numj = 0;
            fseek(filePtr, -1, SEEK_CUR);
        }

        else if (ispunct(ch))
        {
            if (isParen(ch))
            {
                parens[pareni] = ch;
                parenLineNums[pareni] = lineNum;
                pareni++;
            }

            else if (isOtherOperators(ch))
            {
                otherOps[otherOpi] = ch;
                otherOpLineNums[otherOpi] = lineNum;
                otherOpi++;
            }

            else if (isColon(ch))
            {
                if (ch == ';')
                {
                    colons[coloni] = ch;
                    colonLineNums[coloni] = lineNum;
                    coloni++;
                }

                else if (ch == ':')
                {
                    if ((fgetc(filePtr)) == '=')
                    {
                        otherOps[otherOpi] = ch;
                        otherOpLineNums[otherOpi] = lineNum;
                        otherOpi++;
                    }

                    else
                    {
                        colons[coloni] = ch;
                        colonLineNums[coloni] = lineNum;
                        coloni++;
                    }
                }
            }

            else if (isStartRelationalOperator(ch))
            {
                if (ch == '=' || ch == '>')
                {
                    relOps[relOpi][relOpj++] = ch;
                    relOps[relOpi][relOpj] = '\0';
                    relOpLineNums[relOpi] = lineNum;
                    relOpi++;
                    relOpj = 0;
                }

                else if (ch == '<')
                {
                    if ((ch = fgetc(filePtr)) == '>')
                    {
                        relOps[relOpi][relOpj++] = '<';
                        relOps[relOpi][relOpj++] = ch;
                        relOps[relOpi][relOpj] = '\0';
                        relOpLineNums[relOpi] = lineNum;
                        relOpi++;
                        relOpj = 0;
                    }

                    else

                    {
                       fseek(filePtr, -1, SEEK_CUR); 
                    }
                }
            }
        }

    } // end while

    splitWords();

    printSummary();

    return EOT;
}

void printSummary()
{
    printf("Begin Summary:");

    printf("Total %d Reserved Words found are: \n", resi);
    printReservedWords();
    printf("\n");

    printf("\nTotal %d Identifiers found are: \n", ideni);
    printIdentifiers();
    printf("\n");

    printf("\nTotal %d Numbers found are: \n", numi);
    printNumbers();
    printf("\n");

    printf("\nTotal %d Parenthesis found are: \n", pareni);
    printParens();
    printf("\n");

    printf("\nTotal %d Relational Operators found are: \n", relOpi);
    printRelationalOperators();
    printf("\n");

    printf("\nTotal %d Other Operators found are: \n", otherOpi);
    printOtherOperators();
    printf("\n");

    printf("\nEnd Summary");
}

int isStartRelationalOperator(char c)
{
    int result = 0; // false
    if (c == '=' || c == '<' || c == '>')
    {
        result = 1;
    }
    return result;
}

int isOtherOperators(char c)
{
    int i;
    int result = 0; // false
    for (i = 0; i < 4; i++)
    {
        if (otherOperators[i] == c)
        {
            result = 1;
        }
    }
    return result;
}

int isParen(char c)
{
    int i;
    int result = 0; // false
    for (i = 0; i < 2; i++)
    {
        if (parens[i] == c)
        {
            result = 1;
        }
    }
    return result;
}

int isColon(char c)
{
    int result = 0; // false
    if (c == ':' || c == ';')
    {
        result = 1;
    }
    return result;
}

int isReservedWord(char *str)
{
    int i;
    int result = 0; // false
    for (i = 0; i < 11; i++)
    {
        if (!strcasecmp(reservedWords[i], str))
        {
            result = 1;
        }
    }
    return result;
}

void printOtherOperators()
{
    int i;
    for (i = 0; i < otherOpi; i++)
    {
        printf("%c \t (line %d) \n", otherOps[i], otherOpLineNums[i]);
    }
}

void printParens()
{
    int i;
    for (i = 0; i < pareni; i++)
    {
        printf("%c \t (line %d) \n", parens[i], parenLineNums[i]);
    }
}

void printRelationalOperators()
{
    int i;
    for (i = 0; i < relOpi; i++)
    {
        printf("%c \t (line %d) \n", relOps[i], relOpLineNums[i]);
    }
}

void printWords()
{
    int i;
    for (i = 0; i < wordi; i++)
    {
        printf("%c \t (line %d) \n",words[i], wordLineNums[i]);
    }
}

void printReservedWords()
{
    int i;
    for (i = 0; i < resi; i++)
    {
        printf("%c \t (line %d) \n", reserveds[i], resLineNums[i]);
    }
}

void printIdentifiers()
{
    int i;
    for (i = 0; i < ideni; i++)
    {
        printf("%c \t (line %d) \n", idens[i], idenLineNums[i]);
    }
}

void printNumbers()
{
    int i;
    for (i = 0; i < numi; i++)
    {
        printf("%c \t (line %d) \n", nums[i], numLineNums[i]);
    }
}

void splitWords()
{
    int i;
    for (i = 0; i < wordi; i++)
    {
        if (isReservedWord(words[i]))
        {
            strcpy(reserveds[resi], words[i]);
            resLineNums[resi] = wordLineNums[i];
            resi++;
        }
        
        else
        {
            strcpy(idens[ideni], words[i]);
            idenLineNums[ideni] = wordLineNums[i];
            ideni++;
        }
    }
}

void printToken(Token *token)
{
    char *tokenTypeStrings[] = {"Identifier", "Reserved Word", "Number", "Relational Operator", "Other Operator", "Parenthesis", "Colon"};

    int index = token -> tokenType;
    if (index < 0 || index > 6)
    {
        return;
    }

    printf("Token type: %s | Instance: %s | Line: %d", tokenTypeStrings[index], token->instance, token->lineNum);
}