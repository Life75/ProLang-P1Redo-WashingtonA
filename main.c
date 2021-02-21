#include <stdio.h>

#include "lexicon.h"
#include "parser.h"



int main(int argc, char *argv[])
{
    char fileName[10] = "a1";
    printf("Compiling file %s\n", fileName);
   //Take in script for file name     
    if (parser() == PASS) printf("This program is legal: 'success' \n");
    else printf("This program is illegal: 'fail' \n");


    return 0;
}
