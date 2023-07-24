#include <stdio.h>
#include<string.h>

void result(int);

int main() {
    FILE *fp;
    char line[50];
    char answer[50];
    int marks=0;

    fp = fopen("main.txt", "r");

    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    //question
    if (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    } 
    else{
        printf("error");
    }
//A
    if (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    } 
    else{
        printf("error");
    }  
    //B
      if (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    } 
    else{
        printf("error");
    }  
    //C
      if (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    } 
    else{
        printf("error");
    }
    //D
        if (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    } 
    else{
        printf("error");
    }
    fscanf(fp,"answer:%s",line);

    scanf("%[^\n]",answer);
        if(strcasecmp(line,answer)==0)
        {
            result(marks);
        }
        else
        {
            printf("incorrect");
        }
    fclose(fp);
    return 0;
}
void  result(int marks)
{
    printf("correct");
    marks++;
    printf("\n****Result****");
    printf("\nYour marks:%d",marks);
}

