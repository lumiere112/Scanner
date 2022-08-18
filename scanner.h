#ifndef SCANNER_H
#define SCANNER_H

int isExAcceptableChar(char);

int isParen(char);
int isOtherOperators(char);
int isStartRelationalOperator(char);
int isColon(char);

// void printToken(Token *);
void splitWords();
void printWords();
void printReservedWords();
void printNumbers();
void printIdentifiers();
void printParens();
void printOtherOperators();
void printRelationalOperators();
void printSummary();

#endif