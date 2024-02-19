/*result_show.h
RESULT DISPLAY AND COMPARE LOGIC
----------------------------------------------------
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "./pdf.h"
#include "./result.h" 

void result(int numberOfQuestions, char userInput[][10], char answer[][10], char name[], char school[],char path[]);

void result(int numberOfQuestions, char userInput[][10], char answer[][10], char name[], char school[],char path[])
{
    int score = 0;
    for (int i = 0; i < numberOfQuestions; i++)
    {
        if (strcasecmp(userInput[i], answer[i]) == 0)
        {
            score++;
        }
        else
        {
            // WE CAN SUBTRACT THE SCORE
        }
    }
    system("cls || clear");
    printf("Your score: %d/%d\nname:%s\nschool:%s", score, numberOfQuestions, name, school);
    pdf(name,school,score,numberOfQuestions,path);
    getchar();

}

