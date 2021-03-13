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


Changes 3/13/2021
Additions for project 2: added functions:
checkIfIntTag()
checkInit()
registerCOmp()
computeLine()
expression()
printPostFix()


These functions give the capabilities of checking for initalization of variables and make sure any IDs used are initalized beforehand and adds 
computational arithmetic for the given expressions of the file. 

*/

int parser(char fileName[]);
bool syntaxChecker(char input[]);
bool isBegin(char input[]);
bool isEnd(char input[]);
bool inputInSymbolTable(char input[], int currentLine);
void prediction(int def);
bool match();
int IDorNum(char input[]);
bool checkIfIntTag(char input[]);
bool checkInit();
void registerComp();
void computeLine(int index);
int expression(int r, int index);
void printPostFix();

extern bool hasEnd;
extern bool hasBegin;


#endif



