#include "parser.h"
bool hasEnd =false;
bool hasBegin=false;
int lookAhead[TableSize];
int eachParsedStatement[TableSize];

struct SymbolTable symbolTable[TableSize];
struct StatementTable statementTable[TableSize];
struct BackTrace backTrace[TableSize]; 
struct BackTrace railRoad[TableSize];
struct TraceOn TraceOn[TableSize];



void parser() {

    
    for(int i=0; i < 100; i++)
    {
        symbolTable->IDs[i] = ""; 
    }

    for(int i=0; i < 100; i++)
    {
        lookAhead[i] = -1; 
    }

    for(int i=0; i < 100; i++)
    {
        railRoad[i].secondState = -1; 
    }

    for(int i=0; i < 100; i++)
    {
        TraceOn[i].statement = -1; 
    }





    statementTable->eqCounter =0;
    statementTable->leftParCounter =0;
    statementTable->rightParCounter =0;


    backTrace->firstState =0;
    backTrace->firstState =0;
    backTrace->currentLine =0;

    FILE * file;
    char contents;
    char fileName[] = "a1";

    file = fopen("a1", "r");


    if (file == NULL) {
        printf("opening file error");
    }
    // else printf("file opened\n");

    int linecount = 1;
    int def = 0;
    char holder[100] = "";
    int lookAhead =0;
    int lastDef =0;
    int deny =0;
    bool IDhit = false;
    memset(holder, 0, strlen(holder));
    while (1) {
    
    
        //printf("%d\n", lastDef);
        contents = fgetc(file);
       


        def = lexicon(contents);
        
      
        //isEnd(holder);
       // printf("%c\n", contents);

    //if comment ignore until \n
     isBegin(holder) ;
      if(strcmp(holder, "begin") == 0)
            {
                memset(holder, 0, strlen(holder));
            }

      

        if (def == OP || def == EQ  || def == SEMICOLON || def == END || def == LEFT_PAR|| def == RIGHT_PAR) {
            //printf("hi\n");
            // 

        //if(strcmp(holder, "begin") ==0)
            //lastDef = def;

            if(def == EQ)
            {
                statementTable->eqCounter++;
            }

            if(def == LEFT_PAR)
            {
                statementTable->leftParCounter++;
            }

            if(def == RIGHT_PAR)
            {
                statementTable->rightParCounter++;
            }

            //means statement has ended check the EQ and PAR comparisons for the statement 
            if(def == SEMICOLON)
            {
                if(statementTable->eqCounter > 1)
                {
                    //CALL ERROR DEFINE LINE TOOD
                    printf("failed\n");
                }

                if(statementTable->leftParCounter != statementTable->rightParCounter)
                {
                    //CALL ERROR TODO
                    printf("failed\n");
                }

                //flush contents and restart 
                statementTable->eqCounter =0;
                statementTable->leftParCounter =0;
                statementTable->rightParCounter =0;
            }

           

            //printf("|%s|\n",holder);
            if(syntaxChecker(holder))
            {
                inputInSymbolTable(holder);
               
            }
            else 
            {
                //TODO ERROR
            }


           
/*
             for(int i=0; i < TableSize; i++)
             {
                 if(railRoad[i].secondState == -1)
                 {
                     railRoad[i].firstState = checker;
                     railRoad[i].secondState = def;
                     railRoad[i].currentLine = linecount;
                     break;
                 }
                 else
                 {
                    railRoad[i].firstState = railRoad[i-1].secondState;
                    if(strcmp(holder, "") ==0)
                    {
                        railRoad[i].secondState = def;
                    }
                    else railRoad[i].secondState = checker;

                    break;

                 }
             
             }

               */
                
            for(int i=0; i < TableSize; i++)
            {
                if(TraceOn[i].statement == -1)
                {
                     if(strcmp(holder, "") != "")
                    {
                        int checker = IDorNum(holder);
                        

                        if(checker != ERROR)
                        {
                            
                          //  printf("%d\n", checker);
                            TraceOn[i].statement = checker;
                            TraceOn[i].currentLine = linecount;
                            

                        }
                       // printf("%d inside\n", def);
                        for(int j =0; j < TableSize; j++)
                        {
                            if(TraceOn[j].statement == -1)
                            {
                                TraceOn[j].statement = def;
                                TraceOn[j].currentLine = linecount;
                                break;
                            }
                        }
                            
                        
                        
                    }
                    //printf("%d\n", def);
                    //TraceOn[i].statement = def;    
                    

                    //TraceOn[i].statement = def;
                    break;
                }
            }
               
                
               // 
                
                /*
                    if(backTrace->secondState == 0)
                    {
                        backTrace->firstState =checker;
                        backTrace->secondState = def;
                        backTrace->currentLine = linecount;
                        printf("%d\n", backTrace->firstState);
                        printf("%d\n", backTrace->secondState);
                        printf("%s\n", holder);

                        match();
                    }
                    else 
                    {
                        backTrace->firstState = backTrace->secondState;
                        
                        if(strcmp(holder, "") ==0)
                        {
                            backTrace->secondState = def;
                        }
                        else backTrace->secondState = checker;
                        printf("%d\n", backTrace->firstState);
                        printf("%d\n", backTrace->secondState);
                        printf("%s\n", holder);

                        match();
                    }
*/
                   /* if(IDhit)
                    {
                        printf("hit ID");
                    }
                    else printf("hit OP");
                    */
                   
            //  //  */


            //predict 


          /*  if(eachParsedStatement[0] != -1)
            {
                for(int i=0; i < TableSize; i++)
                {
                    prediction(eachParsedStatement[i])
                }
            }*/
            

            //placeInParsedArray(def);



        if(hasBegin)
        {
            /*if(match(def) == ERROR) 
            {
                //printf("%c", contents);
                printf("%s\n", expecting );
                
            }*/
            if(def != SEMICOLON)
            {
                //printf("%d\n", lastDef);
                //prediction(def);
                
             

            }
        }

            //placing inside symbolTable

            
            memset(holder, 0, strlen(holder));
            IDhit = false;


        } 
        else if (def == ID || def == NUM || def == END) {
            //printf("%s\n", holder);
            isEnd(holder);
            //lastDef = def;
                    
        
            if(contents != 32 && contents != '\n')
            {
                strncat(holder, &contents, 1);
            }
            IDhit = true;
        }

        if(def == END)
        {
            //printf("getting to end");
        }



        lastDef = def;


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
     printf("-----------------------------\n");

                for(int i=0; i < TableSize; i++)
                {
                    if(TraceOn[i].statement != -1)
                    {
                        
                        
                       printf("%d\n",  TraceOn[i].statement);
                       //printf("%d\n",  TraceOn[i].currentLine);
                            //printf("here");
                        
                    }
                }

                match();



    /*  while(fgets (contents, 50, file) != NULL)
      {
         // printf("%s", contents);
      }
      */

                       

     
    fclose(file);

/*
    for(int i=0; i< TableSize; i++)
    {
        if(railRoad[i].secondState != -1)
        {
            printf("%d\n", railRoad[i].firstState);
            printf("%d\n", railRoad[i].secondState);            
        }
        else break;
    }*/
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
                //printf("copy\n");
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
                    //printf("placed\n");
                    return true;
                }
            }
        }
        else return false;

    }
}

void prediction(int def)
{

    //flush last lookAhead 
    for(int i=0; i < TableSize; i++)
    {
        lookAhead[i] = -1;
    }

    if(def == ID)
    {
     
        
            lookAhead[0] = EQ;
            lookAhead[1] = OP;
            lookAhead[2] = LEFT_PAR;
            lookAhead[3] = RIGHT_PAR;
            lookAhead[4] = SEMICOLON;
           // printf("1\n");
        
    }

    if(def == NUM)
    {
        lookAhead[0] = OP;
        lookAhead[1] = LEFT_PAR;
        lookAhead[2] = RIGHT_PAR;
        lookAhead[3] = SEMICOLON;
    }

    if(def == OP)
    {
        lookAhead[0] = ID;
        lookAhead[1] = NUM;
        lookAhead[2] = LEFT_PAR;
        lookAhead[3] = SEMICOLON;
    }

    if(def == EQ)
    {
        lookAhead[0] = ID;
        lookAhead[1] = NUM;
        lookAhead[2] = LEFT_PAR;
    }

    if(def == LEFT_PAR)
    {
        lookAhead[0] = ID;
        lookAhead[1] = NUM;
    }

    if(def == RIGHT_PAR)
    {
        lookAhead[0] = OP;
        lookAhead[1] = SEMICOLON;
    }

    if(def == SEMICOLON)
    {
        lookAhead[0] = ID;
    }

   // printf("Choice1: %d\n", lookAhead[0]);
   // printf("Choice2: %d\n", lookAhead[1]);
   // printf("Choice3: %d\n", lookAhead[2]);

}

void match()
{

    
    for(int i=0; i < TableSize; i++)
    {
        bool found = false;
        if(TraceOn[i].statement != -1)
        {
            prediction(TraceOn[i].statement);

            int j=0;
            while(lookAhead[j] != -1)
            {
                if(lookAhead[j] == TraceOn[i+1].statement)
                {
                    printf("match found: %d AND %d \n", TraceOn[i].statement, TraceOn[i+1].statement);
                    found = true;
                    break;
                }
                j++;
            }
            if(TraceOn[i+1].statement != -1)
            {
                if(!found) printf("error %d %d \n", TraceOn[i+1].statement, TraceOn[i].currentLine);
            }
        }
        
    }

    
    //prediction();
}


int IDorNum(char input[])
{
     if(isdigit(input[0]))
   {
       return NUM;
   }
   else if(isalpha(input[0])) 
    {
        return ID;
    }
    return ERROR;

}
