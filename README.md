# Examify
Just trying different funtions and experimenting
# References
https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
# Basic Principles
# 1.c
```c
#include <stdio.h>
void main()
{
    int numberOfOptions = 4;
    char questions[100];
    char options[numberOfOptions][100];
    FILE*fp;

    fp = fopen("main.txt", "r");
    fscanf(fp, "%99[^\n]%*c", questions); 
    printf("%s\n", questions);

    for (int i = 0; i < numberOfOptions; i++) 
    {
        fscanf(fp, "%99[^\n]%*c", options[i]); 
        printf("%s\n", options[i]);
    }

    fclose(fp);
}
```
# main.txt
```txt
q1
1:o1
2:o2
3:o3
4:o4
```
# 2.c
```c
#include <stdio.h>
void main()
{
    int numberOfOptions = 4,numberOfQuestions = 2;
    char questions[numberOfQuestions][100];
    char options[numberOfOptions][100];
    FILE*fp;

    fp = fopen("main.txt", "r");
        
    for (int i = 0; i < numberOfQuestions; i++) 
    {
    fscanf(fp, "%99[^\n]%*c", questions[i]); 
    printf("%s\n", questions[i]);

    for (int i = 0; i < numberOfOptions; i++) 
    {
    fscanf(fp, "%99[^\n]%*c", options[i]); 
    printf("%s\n", options[i]);
    }
}
fclose(fp);
}
```
# main.txt
```txt
q1
1:o11
2:o12
3:o13
4:o14
q2
1:o21
2:o22
3:o23
4:o24
```
# 3.c
```c
#include <stdio.h>
void main()
{
    int numberOfOptions = 4,numberOfQuestions = 3;
    char questions[numberOfQuestions][100];
    char options[numberOfOptions][100];
    char answer [numberOfQuestions][100];
    FILE*fp;

    fp = fopen("main.txt", "r");
        
    for (int i = 0; i < numberOfQuestions; i++) 
    {
    fscanf(fp, "\n%99[^\n]%*c", questions[i]); 
    printf("%s\n", questions[i]);
    fscanf(fp, "\n%99[^\n]%*c", answer[i]); 
    printf("%s\n", answer[i]);

    for (int j = 0; j < numberOfOptions; j++) 
    {
    fscanf(fp, "%99[^\n]%*c", options[j]); 
    printf("%s\n", options[j]);
    }

}
fclose(fp);
}
```
# main.txt
```txt
q1
1:o11
2:o12
3:o13
4:o14
answer:1

q2
1:o21
2:o22
3:o23
4:o24
answer:2

q3
1:o31
2:o32
3:o33
4:o34
answer:3
```
# 4.c
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    int numberOfOptions = 4, numberOfQuestions = 2;
    char questions[numberOfQuestions][100];
    char options[numberOfQuestions][numberOfOptions][100];
    char answer[numberOfQuestions][10];
    char userInput[numberOfQuestions][10];
    FILE *fp;

    fp = fopen("try_final.txt", "r");

    for (int i = 0; i < numberOfQuestions; i++) 
    {
        fscanf(fp, "%99[^\n]%*c", questions[i]);
        printf("%s\n", questions[i]);

        for (int j = 0; j < numberOfOptions; j++) 
        {
            fscanf(fp, "%99[^\n]%*c", options[i][j]);
            printf("%s\n", options[i][j]);
        }

        fscanf(fp, "answer:%s\n", answer[i]);

    // Inside the for-loop for user input
printf("Enter your answer for question %d: ", i + 1);
fgets(userInput[i], sizeof(userInput[i]), stdin);

// Remove trailing newline from userInput[i]
userInput[i][strcspn(userInput[i], "\n")] = '\0';
}

    fclose(fp);

    int score = 0;
    for (int i = 0; i < numberOfQuestions; i++) {
        if (strcasecmp(userInput[i], answer[i]) == 0) {
            score++;
        }
        else{
            printf("%s\n",answer[i]);
        }
    }

    printf("Your score: %d/%d\n", score, numberOfQuestions);


}
```
# main.txt
```txt
What is the capital city of nepal?
A:Kathmandu
B:London
C:Washington
D:Berlin
answer:A

What is national weapon of Nepal?
A:Sword
B:Khukuri
C:Gun
D:knife
answer:B
```
