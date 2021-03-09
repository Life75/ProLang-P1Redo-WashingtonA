#include "lexicon.h"

//ASCII Values for given types 
int lexicon(char ch)  
{

    if(ch == 42 || ch == 43 || ch == 45 || ch == 47 || ch == 37)
    {
        return OP;
    }
    if(ch == 32 || ch == '\t')
    {
        return SPACE;
    }  
    else if(ch == 44)
    {
        return COMMA;
    }
    else if(ch == 59)
    {
        return SEMICOLON;
    } 
    else if(ch == 126)
    {
        return COMMENT;
    }
    else if(ch == 61 ) 
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
        return END;
    }
    else if (ch == EOF)
    {
        return DONE;
    }
    
    //else if( ch )
    else return ch;
}



char *translator(int def)
{
    static char word[50];

    if(def == ID)
    {
        strcpy(word, "Identifier");
    }

    if(def == NUM)
    {
        strcpy(word, "Number");
        
    }

    if(def == EQ) 
    {
        strcpy(word, "="); 
    }

    if(def == OP)
    {
        strcpy(word, "operator");
    }  

    if(def == SEMICOLON)
    {
        strcpy(word, ";");
    }  

    if(def == LEFT_PAR)
    {
        strcpy(word, "(");
    }      

    if(def == RIGHT_PAR)
    {
        strcpy(word, ")");
    }  

    if(def == COMMA)
    {
        strcpy(word, ",");
    }
   

    return word;
}