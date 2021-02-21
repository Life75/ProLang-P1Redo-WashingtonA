#ifndef PARSER_H_INCLUDED 
#define PARSER_H_INCLUDED
#include <stdio.h>
#include "lexicon.h"
#include <stdbool.h>
#include <string.h>
#include "symbolTable.h"
/*
#define ID 300
#define NUM 301
#define EQ 302
#define OP 304
#define BEGIN 400
#define END 401
#define DONE 402
*/
#define TableSize 100


int parser();
bool syntaxChecker(char input[]);
bool isBegin(char input[]);
bool isEnd(char input[]);
bool inputInSymbolTable(char input[]);
void prediction(int def);
void match();
int IDorNum(char input[]);
//need error detection and outputing it out func


extern bool hasEnd;
extern bool hasBegin;
//extern SymbolTable symbolTable;

#endif



