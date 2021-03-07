#ifndef SYMBOLTABLE_H_INCLUDED
#define SYMBOLTABLE_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>

/*
Banner Austyn Washington 
2/21/2021 
SymbolTable holds and tracks the symbols for the Identifiers, statement keeps track of the amount of EQ '=', LEFT_PAR '(', and RIGHT_PAR ')'
throughout the execution of a given statement (not line, but statement). TraceOn contains the parsed information for determining wether the parsed types are
legal or illegal
*/

//keeps track of the different IDs in the whole file 
struct SymbolTable
{
    char IDs[100]; 
    bool intFlag;
    int currentLine;
};

//keeps track of the amount of EQ and LEFT_PAR RIGHT_PAR in a given statement 
struct StatementTable
{
    int eqCounter;
    int leftParCounter;
    int rightParCounter;
};

//Determines Legal and Illegal statements throughout the code with their current line count 
struct TraceOn
{
    int statement;
    int currentLine;
};
#endif



