#ifndef LEXICON_H_INCLUDED 
#define LEXICON_H_INCLUDED
#include <stdio.h>

#define ID 300
#define NUM 301
#define EQ 302
#define OP 304
#define SEMICOLON 305
#define SPACE 306
#define LEFT_PAR 307
#define RIGHT_PAR 308
#define COMMENT 309
#define BEGIN 400
#define END 401
#define DONE 402
#define ERROR 999
#define PASS 404


int lexicon(char ch);
#endif