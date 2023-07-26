//main.c

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include"exam_logic.h"

void main()
{
	int choose;
	printf("Choose the following");
	printf("\nPress 1 to take exam");
	printf("\nPress 2 to know about program");
	printf("\nPress 3 to exit\n:");
	scanf("%d", &choose);
	getchar(); 
	switch(choose)
	{
	case 1:
		system("cls");
		exam_logic();
		break;
	case 2:
		system("cls");
		printf("Made by Samip Regmi for the final year project of class 12 \nSamip Regmi\nClass 11:pascal\nClass 12:euclid\n\n");
		sleep(2);
		main();
		break;

	case 3:
		exit(0);
		break;

	default :
		printf("The Option is not available\n");
		sleep(2);
		system("cls");

		main();
		break;
	}


}