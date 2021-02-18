#include "lexicon.h"

int lexicon(char ch)
{
    if(ch == 32 || ch == '\t')
    {
        //printf("tab here \n");
    }   
    else if(ch == 61 ) //=
    {
        return EQ;
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
    else if (ch == EOF)
    {
        return DONE;
    }
    else return ch;
   // return;
}