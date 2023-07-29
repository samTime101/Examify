/*exam_logic.h
*HEADER FILE WIRTTEN BY SAMTIME101
*https://samiptime101.web.app
*exam logic should be included to the main program to read the questions and print them
--------------------------------------------------------
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "result_show.h"

void exam_logic(char name[], char school[], int numberOfQuestions);


void exam_logic(char name[], char school[], int numberOfQuestions)
{


    int numberOfOptions = 4;
    char questions[numberOfQuestions][300];
    char options[numberOfQuestions][numberOfOptions][300];
    char answer[numberOfQuestions][10];
    char userInput[numberOfQuestions][10];
    FILE *fp;

    fp =  fopen("E:\\\\newProject\\\\try_final.txt", "r");

    for (int i = 0; i < numberOfQuestions; i++)
    {
        fscanf(fp, "%299[^\n]%*c", questions[i]);
        printf("\n%s\n", questions[i]);

        for (int j = 0; j < numberOfOptions; j++)
        {
            fscanf(fp, "%299[^\n]%*c", options[i][j]);
            printf("%s\n", options[i][j]);
        }

        fscanf(fp, "answer:%s\n", answer[i]);

        /* ACCESSING AND STORING USER INPUT WITH LOOP

        DISCARDED PRINTF

        printf("Enter your answer for question %d: ", i + 1);
        ----------------------------------------------------------------
        */
        printf("Enter answer : ");
        fgets(userInput[i], sizeof(userInput[i]), stdin);

        /*
        REMOVING WHITE SPACE FROM USER INPUT
        ------------------------------------------------------------
        */
        userInput[i][strcspn(userInput[i], "\n")] = '\0';
    }
    fclose(fp);
    result(numberOfQuestions, userInput, answer, name, school);
}
