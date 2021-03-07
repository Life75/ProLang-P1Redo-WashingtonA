#include "parser.h"

bool hasEnd = false;
bool hasBegin = false;
bool intTag = false;
int lookAhead[TableSize];
struct SymbolTable symbolTable[TableSize];
struct StatementTable statementTable[TableSize];
struct TraceOn TraceOn[TableSize];



int parser(char fileName[]) {

    //init arrays and values 
    for (int i = 0; i < TableSize; i++) {
        symbolTable->IDs[i] = "";
        symbolTable->intFlag = false;
        symbolTable->currentLine = -1;
    }

    for (int i = 0; i < TableSize; i++) {
        lookAhead[i] = -1;
    }

    for (int i = 0; i < TableSize; i++) {
        TraceOn[i].statement = -1;
        TraceOn[i].currentLine = -1;
    }


    statementTable->eqCounter = 0;
    statementTable->leftParCounter = 0;
    statementTable->rightParCounter = 0;

    FILE * file;
    char contents;
    file = fopen(fileName, "r");


    if (file == NULL) {
        printf("opening file error: %s", fileName);
        return ERROR;
    }

    int linecount = 1;
    int def = 0;
    char holder[100] = "";
    int lookAhead = 0;
    memset(holder, 0, strlen(holder));


    while (1) {



        contents = fgetc(file);


        def = lexicon(contents);



        //if comment ignore until \n
        if (def == COMMENT) {
            //printf("comment here skip line\n");
            while (contents != '\n') {
                contents = fgetc(file);

            }
        }
        isBegin(holder);
        if (strcmp(holder, "begin") == 0) {
            memset(holder, 0, strlen(holder));
        }



        if (def == OP || def == EQ || def == SEMICOLON || def == END || def == LEFT_PAR || def == RIGHT_PAR || def == COMMA) {

            if (!hasBegin) {
                printf("Line: %d error message: No 'begin'.\n", linecount);
                return ERROR;
            }


            if (syntaxChecker(holder)) {
            	if(!checkIfIntTag(holder))
            	{
           	    	if(!inputInSymbolTable(holder, linecount)) //TODO ADD ERROR CHECKING AT THE END TO CHECK IF INIT 
           	    	{
           	    		printf("Line: %d, error '%s' not initalized\n",linecount,holder);
           	    		//return ERROR;
           	    	}
            	} 
            } else {
                if (strcmp(holder, "") != 0) {
                    printf("Line: %d, syntax error:  %s\n", linecount, holder);
                    return ERROR;
                }
            }



            if (def == EQ) {
                statementTable -> eqCounter++;
            }

            if (def == LEFT_PAR) {
                statementTable -> leftParCounter++;
            }

            if (def == RIGHT_PAR) {
                statementTable -> rightParCounter++;
            }

            //means statement has ended check the EQ and PAR comparisons for the statement 
            if (def == SEMICOLON) {
            	intTag = false; //reset tag
                if (statementTable -> eqCounter > 1) {
                    //CALL ERROR DEFINE
                    printf("More than '1' '=' in given statement\n");
                    return ERROR;
                }

                if (statementTable -> leftParCounter != statementTable -> rightParCounter) {
                    //CALL ERROR 
                    if (statementTable -> leftParCounter > statementTable -> rightParCounter) {
                        printf("Line: %d. Missing Expecting ')' \n", linecount);
                    } else {
                        printf("Line: %d. Missing Expecting '(' \n", linecount);
                    }
                    return ERROR;
                }
                //Add commas to be valid for being next to <ID> Check if the holder is == to int, if so initalize a bool value true until it gets to the end and every ID recorded is flag with an INT flag 
                //flush contents and restart 
                statementTable -> eqCounter = 0;
                statementTable -> leftParCounter = 0;
                statementTable -> rightParCounter = 0;
            }
               
            
            


            for (int i = 0; i < TableSize; i++) {
                if (TraceOn[i].statement == -1) {
                    if (strcmp(holder, "") != "") {
                        int checker = IDorNum(holder);


                        if (checker != ERROR) {

                            TraceOn[i].statement = checker;
                            TraceOn[i].currentLine = linecount;


                        }
                        for (int j = 0; j < TableSize; j++) {
                            if (TraceOn[j].statement == -1) {
                                TraceOn[j].statement = def;
                                TraceOn[j].currentLine = linecount;
                                break;
                            }
                        }


                    }

                    break;
                }
            }
            memset(holder, 0, strlen(holder));



        } else if (def == ID || def == NUM || def == END) {

            isEnd(holder);
            
            


            if (contents != 32 && contents != '\n') {
                strncat(holder, & contents, 1);
            }

        }
        else if (def == SPACE)
        {
        	if(checkIfIntTag(holder))
            {
            	intTag = true;
            	//printf("heyo %s \n",holder);
            	memset(holder, 0, strlen(holder));
            }
        }

        if (contents == '\n') {
            linecount++;
        }

        if (contents == EOF) {
            isEnd(holder);
            if (!hasEnd) {
                printf("Error message: Missing 'end.'\n");
                return ERROR;
            }
            break;

        }

    }
    if (!match()) return ERROR;

    fclose(file);

    if (hasBegin && hasEnd) {
        printf("Identifier Table:\n");
        for (int i = 1; i < TableSize; i++) {
            if (strcmp(symbolTable[i].IDs, "") != 0) {
                printf("ID #%d: %s INT FLAG:%d \n", i, symbolTable[i].IDs, symbolTable[i].intFlag);
            }
        }
        return PASS;
    }
}

bool syntaxChecker(char input[]) {

    int length = strlen(input);

    if (isdigit(input[0])) {
        for (int i = 0; i < length; i++) {
            if (!isdigit(input[i])) return false;
        }
        return true;
    }

    if (isalpha(input[0])) {
        char behind = "";

        for (int i = 0; i < length; i++) {
            if (input[i] == 95) {
                if (input[i - 1] == 95) {
                    return false; //2 underscores consecutive
                }
            }
            //doesnt end with underscore
            if (i == length - 1) {
                if (input[i] == 95) {
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
        hasBegin = true;
        return true;
    }
    return false;
}

bool isEnd(char input[]) {
    char end[] = "end.";

    if (strcmp(input, end) == 0) {
        hasEnd = true;
        return true;
    }
    return false;
}


bool inputInSymbolTable(char input[], int currentLine) {
    //check if its in already, if not then input return true, if it is then return false 
    bool copyFound = false;
    if (isalpha(input[0])) {
        for (int i = 0; i < TableSize; i++) {
            if (strcmp(input, symbolTable[i].IDs) == 0) {
                copyFound = true;
            }
        }
        if (!copyFound) {
            for (int i = 0; i < TableSize; i++) {
                if (strcmp("", symbolTable[i].IDs) == 0) {
                    strcpy(symbolTable[i].IDs, input);
                    if(intTag)
                    {
                    	symbolTable[i].intFlag = true;
                    	symbolTable[i].currentLine = currentLine;
                    	printf("%s input in table\n", input);

                    }
                    return true;
                }
            }
        } else return true;

    }
}

bool checkIfIntTag(char input[]) {
	if(strcmp("int", input) == 0)
		return true;
	return false;
}

void prediction(int def) {

    //flush last lookAhead 
    for (int i = 0; i < TableSize; i++) {
        lookAhead[i] = -1;
    }

      if(def == COMMA){
    	lookAhead[0] = ID;
    }

    if (def == ID) {


        lookAhead[0] = EQ;
        lookAhead[1] = OP;
        lookAhead[2] = RIGHT_PAR;
        lookAhead[3] = SEMICOLON;
        lookAhead[4] = COMMA;
    }

    if (def == NUM) {
        lookAhead[0] = OP;
        lookAhead[1] = LEFT_PAR;
        lookAhead[2] = RIGHT_PAR;
        lookAhead[3] = SEMICOLON;
    }

    if (def == OP) {
        lookAhead[0] = ID;
        lookAhead[1] = NUM;
        lookAhead[2] = LEFT_PAR;
        lookAhead[3] = SEMICOLON;
    }

    if (def == EQ) {
        lookAhead[0] = ID;
        lookAhead[1] = NUM;
        lookAhead[2] = LEFT_PAR;
    }

    if (def == LEFT_PAR) {
        lookAhead[0] = ID;
        lookAhead[1] = NUM;
        lookAhead[2] = LEFT_PAR;
    }

    if (def == RIGHT_PAR) {
        lookAhead[0] = OP;
        lookAhead[1] = SEMICOLON;
        lookAhead[2] = RIGHT_PAR;
    }



    if (def == SEMICOLON) {
        lookAhead[0] = ID;
    }

    

}

bool match() {
    for (int i = 0; i < TableSize; i++) {
        bool found = false;
        if (TraceOn[i].statement != -1) {
            prediction(TraceOn[i].statement);

            int j = 0;
            while (lookAhead[j] != -1) {
                if (lookAhead[j] == TraceOn[i + 1].statement) {
                    found = true;
                    break;
                }
                j++;
            }
            if (TraceOn[i + 1].statement != -1) {
                if (!found) {
                    int received = TraceOn[i + 1].statement;
                    int beforeStatement = TraceOn[i].statement;

                    prediction(beforeStatement);

                    if (received != SEMICOLON) {
                        char word[50];
                        strcpy(word, translator(received));
                        printf("Line: %d, contains error Received: '%s' ", TraceOn[i].currentLine, word);

                        for (int i = 0; i < TableSize; i++) {
                            if (lookAhead[i] != -1) {
                                printf("Expected:  '%s' ", translator(lookAhead[i]));
                            }

                        }
                        printf("\n");
                        return false;
                    }
                }

            }
        }
    }
    return true;
}


int IDorNum(char input[]) {
    if (isdigit(input[0])) {
        return NUM;
    } else if (isalpha(input[0])) {
        return ID;
    }
    return ERROR;

}