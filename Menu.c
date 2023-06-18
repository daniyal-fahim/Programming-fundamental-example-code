#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>


struct daniyal_airline
{
	char passport[6];
	char name[15];
    char destination[15];
	int seat_num;
	char email[15];
	struct daniyal_airline *following;
}
*begin, *river;
struct daniyal_airline *dummy;


void main()
{
	system("COLOR fc");
	void reserve(int x), cancel(), display(), savefile();  //function prototypes
	int choice;
	begin = river = NULL;  //initialize the struct pointers to NULL
	int num = 1;
	do
	{

		printf("\n\n ********************************************************************");
		printf("\n                   welcome to AIRBLUE airline system                   ");
		printf("\n  *******************************************************************");
		printf("\n\n\n\t\t Please enter your choice from below (1-4):");
		printf("\n\n\t\t 1. Reservation");
		printf("\n\n\t\t 2. Cancel");
		printf("\n\n\t\t 3. DISPLAY RECORDS");
		printf("\n\n\t\t 4. EXIT");
		printf("\n\n\t\t feel free to contact ");
		printf("\n\n\t\t Enter your choice :");



		scanf("%d", &choice); fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			cancel();
			break;
		case 3:
			display();
			break;
		case 4:
		{
				  savefile();
				  break;
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-4");
			printf("\n\n\t Do not forget to chose from 1-4");
		}
		getch();
	} while (choice != 4);
}
// ************************GOOD LUCK daniyal*****************************
void details()
{
	printf("\n\t Enter your passport number:");
	gets(river->passport); fflush(stdin);   //reads a line from stdin and stores it into the string pointed
	printf("\n\t Enter your  name:");
	gets(river->name); fflush(stdin);
	printf("\n\t Enter your email address:");
	gets(river->email); fflush(stdin);
    printf("\n\t Enter the Destination : ");
    gets(river->destination); fflush(stdin);
}


// ************************************GOOD LUCK daniyal************************************
void details();

void reserve(int x)
{
	river = begin;
	if (begin == NULL)
	{
		// first user
		begin = river = (struct daniyal_airline*)malloc(sizeof(struct daniyal_airline));
		details();
		river->following = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t your seat number is: Seat A-%d", x);
		river->seat_num = x;
		return;
	}
	else if (x > 15) // FULL SEATS
	{
		printf("\n\t\t Seat Full.");
		return;
	}
	else
	{
		// next user
		while (river->following)
			river = river->following;
		river->following = (struct daniyal_airline *)malloc(sizeof(struct daniyal_airline));
		river = river->following;
		details();
		river->following = NULL;
		printf("\n\t Seat booking succesful!");
		printf("\n\t your seat number is: Seat A-%d", x);
		river->seat_num = x;
		return;
	}
}
// ************************GOOD LUCK daniyal********************************


void savefile()
{
	FILE *fpointer = fopen("daniyal records", "w");
	if (!fpointer)
	{
		printf("\n Error in opening file!");
		return;
		Sleep(800);
	}
	river = begin;
	while (river)
	{
		fprintf(fpointer, "%-6s", river->passport);
		fprintf(fpointer, "%-15s", river->name);
		fprintf(fpointer, "%-15s", river->email);
        fprintf(fpointer, "%-15s", river->destination);
        fprintf(fpointer, "\n");
		river = river->following;
	}
	printf("\n\n\t Details have been saved to a file (daniyal records)");
	fclose(fpointer);
}
//********************************GOOD LUCK daniyal***************************************

void display()
{
	river = begin;
	while (river)
	{
		printf("\n\n Passport Number : %-6s", river->passport);
		printf("\n         name : %-15s", river->name);
		printf("\n      email address: %-15s", river->email);
		printf("\n      Seat number: A-%d", river->seat_num);
        printf("\n     Destination:%-15s", river->destination);
		printf("\n\n++*=====================================================*++");
		river = river->following;
	}

}
//*****************************GOOD LUCK daniyal*************************************

void cancel()
{
	river = begin;
	system("cls");
	char passport[6];
	printf("\n\n Enter passort number to delete record?:");
	gets(passport); fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf(" booking has been deleted");
		Sleep(800);
		return;

	}

	while (river->following)
	{
		if (strcmp(river->following->passport, passport) == 0)
		{
			dummy = river->following;
			river->following = river->passport;
			free(dummy);
			printf("has been deleted ");
			getch();
			Sleep(800);
			return;
		}
		river = river->following;
	}
	printf("passport number is wrong please check your passport");

}
