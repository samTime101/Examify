//result_show.h

#include <stdio.h>
#include <string.h>
void result(int numberOfQuestions, char userInput[][10],char answer[][10])
{
    int score = 0;
    for (int i = 0; i < numberOfQuestions; i++) {
        if (strcasecmp(userInput[i], answer[i]) == 0) {
            score++;
        }
        else{
            //sub the score if you want to
        }
    }
    printf("Your score: %d/%d\n", score, numberOfQuestions);
    getchar();
}
