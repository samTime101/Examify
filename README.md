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
