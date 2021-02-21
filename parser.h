#ifndef PARSER_H_INCLUDED 
#define PARSER_H_INCLUDED
#include <stdio.h>
#include "lexicon.h"
#include <stdbool.h>
#include <string.h>
#include "symbolTable.h"
#define TableSize 100
/*
Banner Austyn Washington 
2/21/2021
Maintains most of the functionality throughout the program. Gives the information the Lexicon to define the given type
and determines if the given token is legal or illegal to be there. 
*/

int parser(char fileName[]);
bool syntaxChecker(char input[]);
bool isBegin(char input[]);
bool isEnd(char input[]);
bool inputInSymbolTable(char input[]);
void prediction(int def);
bool match();
int IDorNum(char input[]);

extern bool hasEnd;
extern bool hasBegin;

#endif



