//exam_logic.h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include "result_show.h"

void exam_logic() {
    int numberOfOptions = 4, numberOfQuestions = 4;
    char questions[numberOfQuestions][100];
    char options[numberOfQuestions][numberOfOptions][100];
    char answer[numberOfQuestions][10];
    char userInput[numberOfQuestions][10];
    FILE *fp;

    fp = fopen("try_final.txt", "r");

    for (int i = 0; i < numberOfQuestions; i++) 
    {
        fscanf(fp, "%99[^\n]%*c", questions[i]);
        printf("\n%s\n", questions[i]);

        for (int j = 0; j < numberOfOptions; j++) 
        {
            fscanf(fp, "%99[^\n]%*c", options[i][j]);
            printf("%s\n", options[i][j]);
        }

        fscanf(fp, "answer:%s\n", answer[i]);

    // Inside the for-loop for user input

    printf("Enter your answer for question %d: ", i + 1);
    fgets(userInput[i], sizeof(userInput[i]), stdin);

// Remove newline from userInpu
    userInput[i][strcspn(userInput[i], "\n")] = '\0';
}
    fclose(fp);
    result(numberOfQuestions,userInput,answer);
}
