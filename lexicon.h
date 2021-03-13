#ifndef LEXICON_H_INCLUDED 
#define LEXICON_H_INCLUDED
#include <stdio.h>
#include <string.h>

/***************************************
Banner: Austyn Washington 
3/13/2021

Lexicon adds the functionality for determining what the value was given when parsed defining the diffenent myriad value types ex: ID, NUM, etc 

translator does the reverse of lexicon and translates the given value

****************************************/

#define ID 300
#define NUM 301
#define EQ 302
#define OP 304
#define SEMICOLON 305
#define SPACE 306
#define LEFT_PAR 307
#define RIGHT_PAR 308
#define COMMENT 309
#define COMMA 310
#define BEGIN 400
#define END 401
#define DONE 402
#define ERROR 999
#define PASS 404


int lexicon(char ch);
char *translator(int def);
#endif