#ifndef SYMDEF_H
#define SYMDEF_H

#define MAX 8 // max length of a word
#define LIMIT 200 // max number of words in a file

char *reservedWords[11] = {"program", "begin", "end", "if", "then", "else", "input", "output", "int", "while", "loop"};

char *relationalOperators[4] = {"=", ">", "<", "<>"};

char otherOperators[4] = {'+', '-', '*'};

char parens[2] = {'(', ')'};

char colons[2] = {':', ';'};

char words[LIMIT][MAX]; // identifiers, reserved words
int wordi = 0 , wordj = 0;
int wordLineNums[LIMIT];

char reserveds[LIMIT][MAX]; // reserved words
int resi = 0;
int resLineNums[LIMIT];

char idens[LIMIT][MAX]; // identifiers
int ideni = 0;
int idenLineNums[LIMIT];

char nums[LIMIT][MAX]; // numbers
int numi = 0, numj = 0;
int numLineNums[LIMIT];

char parens2[LIMIT]; // parenthesis
int pareni = 0;
int parenLineNums[LIMIT];

char otherOps[LIMIT]; // other operators
int otherOpi = 0;
int otherOpLineNums[LIMIT];

char relOps[LIMIT][MAX]; // relational operators
int relOpi = 0, relOpj = 0;
int relOpLineNums[LIMIT];

char colons2[LIMIT]; // colons
int coloni = 0;
int colonLineNums[LIMIT];

#endif