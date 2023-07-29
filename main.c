#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "exam_logic.h"
// #include "./textinc.h"

void admin();
/*
DECLARING A DEFAULT NUMBER OF QUESTIONS
THE DEFAULT NUMBER OF QUESTIONS IS 4
---------------------------------------
*/
int numberOfQuestions = 5;


void main()
{
    // if (SetConsoleFontSize(24))
    // {
     	int choose;
        char name[20], school[40], user_pass[10], pass[10] = "admin";

        printf("Choose the following");
        printf("\nPress 1 to take exam");
        printf("\nPress 2 to know about program");
        printf("\nPress 3 to Admin Panel");
        printf("\nPress 4 to exit\n:");
        scanf("%d", &choose);
        getchar();
        switch (choose)
        {
        case 1:
            system("cls");
            printf("Enter name:");
            fgets(name, sizeof(name), stdin);
            printf("\nEnter School:");
            fgets(school, sizeof(school), stdin);
            if (*name != '\n' && *school != '\n')
            {
/*
PASSING NUMBER OF QUESTIONS TO EXAM LOGIC FUNCTION
IF NOT SPECIFIED BY ADMIN , DEFAULT VALUE WILL BE GONE i.e. 4
*/
                exam_logic(name, school, numberOfQuestions); 
            }
            else
            {
                printf("Wrong Entry 101!\n");
                sleep(2);
                system("cls");
                main();
            }
            break;

        case 2:
            system("cls");
            printf("Made by Samip Regmi for the final year project of class 12 \nSamip Regmi\nClass 11:pascal\nClass 12:euclid\n\n");
            sleep(2);
            main();
            break;

        case 3:
            printf("Enter password:");
            fgets(user_pass, sizeof(user_pass), stdin);

/*REMOVE THE WHITE SPACE FOR COMPARE
------------------------------------------------------------------------
*/
            user_pass[strcspn(user_pass, "\n")] = '\0'; 
            if (strcmp(user_pass, pass) == 0)
            {
                admin();
            }
            else
            {
                system("cls");
                main();
            }
            break;

        case 4:
            exit(0);
            break;

       
/*
MAKING SURE NO PRESENCE OF WHITE SPACE
-------------------------------------------------
*/
        default:
            while (getchar() != '\n');
            system("cls");
            main();
            break;
        }
    }
// }

/*
ADMIN PANEL TO ADD NUMBER OF QUESTIONS AND OTHER ADMIN PROPERTIES
------------------------------------------------------------
*/


void admin()
{
    int choose;
    system("cls");
    printf("Hello from admin\n");
    printf("Press 1 to setup questions\n:");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        printf("Enter number of questions:");
		  if(scanf("%d", &numberOfQuestions)==1)
		  {
        system("cls");
        main(); 
        break;
     }
     else{
     	   printf("Invalid choice, returning to main menu.\n");
        sleep(3);
        system("cls");
        main();
     }
    default:
        printf("Invalid choice, returning to main menu.\n");
        sleep(3);
        system("cls");
        main();
        break;
    }
}
