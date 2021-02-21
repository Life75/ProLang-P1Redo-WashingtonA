#ifndef SYMBOLTABLE_H_INCLUDED
#define SYMBOLTABLE_H_INCLUDED
#include <stdio.h>

//keeps track of the different IDs in the whole file 
struct SymbolTable
{
    char IDs[100]; 


};

//keeps track of the amount of EQ and LEFT_PAR RIGHT_PAR in a given statement 
struct StatementTable
{
    int eqCounter;
    int leftParCounter;
    int rightParCounter;
};

struct BackTrace
{
    int firstState;
    int secondState;
    int currentLine;
};


struct TraceOn
{
    int statement;
    int currentLine;
};
#endif