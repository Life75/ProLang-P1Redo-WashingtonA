#ifndef PARSER_H_INCLUDED 
#define PARSER_H_INCLUDED
#include <stdio.h>
#include "lexicon.h"
#include <stdbool.h>
#include <string.h>
/*
#define ID 300
#define NUM 301
#define EQ 302
#define OP 304
#define BEGIN 400
#define END 401
#define DONE 402
*/


void parser();
bool syntaxChecker(char input[]);
bool isBegin(char input[]);
bool isEnd(char input[]);

#endif



