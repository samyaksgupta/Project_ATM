#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<iostream>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include "qrcodegen.hpp"




using namespace std;
using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;





void reservation(void);
void viewdetails(void);
void cancel(void);
void printticket(char name[],int,int,float);
void specifictrain(int);
float charge(int,int);
void login();

int main()

{
	system("Color 1F");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\tLoading ");
	char x = 219;
	for(int i=0;i<35;i++){
		cout<<x;
		if(i<10)
		Sleep(300);
		if(i<10 && i<20)
		Sleep(150);
		if(i>=10)
		Sleep(25);
	}
	system("cls");
	

		system("Color 1F");
		system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t=======================================================\n");
	printf("\t\t\t\t\t|                                                     |\n");
	printf("\t\t\t\t\t|       ------------------------------------          |\n");
	printf("\t\t\t\t\t|            NEXT GEN TICKETING SYSTEM                |\n");
	printf("\t\t\t\t\t|       ------------------------------------          |\n");
	printf("\t\t\t\t\t|                                                     |\n");
	printf("\t\t\t\t\t|                                                     |\n");
	printf("\t\t\t\t\t|                                                     |\n");
	printf("\t\t\t\t\t|                                                     |\n");
	printf("\t\t\t\t\t=======================================================\n\n\n");
	printf("\t\t\t\t\t              .-=+**#####**+=-.              \n");
    printf("\t\t\t\t\t          .=*###################*=.          \n");
    printf("\t\t\t\t\t        =*#####+=:..     ..:=+#####*=        \n");
    printf("\t\t\t\t\t     .=####*-.                 .-*####=      \n");
    printf("\t\t\t\t\t    -####+.                       .+####-    \n");
    printf("\t\t\t\t\t   +###*.                           :*###+   \n");
    printf("\t\t\t\t\t  *###+.                             .+###*  \n");
    printf("\t\t\t\t\t +#########################################+ \n");
    printf("\t\t\t\t\t:###*+++++++++++++++++++#####+++++++++++*###:\n");
    printf("\t\t\t\t\t+###-                 :*###=            -###+\n");
    printf("\t\t\t\t\t####.               -*###-              .###*\n");
    printf("\t\t\t\t\t####              -*##*-                 ####\n");
    printf("\t\t\t\t\t*###.           =###*:                  .###*\n");
    printf("\t\t\t\t\t=###+=========+####*====================+###-\n");
    printf("\t\t\t\t\t ########################################### \n");
    printf("\t\t\t\t\t :####-...............................-####: \n");
    printf("\t\t\t\t\t  :####:                             -####:  \n");
    printf("\t\t\t\t\t   :*###+.                         .+###*.   \n");
    printf("\t\t\t\t\t     =####+:                     :+####=     \n");
    printf("\t\t\t\t\t      .=#####+-.             .-+#####=.      \n");
    printf("\t\t\t\t\t         -+######*+===-===+*######+-         \n");
    printf("\t\t\t\t\t            :=+###############+=:            \n");
   

	printf(" \n Press any key to continue:");

	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	system("Color 1F");
	printf("\n=================================\n");
	printf("        TRAIN TICKET SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}



void viewdetails(void)
{
    system("cls");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Tr.No   Name                    Destinations                         Charges        Time\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("1001    Red Line Metro          Dilshad Garden to Rithala              30       5:00 AM - 6:00 AM\n");
    printf("1002    Yellow Line Metro       Samaypur Badli to HUDA City Centre     40       6:30 AM - 7:30 AM\n");
    printf("1003    Blue Line Metro         Noida City Centre to Dwarka Sector 21  35       8:00 AM - 9:00 AM\n");
    printf("1004    Green Line Metro        Inderlok to Mundka                     25       9:30 AM - 10:30 AM\n");
    printf("1005    Violet Line Metro       Kashmere Gate to Raja Nahar Singh      35       11:00 AM - 12:00 PM\n");
    printf("1006    Orange Line Metro       Dwarka Sector 21 to Noida City Centre  40       1:00 PM - 2:00 PM\n");
    printf("1007    Pink Line Metro         Majlis Park to Shiv Vihar              35       2:30 PM - 3:30 PM\n");
    printf("1008    Magenta Line Metro      Botanical Garden to Janakpuri West     35       4:00 PM - 5:00 PM\n");
    printf("1009    Airport Express Metro   New Delhi to Dwarka Sector 21          60       5:30 PM - 6:30 PM\n");
    printf("1010    Grey Line Metro         Dwarka Sector 21 to Najafgarh          25       7:00 PM - 8:00 PM\n");
}






void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	fgets(passdetails.name, sizeof(passdetails.name), stdin);


	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("Here Is your qr Code\n");
				system("cls");
				system("Color 0F");
				
		printf("        ##############  ##          ##      ##############\n");
    	printf("        ##          ##  ##  ##  ######  ##  ##          ##\n");
    	printf("        ##  ######  ##      ##      ######  ##  ######  ##\n");
    	printf("        ##  ######  ##  ####  ######    ##  ##  ######  ##\n");
    	printf("        ##  ######  ##    ##    ########    ##  ######  ##\n");
   	 	printf("        ##          ##    ##    ##      ##  ##          ##\n");
    	printf("        ##############  ##  ##  ##  ##  ##  ##############\n");
    	printf("                        ##    ######  ##\n");
    	printf("        ##  ####  ######  ##  ##    ####    ##    ##  ####\n");
    	printf("                ####    ##  ########  ##    ####    ####\n");
    	printf("        ######    ####    ####  ######    ##      ##\n");
    	printf("        ##      ##    ##          ##    ##  ##  ##  ##  ##\n");
    	printf("          ##  ####  ####  ##  ##    ##      ##    ##    ##\n");
    	printf("          ##    ##      ########  ##    ##    ####  ######\n");
    	printf("          ########  ##  ##  ##  ##  ##  ####    ######  ##\n");
   	 	printf("        ##    ##      ########  ######  ##########    ##\n");
    	printf("            ####    ############  ##    ############  ##\n");
    	printf("                        ##  ##  ####  ####      ##    ##\n");
    	printf("        ##############  ##########      ##  ##  ##    ##\n");
    	printf("        ##          ##  ######  ##  ##  ##      ##  ####\n");
    	printf("        ##  ######  ##    ##  ######  ##############  ####\n");
    	printf("        ##  ######  ##  ####    ####    ##  ##      ##  ##\n");
    	printf("        ##  ######  ##  ####  ######  ########  ####  ##\n");
    	printf("        ##          ##    ##          ######        ####\n");
    	printf("        ##############  ##      ##  ####  ######    ##  ##\n");
				
				
		printf("==================");
		printf("\nPress any key to go back to Main menu");

	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}


float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(6000.0*num_of_seats);
	}
}




void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}



void specifictrain(int train_num)
{
    if (train_num == 1001)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Red Line)");
        printf("\nDestination:\t\tDilshad Garden to Rithala");
        printf("\nDeparture:\t\t5:00 AM - 6:00 AM");
    }
    if (train_num == 1002)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Yellow Line)");
        printf("\nDestination:\t\tSamaypur Badli to HUDA City Centre");
        printf("\nDeparture:\t\t6:30 AM - 7:30 AM");
    }
    if (train_num == 1003)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Blue Line)");
        printf("\nDestination:\t\tNoida City Centre to Dwarka Sector 21");
        printf("\nDeparture:\t\t8:00 AM - 9:00 AM");
    }
    if (train_num == 1004)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Green Line)");
        printf("\nDestination:\t\tInderlok to Mundka");
        printf("\nDeparture:\t\t9:30 AM - 10:30 AM");
    }
    if (train_num == 1005)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Violet Line)");
        printf("\nDestination:\t\tKashmere Gate to Raja Nahar Singh");
        printf("\nDeparture:\t\t11:00 AM - 12:00 PM");
    }
    if (train_num == 1006)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Orange Line)");
        printf("\nDestination:\t\tDwarka Sector 21 to Noida City Centre");
        printf("\nDeparture:\t\t1:00 PM - 2:00 PM");
    }
    if (train_num == 1007)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Pink Line)");
        printf("\nDestination:\t\tMajlis Park to Shiv Vihar");
        printf("\nDeparture:\t\t2:30 PM - 3:30 PM");
    }
    if (train_num == 1008)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Magenta Line)");
        printf("\nDestination:\t\tBotanical Garden to Janakpuri West");
        printf("\nDeparture:\t\t4:00 PM - 5:00 PM");
    }
    if (train_num == 1009)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Airport Express)");
        printf("\nDestination:\t\tNew Delhi to Dwarka Sector 21");
        printf("\nDeparture:\t\t5:30 PM - 6:30 PM");
    }
    if (train_num == 1010)
    {
        printf("\nTrain:\t\t\tDelhi Metro (Grey Line)");
        printf("\nDestination:\t\tDwarka Sector 21 to Najafgarh");
        printf("\nDeparture:\t\t7:00 PM - 8:00 PM");
    }
}



void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="samyak";
    char pass[10]="samyak";
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

void cancel(void)   
{
	system("cls");
	int trainnum;
	printf("-----------------------\n");
		printf("Enter the train number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&trainnum);
		printf("\n\nCancelled");
		getch();
}