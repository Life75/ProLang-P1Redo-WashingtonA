#include "parser.h"

void parser()
{
    FILE *file;
    char contents;
    char fileName[] = "a1";
    
    file = fopen("a1", "r");
    

    if(file == NULL)
    {
        printf("opening file error");
    }
   // else printf("file opened\n");

    int linecount =0;
    int def = 0;
    char holder[100] = "";
    while(1)
    {
        
        contents = fgetc(file);
        if(contents == EOF)
        break;

        def = lexicon(contents);

         if(def == OP || def ==  EQ)
         {
             //printf("hi\n");
             printf("%s\n", holder);
             isBegin(holder);
             isEnd(holder);
             memset(holder,0,strlen(holder));

         }
         else if(def == ID || def == NUM)
         {
            strncat(holder, &contents, 1);
             
         }

       
        if(contents == '\n')
        {
            linecount++;
        }
        //printf("%d", def);
    }
   //          printf("%s", holder);

    printf("%d", linecount);




  /*  while(fgets (contents, 50, file) != NULL)
    {
       // printf("%s", contents);
    }
    */        
            

    
    fclose(file);
}

_Bool syntaxChecker(char input[])
{

}

_Bool isBegin(char input[])
{

}

_Bool isEnd(char input[])
{

}