/* exam_logic.h
* HEADER FILE WRITTEN BY SAMIP REGMI
*TIME101
* https://samiptime101.web.app
* exam logic should be included in the main program to read the questions and print them
--------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../header/result_show.h"
#include "../header/saveAnswer.h"

void exam_logic(char name[], char school[], int numberOfQuestions, char path[]);

void exam_logic(char name[], char school[], int numberOfQuestions, char path[])
{
    int numberOfOptions = 4;
    char questions[numberOfQuestions][300];
    char options[numberOfQuestions][numberOfOptions][300];
    char answer[numberOfQuestions][10];
    char userInput[numberOfQuestions][10];
    FILE *fp;

    fp = fopen(path, "r");

    for (int i = 0; i < numberOfQuestions; i++)
    {
        // QUESTION
        printf("\n%s", fgets(questions[i], sizeof(questions[i]), fp));

        for (int j = 0; j < numberOfOptions; j++)
        {
//OPTIONS
            fscanf(fp, "%299[^\n]%*c", options[i][j]);
            printf("%s\n", options[i][j]);
        }
//ANSWER
        fscanf(fp, "answer:%s\n", answer[i]);

        printf("Enter answer : ");
        fgets(userInput[i], sizeof(userInput[i]), stdin);

        userInput[i][strcspn(userInput[i], "\n")] = '\0';
    }
    fclose(fp);
    saveAnswer(numberOfQuestions, userInput);

    result(numberOfQuestions, userInput, answer, name, school, path);
}
