/* result_show.h
   RESULT DISPLAY AND COMPARE LOGIC
   ----------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

void saveAnswer(int numberOfQuestions, char userInput[][10]);

void saveAnswer(int numberOfQuestions, char userInput[][10])
{
    FILE *fp1;
    fp1 = fopen("../src/answer.txt", "w");
    
    if (fp1 == NULL)
    {
        printf("fail\n");
    }

    for (int i = 0; i < numberOfQuestions; i++)
    {
        fprintf(fp1, "%s\n", userInput[i]);
    }

    fclose(fp1);
}
