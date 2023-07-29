/*result_show.h
RESULT DISPLAY AND COMPARE LOGIC
----------------------------------------------------
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void result(int numberOfQuestions, char userInput[][10], char answer[][10], char name[], char school[]);


void result(int numberOfQuestions, char userInput[][10], char answer[][10], char name[], char school[])
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
            //sub the score if you want to
        }
    }
    system("cls");
    printf("Your score: %d/%d\nname:%s\nschool:%s", score, numberOfQuestions, name, school);
    getchar();
}

