#include <stdio.h>	
#include "lexicon.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    printf("Compiling file %s...\n", argv[1]);
    if (parser(argv[1]) == PASS) printf("This program is legal: 'success' \n");
    else printf("This program is illegal: 'fail' \n");
    return 0;
}
