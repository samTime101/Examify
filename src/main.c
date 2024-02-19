#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./exam_logic.h"

void admin();
/*
DECLARING A DEFAULT NUMBER OF QUESTIONS
THE DEFAULT NUMBER OF QUESTIONS IS 3
WE CAN CHANGE AS ADMIN TO OUR PREFERRED 
NUMBER OF QUESTIONS.
---------------------------------------
*/
int numberOfQuestions = 3;
char path[45] = "main.txt";

void main()
{
     	int choose;
        char name[20], school[40], user_pass[10], pass[10] = "admin";
        printf("****EXAMIFY-updated on magh 10 2080****");
        printf("\nDEFAULT QUESTIONS SET : %d",numberOfQuestions);
        printf("\nDefault file path : %s",path);
        printf("\n************************************");
        printf("\n");
        printf("\nChoose the following");
        printf("\nPress 1 to take exam");
        printf("\nPress 2 to know about program");
        printf("\nPress 3 to Admin Panel");
        printf("\nPress 4 to exit\n:");
        scanf("%d", &choose);
        getchar();
        switch (choose)
        {
        case 1:
            system("cls || clear");
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
                exam_logic(name, school, numberOfQuestions,path); 
            }
            else
            {
                printf("Wrong Entry 101!\n");
                sleep(2);
                system("cls || clear");
                main();
            }
            break;

        case 2:
            system("cls || clear");
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
                system("cls || clear");
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
            system("cls ||clear");
            main();
            break;
        }
    }
// }

/*
ADMIN PANEL TO ADD NUMBER OF QUESTIONS AND OTHER ADMIN PROPERTIES
------------------------------------------------------------
*/

/* UPDATED ADMIN FUNCTION
ADDED || clear for both linux and windows system
*/ 
void admin()
{
    int choose;
    system("cls || clear");
    printf("Hello from admin\n");
    printf("\nPress 1 to setup questions and 2 to change file path:");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        printf("Enter number of questions:");
        if(scanf("%d", &numberOfQuestions)==1)
        {
            system("cls || clear");
            main(); 
            break;
        }
        else
        {
            printf("Invalid choice, returning to main menu.\n");
            sleep(3);
            system("cls || clear");
            main();
        }    
    case 2:
        printf("Enter the file path:");
//REMOVE THE NEW LINE 
while(getchar() != '\n'); 
// READING ONLY 15 NOT NEW LINE

    if (scanf("%15[^\n]", path) == 1) {
        while (getchar() != '\n'); 
            printf("Number of Questions in %s ?:",path);
                if(scanf("%d", &numberOfQuestions)==1)
                    {
                        system("cls || clear");
                        main(); 
                        break;

                        }
                else
                {
                    printf("Invalid choice, returning to main menu.\n");
                    sleep(3);
                    system("cls || clear");
                    main();
                }          // system("cls || clear");

                    // main(); 
                    break;
        }
        else
        {
            printf("Invalid choice, returning to main menu.\n");
            sleep(3);
            system("cls || clear");
            main();
        }


    default:
        printf("Invalid choice, returning to main menu.\n");
        sleep(3);
        system("cls || clear");
        main();
        break;
    }
}
