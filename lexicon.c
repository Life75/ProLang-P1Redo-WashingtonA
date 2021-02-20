#include "lexicon.h"

int lexicon(char ch)
{
    if(ch == 32 || ch == '\t')
    {
        //printf("tab space \n");
        return SPACE;
    }  
    else if(ch == 59)
    {
        return SEMICOLON;
    } 
    else if(ch == 61 ) //=
    {
        return EQ;
    }
    else if(ch ==40)
    {
        return LEFT_PAR;
    }
    else if(ch == 41)
    {
        return RIGHT_PAR;
    }
    else if(ch == 42 || ch == 43 || ch == 45 || ch == 47 || ch == 37)
    {
         //printf("working\n");
        return OP;
    }
    else if(isdigit(ch))
    {
        return NUM;
    }
    else if(!isdigit(ch))
    {
       
        return ID;
    }
    else if(ch == 46)
    {
        //printf("end");
        return END;
    }
    else if (ch == EOF)
    {
        return DONE;
    }
    else return ch;
   // return;
}