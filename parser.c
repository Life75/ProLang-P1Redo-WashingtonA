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
    memset(holder,0,strlen(holder));
    while(1)
    {
        
        contents = fgetc(file);
        if(contents == EOF)
        break;

        def = lexicon(contents);

         if(def == OP || def ==  EQ || isBegin(holder))
         {
             //printf("hi\n");
            // printf("%s\n", holder);

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

bool syntaxChecker(char input[])
{

}

bool isBegin(char input[])
{
    char begin[] = "begin";

    if(strcmp(input, begin) == 0)
    {
        printf("works");
        return true;
    }
/*
    for(int i=0; i < 5; i++)
    {
        if(input[i] == begin[i])
        {
            if(i == 4)
            {
                //printf("%s", input);
                return true;
            }
        }
        else 
        {
            break;
        } 
        return false;

    }*/
    return false;
}

bool isEnd(char input[])
{

}