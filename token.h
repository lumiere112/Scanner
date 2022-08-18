#ifndef TOKEN_H
#define TOKEN_H

#define MAX 8 // max length of a word
#define LIMIT 200 // max number of words in a file

typedef enum 
{
    IDENT,
    RESWORD,
    NUMBER,
    RELATIONAL_OP,
    OP,
    PAREN,
    COLON,

    UNDEFINED,
    EOT

/*
    RELATIONAL_OP_EQUAL, // =
    RELATIONAL_OP_GREATER, // >
    RELATIONAL_OP_LESS, // <
    RELATIONAL_OP_NOT_EQUAL, // <>

    OP_ASSIGNMENT, // :=
    OP_ADD, // +
    OP_SUB, // -
    OP_MULT, // *

    PAREN_OPEN, // (
    PAREN_CLOSE, // )

    COLON_SEMI, // ;
    COLON_NORMAL, // :
*/

} TokenType;

typedef struct 
{
    TokenType tokenType;
    char *instance;
    int lineNum;
} Token;

#endif