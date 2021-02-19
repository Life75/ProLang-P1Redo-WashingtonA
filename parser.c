#include "parser.h"
bool hasEnd =false;
bool hasBegin=false;
struct SymbolTable symbolTable[TableSize];



void parser() {

    
    for(int i=0; i < 100; i++)
    {
        symbolTable->IDs[i] = ""; 
    }
    FILE * file;
    char contents;
    char fileName[] = "a1";

    file = fopen("a1", "r");


    if (file == NULL) {
        printf("opening file error");
    }
    // else printf("file opened\n");

    int linecount = 0;
    int def = 0;
    char holder[100] = "";
    int lookAhead =0;
    memset(holder, 0, strlen(holder));
    while (1) {
    
    
        
        contents = fgetc(file);
       


        def = lexicon(contents);
        

        //prediction(def);
        //isEnd(holder);
       // printf("%c\n", contents);

    //if comment ignore until \n
        if (def == OP || def == EQ || isBegin(holder) || def == SEMICOLON || def == END) {
            //printf("hi\n");
            // 
            printf("|%s|\n",holder);
            syntaxChecker(holder);
            inputInSymbolTable(holder);

            //placing inside symbolTable

            
            memset(holder, 0, strlen(holder));

        } 
        else if (def == ID || def == NUM || def == END) {
            //printf("%s\n", holder);
            isEnd(holder);
            
            if(contents != 32 && contents != '\n')
            {
                strncat(holder, &contents, 1);
            }

        }

        if(def == END)
        {
            //printf("getting to end");
        }





        if (contents == '\n') {
            linecount++;
        }

         if (contents == EOF)
         {
            //printf("%s",holder);
            isEnd(holder);
             //printf("reached end\n");
             break;

         }
            
        //printf("%d", def);
    }
    //          printf("%s", holder);
    
    //printf("%d", linecount);




    /*  while(fgets (contents, 50, file) != NULL)
      {
         // printf("%s", contents);
      }
      */



    fclose(file);
}

bool syntaxChecker(char input[]) {

   int length = strlen(input);
//if num
   if(isdigit(input[0]))
   {
        for(int i=0; i < length; i++)
        {
            if(!isdigit(input[i])) return false;
        }    
        return true;
   }

    if(isalpha(input[0]))
    {
        char behind = "";
        //check for consective underscores
        for(int i=0; i < length; i++)
        {
            if(input[i] == 95)
            {
                //printf("underscore found");
                if(input[i-1] == 95)
                {
                    //printf("%s","incorrect");
                    return false; //2 underscores consecutive
                }
            }
    //make doesnt end with underscore
            if(i == length -1)
            {
                if(input[i] == 95) 
                {
                   // printf("%s","works1");
                    return false;
                } 
            }
            
        }
        return true;
    }
    return false;

  
   
   return false;

}

bool isBegin(char input[]) {
    char begin[] = "begin";

    if (strcmp(input, begin) == 0) {
        //printf("works");
        hasBegin = true;
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

bool isEnd(char input[]) {
    char end[] = "end.";
    //printf("%s\n",input);
    if (strcmp(input, end) == 0) {
        //printf("works");
        hasEnd = true;
        return true;
    }
/*
    for (int i = 0; i < 4; i++) {
        if (input[i] == end[i]) {
           
            if (i == 3) {
                
                return true;
            }
        } else {
            break;
        }
    }
*/
    return false;
}


bool inputInSymbolTable(char input[])
{
    //check if its in already, if not then input return true, if it is then return false 
    bool copyFound = false;
    if(isalpha(input[0]))
    {
        for(int i=0; i < TableSize; i++)
        {
            if(strcmp(input, symbolTable[i].IDs) == 0)
            {
                printf("copy\n");
                copyFound = true;
            }
        }
        if(!copyFound)
        {
            for(int i=0; i < TableSize; i++)
            {
                if(strcmp("", symbolTable[i].IDs) ==0)
                {
                    strcpy(symbolTable[i].IDs, input);
                    printf("placed\n");
                    return true;
                }
            }
        }
        else return false;

    }
}
