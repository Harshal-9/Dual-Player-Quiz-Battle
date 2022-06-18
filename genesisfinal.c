
//This file is highly recommended to be ran on codeblocks
//system("cls") and system("colour") functions can be only executed in codeblocks

#include<stdio.h>
#include<conio.h>
#include<ctype.h> //to use toupper function...toupper function is used to capitalize the inputed character
#include<stdlib.h>
#include<string.h>
#include<time.h>

void battle_log();  //to view previously played logs
void show_record(); //display highest score
void reset_score(); //reset score back to 0
void help();  // to view help section
void store_vlaue(int,int,int); //store value of k1,k2,k3
void edit_score(float,char []); //edit highest score
void display1(int,int,int); // display lifelines left for player1
void display2(int,int,int); // display lifeline left for player2
int lifeline1(char,int,int,int); // lifeline defination for player 1
int lifeline2(char,int,int,int); //lifeline def for player 2
void out();
int k1_value(); // retrive value of k1
int k2_value(); // retrive value of k2
int k3_value(); // retrive value of k3
int countr,r,r1,count,i/*forloop*/,n,res,k1=1/*counter for easy questions*/,k2=1/*counter for medium questions*/,k3=1/*counter for hard questions*/,k=1/*for player check*/,p1f1=1,p1f2=1,p1f3=1,p2f1=1,p2f2=1,p2f3=1,z;

int second=60;
void delay(ms)  //this function is defined so as to produce delay in timer
{
    clock_t timeDelay = ms+clock(); //clock_t clock(void) returns the number of clock ticks elapsed since the program was launched.
    while(timeDelay>clock());
}
int counter()  //counter function for timer.It will count time for 60 sec
{
    while(second>=0&& !kbhit()) //jewha paryant second zero nahi honar ani keyboard warna ip nahi ghenar toparyant ha while loop chalnar
    {
        if(second>=10)     //2 digit cha second asla tar donda backslash waparla
        printf("%d\b\b",second);
        else
        printf("0%d\b\b",second); //one digit cha second asla tar tyala zero deun 2 digit banvla and mag donda backslash waparla
        delay(1000); // delay of 1000 milisecond that is delay of 1 second
        second--;
    }
    if(kbhit())  //kbhit to take input from keyboard
        second=60;
    if(second<=0)
        out();
}

void call() // we created this function to call timer in each question
{
    printf("\n\n\t\t Time left is: ");
    counter();
}

void reduce(char ch) // this function is created to just reduced the number of lines which get repeated for every question
{
     if(k%2==1)
        res=lifeline1(ch,p1f1,p1f2,p1f3);
     else
        res=lifeline2(ch,p2f1,p2f2,p2f3);

     if(res==11)
        p1f1=0;
     if(res==12)
        p1f2=0;
     if(res==13)
        p1f3=0;
     if(res==21)
        p2f1=0;
     if(res==22)
        p2f2=0;
     if(res==23)
        p2f3=0;
}

int main()
     {
     system("color f5");//to give background colour to main home
     float score;
     char choice,ch,ch2; // ch for file handling ch2 for saving correct answer of each question
     char pn1,pn2,player1_name[20],player2_name[20];
     FILE *fp;
     mainhome: // we used this because if we would have used function instead of this instructor then we need to pass many parameters in function which would really make our code difficult to handle so as to avoid this we used instructor
     system("cls");//for clearing the screen
     printf("<<<TEAM RUNTIME TERROR PRESENTS:>>>\n");
     printf("\n\t\t--------------------------------------------");
     printf("\n\t\t|\t###DUAL PLAYER QUIZ BATTLE###      |");
     printf("\n\t\t--------------------------------------------\n");
     printf("\n\t\t--------------------------------------------");
     printf("\n\t\t|\tWELCOME                            |");
     printf("\n\t\t|\t         TO                        |");
     printf("\n\t\t|\t             THE BATTLE!!!         |");
     printf("\n\t\t--------------------------------------------\n");
     printf("\n\t\t--------------------------------------------");
     printf("\n\t\t *** !!!GET READY TO STORM YOUR BRAIN!!! ***") ;
     printf("\n\t\t--------------------------------------------\n");
     printf("\n\t\t--------------------------------------------");
     printf("\n\t\t| --> Press S to start the game            |");
     printf("\n\t\t| --> Press V to view the highest score    |");
     printf("\n\t\t| --> Press R to reset score               |");
     printf("\n\t\t| --> press H for help                     |");
     printf("\n\t\t| --> press B for battle logs              |");
     printf("\n\t\t| --> press Q to quit                      |");
     printf("\n\t\t--------------------------------------------\n");
     printf("\n\t\t  --> Enter your choice:");
     choice=toupper(getch()); //to take input and convert it into uppercase we use toupper(getch())
    if (choice=='V')
	{
	show_record();
	getch();
	goto mainhome;
	}
     else if (choice=='H')
	{
	help();getch();
	goto mainhome;
	}
	else if (choice=='B')
    {
     battle_log();
     printf("\n\n\n\n\n\t*Enter any key to go to mainhome*");
     getch();
     goto mainhome;
    }
	else if (choice=='R')
	{
    reset_score();
    printf("\nThe Highest score is of 0 points !");
	getch();
	goto mainhome;}
	else if (choice=='Q')
    {
    system("cls");
    printf("\n\n\n\n\n\n\t\t\tHOPE YOU ENJOYED THE BATTLE!");
    printf("\n\n\t\t\tLOTS OF THANKS! ");
    printf("\n\n\t\t\tHAVE A NICE DAY!");
    getch();
    system("cls");
    printf("\n Created by:\n");
    printf("\n\t 1)HARSHAL KODGIRE");
    printf("\n\t 2)NIKHIL DANAPGOL");
    printf("\n\t 3)SMITAL PATIL");
    printf("\n\n Mentors:\n");
    printf("\n\t 1)SUYASH SAVJI");
    printf("\n\t 2)ADITYA GADADHANI\n");
    printf("\n Special thanks to:\n");
    printf("\n\t!ACSES CLUB WCE!\n\n");
        exit(1);
    }
    else if(choice=='S')
    {
     system("cls");
    printf("\n\t\tWARM WELCOME TO BOTH THE PLAYERS!!!");
    printf("\n\n\n\t\t\tPlease resister your names below:\n\n");
    printf("\n\tEnter the name of Player 1: ");
    gets(player1_name);
    printf("\n\tEnter the name of Player 2: ");
    gets(player2_name);
    printf("\n\tSo,till the end of battle %s is PLAYER1 and %s is PLAYER2",player1_name,player2_name);
    printf("\n\n\n\t\t\t-->!!!ALL THE BEST!!!<--");
    getch();

    system("cls");
    printf("\n ******************  WELCOME \"%s\" AND \"%s\" TO DUAL PLAYER QUIZ BATTLE  ****************",player1_name,player2_name);
    printf("\n\n Here are some rules and tips you might need to know before getting started:");
    printf("\n ----------------------------------------------------------------------------");
    printf("\n >> This battle consist of 30 questions,15 questions each for each player.\n");
    printf("\n >> These questions are divided into three sections : Easy, Medium and Hard!");
    printf("\n    First 10 questions will be of EASY level next 10 will be of MEDIUM level");
    printf("\n    and rest 10 will be of HARD level.\n");
    printf("\n >> Both players will be asked continous questions, for each correct answer");
    printf("\n    player will be awarded with 1 point !\n");
    printf("\n >> Each player will be provided with 3 LIFELINES you will get information about");
    printf("\n    LIFELINES on next page.\n");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option.\n");
    printf("\n >> If anyone choose the incorrect option,he/she will be eliminated!\n");
    printf("\n\n * Press N to go to the next page! *\n");
    printf("\n * Press any other key to return to the main menu! *");
    printf("\n\n     Enter your choice:");
    if(toupper(getch())=='N')
    {
        system("cls");
        printf("\n\t------------------- LIFE LINES --------------------------\n");
        printf("\n\t\tFOLLOWING ARE THREE \"LIFE LINES\" :- ");
        printf("\n\n\t\t\t1)JEEVAN");
        printf("\n\t\t\t2)SKIPPER");
        printf("\n\t\t\t3)COUNTLESS");
        printf("\n\n 1)\"JEEVAN\" : By using this lifeline player can attempt the same question for second time!");
        printf("\n              (i.e if player gives wrong answer then he/she can again try to answer the same");
        printf("\n                   question without being eliminated!!!)\n");
        printf("\n 2)\"SKIPPER\" : By using this lifeline player can skip the question!\n");
        printf("\n 3)\"COUNTLESS\" : By using this lifeline player can stop timer !\n");
        printf("\n     **Note that:-");
        printf("\n\n\t\t   You need to enter 'Q' to use life-lines.!  ");
        printf("\n\n\t* NOTE: Each lifeline can be used only once.* ");
        printf("\n\t* Press Y to start the Battle! *");
        printf("\n\t* Press any other key to return to the main menu! *");
        printf("\n\n\t\tEnter your choice:");
    }
    else
    {
    goto mainhome;
    system("cls");
    }
    if (toupper(getch())=='Y')
		{
		    goto home;
        }
	else
		{
            goto mainhome;
            system("cls");
        }

     wrong:

     store_value(k1,k2,k3);
     system("color f5");
     max(k);
     fp=fopen("battle_log.txt","a");
     if(k%2==0)
        fprintf(fp," \n\n\t\t\t %s\t\t%s\t\t%s",player1_name,player2_name,player1_name);
     else
        fprintf(fp," \n\n\t\t\t %s\t\t%s\t\t%s",player2_name,player1_name,player2_name);
     fclose(fp);
     printf("\n\n\t\t   Incorrect option! You are out of the Battle!\n\n Press enter to go to result page...");
     getch();
     goto result;

     home:

     system("cls");
     printf("\n\n\n\n\n\n\n\t\tGet! Set! Go....");
     getch();
     system("cls");
     k1=k1_value();
     k2=k2_value();
     k3=k3_value();

     z=k1;
     while(k1<z+10&&k1<=50){      //while loop is introduced for setting question limit of 10 everytime out of 50
     switch(k1)//switch case for displaying easy level questions
     {

        case 1:
            system("cls");system("color f0"); //players background color
            printf("\n The tallest building in the world is located in which city?\n");  //question
            printf("\n A) New york\n\n B) Dubai\n\n C) Delhi\n\n D) None of these"); //options
            ch2='B'; //correct answer
            if(k%2==1) //player 1
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0) // player 2
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call(); // timer
            choice=toupper(getch()); // take input
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;  // to increament question
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 2:
            system("cls");system("color 0f");
            printf("\n Where do the prime minister if India reside?\n");
            printf("\n A) Mumbai\n\n B) Chennai\n\n C) Delhi\n\n D) Lucknow");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 3:
            system("cls");system("color f0");
            printf("\n Which Indian state has the most literacy rate?\n");
            printf("\n A) kerala\n\n B) Rajasthan\n\n C) Arunachal Pradesh\n\n D) Orissa");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 4:
            system("cls");system("color 0f");
            printf("\n In which state is mahabaleshwar located?\n");
            printf("\n A) Mizoram\n\n B) Maharashtra\n\n C) Manipur\n\n D) Orissa");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 5:
            system("cls");system("color f0");
            printf("\n Gravity was discovered by ....\n");
            printf("\n A) Einstine\n\n B) Faraday\n\n C) Newton\n\n D) Galileo");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 6:
            system("cls");system("color 0f");
            printf("\n Which river flows in India?\n");
            printf("\n A) Godavari\n\n B) nile\n\n C) Bauxin\n\n D) None of these");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 7:
            system("cls");system("color f0");
            printf("\n  Who won the Nobel Prize for Literature in 1913?\n");
            printf("\n A) Debendranath Tagore\n\n B) Rabindranath Tagore\n\n C) Mohammad Iqbal\n\n D) Mirza Galib");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 8:
            system("cls");system("color 0f");
            printf("\n Where is White house located ?\n");
            printf("\n A) America\n\n B) Pakistan\n\n C) China\n\n D) India");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 9:
            system("cls");system("color f0");
            printf("\n Who constructed basic format of Indian constitution?\n");
            printf("\n A) Abdul Kalam\n\n B) Narendra Modi\n\n C) Dr Babasaheb Ambedkar\n\n D) Rajeev Gandhi");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;


        case 10:
            system("cls");system("color 0f");
            printf("\n M.S Dhoni is related to which sport played in India?\n");
            printf("\n A) Chess\n\n B) Cricket\n\n C) Ludo\n\n D) Carrom");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;


        case 11:
            system("cls");system("color f0");
            printf("\n Which Indian state has its maximum area under the forest cover?\n");
            printf("\n A) Maharashtra \n\n B) Madhya Pradesh\n\n C) Arunachal Pradesh\n\n D) Kerala");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 12:
            system("cls");system("color 0f");
            printf("\n India is a federal union comprising twenty-nine states and how many  union territories?\n");
            printf("\n A) 6\n\n B) 7\n\n C) 8\n\n D) 9");
            ch2='D';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='D')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='D'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 13:
            system("cls");system("color f0");
            printf("\n Which of the following is the capital of Arunachal Pradesh\n");
            printf("\n A) Itanagar \n\n B) Dispur\n\n C) Imphal\n\n D) Panaji");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 14:
            system("cls");system("color 0f");
            printf("\n Curd made up of\n");
            printf("\n A) palm oil\n\n B) Lime water\n\n C) Milk\n\n D) None of the above");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 15:
            system("cls");system("color f0");
            printf("\n Who has served as prime minister of India ?\n");
            printf("\n A) Shivraj Chauhan\n\n B) Indira Gandhi\n\n C) Amit Shah\n\n D) Sonia Gandhi");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 16:
            system("cls");system("color 0f");
            printf("\n The trophies and cups awarded for cricket are\n");
            printf("\n A) McDowell's Challenge cup and World cup\n\n B) Federation cup\n\n C) Moin-ud-Dowla cup and B. C. Gupta cup\n\n D) None of the above");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 17:
            system("cls");system("color f0");
            printf("\n The velocity of light is greater than veocity of \n");
            printf("\n A) earth\n\n B) air\n\n C) All\n\n D) Sound");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 18:
            system("cls");system("color 0f");
            printf("\n The telescope is used for viewing\n");
            printf("\n A) distant objects\n\n B) near objects\n\n C) small objects\n\n D) living cells");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 19:
            system("cls");system("color f0");
            printf("\n The term butterfly is associated with which sport\n");
            printf("\n A) Kabaddi\n\n B) Swimming\n\n C) Boxing\n\n D) Wrestling");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 20:
            system("cls");system("color 0f");
            printf("\n The velocity of sound in air (under normal condition) is\n");
            printf("\n A) 30 m/sec\n\n B) 320 m/sec\n\n C) 343 m/sec\n\n D) 430 m/sec");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 21:
            system("cls");system("color f0");
            printf("\n The unit of current is\n");
            printf("\n A) ohm\n\n B) watt\n\n C) ampere\n\n D) none of the above");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 22:
            system("cls");system("color 0f");
            printf("\n Vitamin A is most useful for combating\n");
            printf("\n A) anemia\n\n B) goitre\n\n C) rickets\n\n D) night blindness");
            ch2='D';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='D')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='D'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 23:
            system("cls");system("color f0");
            printf("\n Ancient India had largest deposits of ____ in the world.\n");
            printf("\n A) silver\n\n B) copper\n\n C) gold\n\n D) none of the above");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 24:
            system("cls");system("color 0f");
            printf("\n India's first satellite is named after...\n");
            printf("\n A) Aryabhatta\n\n B) Bhaskara II\n\n C) Bhaskara I\n\n D) Albert Einstein");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 25:
            system("cls");system("color f0");
            printf("\n India's tallest statue is located at\n");
            printf("\n A) Karnakata\n\n B) New Delhi\n\n C) Gujarat\n\n D) Madhya Pradesh");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 26:
            system("cls");system("color 0f");
            printf("\n If speed of rotation of the earth increases, weight of the body\n");
            printf("\n A) increases\n\n B) remain the same\n\n C) decreases\n\n D) may increase or decrease");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 27:
            system("cls");system("color f0");
            printf("\n In which year did Narendra Modi became the Prime Minister of India for the First time\n");
            printf("\n A) 2013\n\n B) 2014\n\n C) 2019\n\n D) 2017");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 28:
            system("cls");system("color 0f");
            printf("\n How many players are there on each side in the game of cricker?\n");
            printf("\n A) 4\n\n B) 11\n\n C) 6\n\n D) 7");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 29:
            system("cls");system("color f0");
            printf("\n India's first atomic power station was set up at\n");
            printf("\n A) Surat (Gujarat)\n\n B) Tarapur (Maharashtra)\n\n C) Trombay (Maharashtra)\n\n D) Solapur (Maharashtra)");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 30:
            system("cls");system("color 0f");
            printf("\n How many grams are there in 1 kilogram weight?\n");
            printf("\n A) 900\n\n B) 500\n\n C) 1000\n\n D) 250");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 31:
            system("cls");system("color f0");
            printf("\n  Joule is the unit of\n");
            printf("\n A) temperature\n\n B) heat\n\n C) energy\n\n D) pressure");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 32:
            system("cls");system("color 0f");
            printf("\n Most commonly used bleaching agent is\n");
            printf("\n A) alcohol\n\n B) carbon dioxide\n\n C) chlorine\n\n D) sodium chloride");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 33:
            system("cls");system("color f0");
            printf("\n Neil Armstrong and Edwin Aldrin were the first to\n");
            printf("\n A) step on the moon\n\n B) circle the moon\n\n C) walk in space\n\n D) journey into space");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 34:
            system("cls");system("color 0f");
            printf("\n Light Year is related to\n");
            printf("\n A) energy\n\n B) speed\n\n C) distance\n\n D) intensity");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 35:
            system("cls");system("color f0");
            printf("\n Penicillin is widely used as\n");
            printf("\n A) an antiseptic\n\n B) a disinfectant\n\n C) an antibiotic\n\n D) an insecticide");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 36:
            system("cls");system("color 0f");
            printf("\n Pressure cooker cooks rice faster because\n");
            printf("\n A) it always lets the steam escape\n\n B) high pressure crushes the hard covering of rice grains\n\n C) it does not let the heat energy escape easily\n\n D) high pressure raises the boiling point of water");
            ch2='D';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='D')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='D'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 37:
            system("cls");system("color f0");
            printf("\n Study of nature is known as\n");
            printf("\n A) ecology\n\n B) naturalist\n\n C) numismatics\n\n D) None of the above");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 38:
            system("cls");system("color 0f");
            printf("\n Super conductivity is a phenomenon in which the resistance of a  substance\n");
            printf("\n A) increases with temperature\n\n B) decreases with temperature\n\n C) does not change with temperature\n\n D) becomes zero at very low temperature");
            ch2='D';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='D')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='D'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 39:
            system("cls");system("color f0");
            printf("\n The energy of food is measured in\n");
            printf("\n A) kelvin\n\n B) calories\n\n C) bushel\n\n D) none of the above");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 40:
            system("cls");system("color 0f");
            printf("\n The instrument used to measure electric current is\n");
            printf("\n A) Ammeter\n\n B) electrometer\n\n C) galvonometer\n\n D) spectrometer");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 41:
            system("cls");system("color f0");
            printf("\n When is Christmas celebrated\n");
            printf("\n A) December\n\n B) November\n\n C) October\n\n D) Augest");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 42:
            system("cls");system("color 0f");
            printf("\n The smallest state of India is\n");
            printf("\n A) Rajsthan\n\n B) sikkim\n\n C) himachal pradesh\n\n D) Goa");
            ch2='D';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='D')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='D'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 43:
            system("cls");system("color f0");
            printf("\n The name of Ronaldo is associated with the game of\n");
            printf("\n A) football\n\n B) hockey\n\n C) gymnastics\n\n D) badminton");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 44:
            system("cls");system("color 0f");
            printf("\n The official language of the Government of India is\n");
            printf("\n A) English\n\n B) Malyalam\n\n C) Hindi\n\n D) Marathi");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 45:
            system("cls");system("color f0");
            printf("\n The number of chromosomes in human body is\n");
            printf("\n A) 42\n\n B) 44\n\n C) 46\n\n D) 48");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 46:
            system("cls");system("color 0f");
            printf("\n The unit of energy in MKS system is\n");
            printf("\n A) volt\n\n B) erg\n\n C) ohm\n\n D) joule");
            ch2='D';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='D')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='D'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 47:
            system("cls");system("color f0");
            printf("\n  Water is a good solvent of ionic salts because\n");
            printf("\n A) it has a high boiling point\n\n B) it has a high dipole moment\n\n C) it has a high specific heat\n\n D) it has no colour");
            ch2='B';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='B')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='B'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 48:
            system("cls");system("color 0f");
            printf("\n  When light passes from air into glass it experiences change of\n");
            printf("\n A) frequency and wavelength\n\n B) frequency and speed\n\n C) wavelength and speed\n\n D) frequency, wavelength and speed");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 49:system("color f0");
            system("cls");
            printf("\n What is the S.I. unit of temperature?\n");
            printf("\n A) kelvin\n\n B) celcius\n\n C) Centigrade\n\n D) Fahrenheit");
            ch2='A';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='A')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='A'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;

        case 50:
            system("cls");system("color 0f");
            printf("\n What is the capital of Jharkhand\n");
            printf("\n A) Raipur\n\n B) Dehradun\n\n C) Ranchi\n\n D) None of the above");
            ch2='C';
            if(k%2==1)
            { display1(p1f1,p1f2,p1f3);printf("\n\n %s enter your choice: ",player1_name);}
            if(k%2==0)
            { display1(p2f1,p2f2,p2f3);printf("\n\n %s enter your choice: ",player2_name);}
            call();
            choice=toupper(getch());
            if(choice=='C')
            {
                printf("\n\n\t\t   !!!Your answer is correct!!!\n\n Press enter to go to next question...!");
                k++;k1++;
                getch();
            }
            if(choice=='Q')
            {
                reduce(ch2);k++;k1++;
            }
            if((choice!='C'&&choice!='Q')||res==-100)
            {	goto wrong;	}
            continue;
     }
  }
        if(k1>=50)
            k1=1;
        store_value(k1,k2,k3);//to store respective values of k1,k2,k3

     z=k2;
     while(k2<z+10&&k2<=50){
     switch(k2)//switch case for displaying medium level questions
     {

         case 1:
             system("cls");system("color f0");
             printf("\n Which of these numbers is normally required to verify a transaction,when shopping online using a debit or credit card?\n\n A) PAN\n\n B) PNR\n\n C) CVV\n\n D) AADHAR ");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100)    {
                    goto wrong;}
             continue;

         case 2:
             system("cls");system("color 0f");
            printf("\n \“Nabhah Sparsham Deeptam\”, the motto of India Air Force,is taken from which ancient work?\n\n A) Garuda Purana\n\n B) Valmiki Ramayan\n\n C) Bhagwad Gita\n\n D) Mundaka Upnishad");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

         case 3:
             system("cls");system("color f0");
              printf("\n At which monument in Delhi did the British forces arrest Bahadur Shah Zafar in September 1857?\n\n A) Humayu’s Tomb\n\n B) Nizamuddin Dargah\n\n C) Purana Qila\n\n D) Tughlaqabad Fort");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);
                k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

         case 4:
             system("cls");system("color 0f");
             printf("\n Which of these creatures is not scientifically classified as fish?\n\n A) Rohu\n\n B) Katla\n\n C) Hilsa\n\n D) Jhinga");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

         case 5:
             system("cls");system("color f0");
            printf("\n Which is the largest joint in the human body?\n\n A) Elbow\n\n B) Hip\n\n C) Knee\n\n D) Shoulder");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

        case 6:
             system("cls");system("color 0f");
             printf("\n What does the ‘R’ stand for in the name of Dr B R Ambedkar?\n\n A) Ramesh\n\n B) Ramakant\n\n C) Raman\n\n D) Ramji");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                if(choice=='Q')
                {
                 reduce(ch2);
                 k++;k2++;
                }
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;


        case 7:
             system("cls");system("color f0");
             printf("\n According to WHO, which disease has been completely eradicated from the world by vaccination?\n\n A) Measles\n\n B) Polio\n\n C) Mumps\n\n D) Smallpox");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

        case 8:
             system("cls");system("color 0f");
             printf("\n In which century were the first two battles of Panipat fought?\n\n A) 15th\n\n B) 16th\n\n C) 18th\n\n D) 17th");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 9:
             system("cls");system("color f0");
              printf("\n Which of these is usually denoted by 120/80 for an adult?\n\n A) Normal Pulse\n\n B) Normal Hearing\n\n C) Normal vision\n\n D) Normal Blood Pressure");
              ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

        case 10:
             system("cls");system("color 0f");
             printf("\n Who advised Mahatma Gandhi to take a tour of the whole country before becoming active in national politics?\n\n A) Annie Besant\n\n B) Gopal Krishna Gokhale\n\n C) Bipin Chandra Pal\n\n D) Bal Gangadhar Tilak");
             fclose(fp);
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

        case 11:
             system("cls");system("color f0");
             printf("\n The wife of which of these famous sportspersons was once captain of Indian\nvolleyball team?\n\n A) K.D.Jadav\n\n B) Milkha Singh\n\n C) Dhyan Chand\n\n D) Prakash Padukone");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;


        case 12:
             system("cls");system("color 0f");
            printf("\n In which state is the Larji Hydroelectric Power Project located?\n\n A) Uttarakhand\n\n B) Himachal Pradesh\n\n C) Sikkim\n\n D) Jammu and Kashmir");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

        case 13:
             system("cls");system("color f0");
              printf("\n Which newspaper once kept its editorial column blank as a mark of protest against the emergency of 1975?\n\n A) Hindustan Times\n\n B) The Indian Express\n\n C) The Hindu\n\n D) The Times of India");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;


        case 14:
             system("cls");system("color 0f");
            printf("\n Which of these terms is not associated with football?\n\n A) Penalty Kick.\n\n B) Direct free kick\n\n C)  Offside\n\n D) Penalty Stroke");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 15:
             system("cls");system("color f0");
             printf("\n Within which of these mediums is the speed of the sound fastest?\n\n A) Vacuum\n\n  B) Air\n\n C) Water\n\n D) Steel");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                goto wrong;}
             continue;

    case 16:
             system("cls");system("color 0f");
            printf("\n Which of these teams has not played their first ever cricket test match against India?\n\nA) Bangladesh\n\n B) Afghanistan\n\n C)  Ireland\n\n D) Zimbabwe");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;
        case 17:
             system("cls");system("color f0");
            printf("\n Which objects of everyday use have types called AA, AAA, C and D?\n\n A) SIM Cards\n\n B) Memory Cards\n\n C) Batteries\n\n D) Paper");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;
        case 18:
             system("cls");system("color 0f");
            printf("\n On which of these planets does the sun rise in the west and set in the east?\n\n A) Jupiter\n\n B) Mars\n\n C) Venus\n\n D) Mercury");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;
        case 19:
             system("cls");system("color f0");
            printf("\n What Animal is the official state animal of Karnataka, Kerala and Jharkhand?\n\n A) Lion\n\n B) Tiger\n\n C) Elephant\n\n D) Deer");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 20:
             system("cls");system("color 0f");
            printf("\n What is the meaning of Kharif in reference to Kharif Crop?\n\n A) Patjhad\n\n B) Vasant\n\n C) Varsha\n\n D) Grishma");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 21:
             system("cls");system("color f0");
            printf("\n About which city did Mark Twain write, “older than history, older than tradition, older even than legend and looks twice as old as all\nof them put together”?\n\n A) Delhi\n\n B) Dhaka\n\n C) Prayag\n\n D) Varanasi");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 22:
             system("cls");system("color 0f");
            printf("\nn Which of these team sports are players categorized as defenders and raiders?\n\n A) Kabaddi\n\n B) Volleyball\n\n C) Kho – Kho\n\n D) Malkhambh");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 23:
             system("cls");system("color f0");
            printf("\n What is the common name for surgery conducted on coronary arteries that supply blood to the heart?\n\n A) Cataract\n\n B) Gastric\n\n C) Bypass\n\n D) Debridement");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 24:
             system("cls");system("color 0f");
            printf("\n Which of these Indian cities is closest to the Pakistani city of Lahore?\n\n A) Srinagar\n\n B) Jaisalmer\n\n C) Amritsar\n\n D) Udhampur");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 25:
             system("cls");system("color f0");
            printf("\n In July 2017, Narendra Modi Become the first Indian Prime Minister to visit which country?\n\n A)  Israel\n\n B) Jordan\n\n C) Saudi Arabia\n\n D) Qatar");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 26:
             system("cls");system("color 0f");
            printf("\n At which of these institutes did Dr APJ Abdul Kalam deliver his final lecture?\n\n A) IIT Bombay\n\n B) IIM Shillong\n\n C) IIT Madras\n\n D) IIM Calicut");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 27:
             system("cls");system("color f0");
            printf("\n With reference to vehicles, which one of the following specifically advised to be used at night?\n\n A) Horn\n\n B) Hand Brake\n\n C) Dipper\n\n D) Power Window");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 28:
             system("cls");system("color 0f");
            printf("\n What can you hear when a bell rings in a vaccum?\n\n A) Loud Sound\n\n B) Usual Sound\n\n C) No Sound\n\n D) Vibrating Sound");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 29:
             system("cls");system("color f0");
            printf("\n What does ‘S’ stand for in a ‘SIM’ card used in mobile phones?\n\n A) Service\n\n B) Smart\n\n C) Science\n\n D) Subscriber");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 30:
             system("cls");system("color 0f");
            printf("\n What is the color of octopus blood?\n\n A) Blue\n\n B) White\n\n C) Red\n\n D) Yellow");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 31:
             system("cls");system("color f0");
            printf("\n Whose birthday is celebrated as ‘Engineers’ Day’ in India?\n\n A) A P J Abdul Kalam\n\n B) John C. Gammon\n\n C) M Visvesvarayya\n\n D) Soren Krisitian Toubro");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 32:
             system("cls");system("color 0f");
            printf("\n Which mountain was formerly known as Peak 15?\n\n A) Mount Rushmore\n\n B) Kanchenjunga\n\n C) Mount Everest\n\n D) K2");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 33:
             system("cls");system("color f0");
            printf("\n Maulana Abul Kalam Azad’s Birthday on 11 November is celebrated in India as what?\n\n A)  National Education Day\n\n B) National Integration Day\n\n C) National Minority Day\n\n D) National Sports Day");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 34:
             system("cls");system("color 0f");
            printf("\n Lok Kalyan Marg, New Delhi is the residential complex of which of these public servants?\n\n A) President of India\n\n B) Chief Minister of Delhi\n\n C) Prime Minister of India\n\n D) Vice – President of India");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 35:
             system("cls");system("color f0");
            printf("\n ‘India Begins Here’ is the tagline of which state’s tourism campaign?\n\n A) West Bengal\n\n B) Punjab.\n\n C) Madhya Pradesh\n\n D) Rajasthan");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 36:
             system("cls");system("color 0f");
            printf("\n Which of these can be estimated from the colour of the nose of a lion?\n\n A) Age\n\n B) Speed\n\n C) Intelligence\n\n D) Strength");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 37:
             system("cls");system("color f0");
            printf("\n Who is the first player from Afghanistan to play in the IPL?\n\n A) Dawlat Zadran\n\n B) Mohammad Shahzad\n\n C) Mohammad Nabi\n\n D) Rashid Khan");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 38:
             system("cls");system("color 0f");
            printf("\n Which of these is a metal which in its pure form, is silvery white in appearance?\n\n A) Bauxite\n\n B) Tin\n\n C) Copper\n\n D) Graphite");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 39:
             system("cls");system("color f0");
            printf("\n What is the name of Indian Navy’s aircraft carrier which was decommissioned after 30 years of service in March 2017?\n\n A) INS Vikramaditya\n\n B) INS Viraat\n\n C) INS Vikrant\n\n D) INS Ranvijay");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 40:
             system("cls");system("color 0f");
            printf("\n Which of these fruits gets its English name from an Arabic word which can be translated as ‘dates from India’?\n\n A) Tamarind\n\n B) Coconut\n\n C) Carambola\n\n D) Jujube");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 41:
             system("cls");system("color f0");
            printf("\n Who became the first Indian woman to join the International Olympic Committee?\n\n A) Anjum Chopra\n\n B) P T Usha\n\n C) Karnam Malleswari\n\n D) Nita Ambani");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 42:
             system("cls");system("color 0f");
            printf("\n Which of these organs is a part of the human digestive system?\n\n A) Pancreas\n\n B) Thymus\n\n C) Pituitary gland\n\n D) Cerebrum");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 43:
             system("cls");system("color f0");
            printf("\n Who among these leaders has served thrice as Prime Minister but never completed a full term in office?\n\n A) Sheikh Haseena\n\n B) Atal Bihari Vajpayee\n\n C) Nawaz Sharif\n\n D) Begum Khaleeda Zia");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 44:
             system("cls");system("color 0f");
            printf("\n Which of these substances is composed of only two elements hydrogen & oxygen?\n\n A) Water\n\n B) Salt\n\n C) Sugar\n\n D) Blood");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 45:
             system("cls");system("color f0");
            printf("\n Which crop is sown on the largest area in India?\n\n A) Rice\n\n B) Wheat\n\n C) Sugarcane\n\n D) Maize");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 46:
             system("cls");system("color 0f");
            printf("\n Which of the following personalities gave ‘The Laws of Heredity’?\n\n A) Robert Hook\n\n B) G.J. Mendel\n\n C) Charles Darwin\n\n D) William Harvey");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);
                 k++;k2++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 47:
             system("cls");system("color f0");
            printf("\n In which state has the largest area?\n\n A) Maharashtra\n\n B) Madhya Pradesh\n\n C) Uttar Pradesh\n\n D) Rajasthan");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 48:
             system("cls");system("color 0f");
            printf("\n Galileo was an Italian astronomer who\n\n A) developed the telescope\n\n B) discovered four satellites of Jupiter\n\n C) discovered that the movement of pendulum produces a regular time measurement\n\n D) All of the above");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 49:
             system("cls");system("color f0");
            printf("\n The Maratha and The Kesri were the two main newspapers\nwhich were started by the following people?\n\n A) Lala Lajpat Rai\n\n B) Gopal Krishna Gokhale\n\n C) Bal Gangadhar Tilak\n\n D) Madan Mohan Malviya");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 50:
             system("cls");system("color 0f");
            printf("\n Exposure to sunlight helps a person to improve his health because\n\n A) the infrared light kills bacteria in the body\n\n B) resistance power increases\n\n C) the pigment cells in the skin get stimulated and produce a healthy tan\n\n D) the ultraviolet rays convert skin oil into Vitamin D");
            ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k2++;
                getch();
             }
             if(choice=='Q')
             {
                  reduce(ch2);
                 k++;k2++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


     }
 }
     if(k2>=50)
        k2=1;
     store_value(k1,k2,k3);


     z=k3;
     while(k3<z+10&&k3<=50){
     switch(k3)//switch case for displaying hard level questions
     {
         case 1:
             system("cls");system("color f0");
             printf("\n What was the name of all the three soccer clubs set up with the help of Mahatama Gandhi in the early 20th century at Durban, Pretoria and Johannesburg?\n");
             printf("\n A) Truth Seeker\n\n B) NonViolents\n\n C) Passive Resisters\n\n D) Non co-operators");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 2:
             system("cls");system("color 0f");
             printf("\n Which of these states has had the most number of its governors become presidents of India?\n");
             printf("\n A) Rajasthan\n\n B) Bihar\n\n C) Punjab\n\n D) Andhra Pradesh");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                  goto wrong;}
             continue;

         case 3:
             system("cls");system("color f0");
             printf("\n Who was the Indian bowler off whom Australian legend Don Bradman got a single to reach his 100th first class century?\n");
             printf("\n A) Baqa Jilani\n\n B) Commandur Rangachari\n\n C) Gogumal Kishenchand\n\n D) Kanwar Rai Singh");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 4:
             system("cls");system("color 0f");
             printf("\n Which of these Mughal structures was known by the name ‘Rauza-i-Munawwara'?\n");
             printf("\n A) Shalimar Bagh\n\n B) Chini Ka Rauza\n\n C) Humayun’s Tomb\n\n D) Taj Mahal");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 5:
             system("cls");system("color f0");
             printf("\n In mythology, what was the name of Hiranyakashipu’s wife and Prahlad’s mother?\n");
             printf("\n A) Kapinjala\n\n B) Kayadhu\n\n C) Kamalakshi\n\n D) Kaushiki");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 6:
             system("cls");system("color 0f");
             printf("\n Sir Edmund Hillary served as which county’s high commissioner to India, Bangladesh and Nepal?\n");
             printf("\n A) United Kingdom\n\n B) Australia\n\n C) Canada\n\n D) New Zealand");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 7:
             system("cls");system("color f0");
             printf("\n Which Deputy Chairman of the Rajya Sabha went on to become president of India?\n");
             printf("\n A) Varahagiri Venkata Giri\n\n B) Pratibha Patil\n\n C) Zakir Hussain\n\n D) Shankar Dayal Sharma");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 8:
             system("cls");system("color 0f");
             printf("\n Who was the first Indian director of the Indian Institute of Science, Bangalore, the brainchild of Jamshedji Nusserwanji Tata?\n");
             printf("\n A) Dorabji Tata\n\n B) CV Raman\n\n C) Homi Jehangir Bhabha\n\n D) Satish Dhawan");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 9:
             system("cls");system("color f0");
             printf("\n In which group of places the Kumbha Mela is held every twelve years?\n");
             printf("\n A) Ujjain,Purl,Prayag,Haridwar\n\n B) Prayag,Haridwar,Ujjain,Nasik\n\n C) Rameshwaram,Purl,Badrinath,Dwarika\n\n D) Chittakoot,Ujjain,Prayag,Haridwar");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 10:
             system("cls");system("color 0f");
             printf("\n Which day is observed as the World Standards Day?\n");
             printf("\n A) June 26\n\n B) Oct 14\n\n C) Nov 15\n\n D) Dec 2");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                  goto wrong;}
             continue;

        case 11:
             system("cls");system("color f0");
             printf("\n Which of the following was the theme of the World Red Cross and Red Crescent Day?\n");
             printf("\n A) Dignity for all - focus on women\n\n B) Dignity for all - focus on Children\n\n C) Focus on health for all\n\n D) Nourishment for all-focus on children");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 12:
             system("cls");system("color 0f");
             printf("\n Who is the author of 'Manas Ka-Hans'?\n");
             printf("\n A) Khushwant Singh\n\n B) Prem Chand\n\n C) Jayashankar Prasad\n\n D) Amrit Lal Nagar");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 13:
             system("cls");system("color f0");
             printf("\n Who is the author of the book 'Amrit Ki Ore'?\n");
             printf("\n A) Mukesh Kumar\n\n B) Narendra Mohan\n\n C) Upendra Nath\n\n D) Nirad C. Choudhary");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 14:
             system("cls");system("color 0f");
             printf("\n The festival of Nabanna is celebrated predominatly in\n");
             printf("\n A) Andhra Pradesh\n\n B) Rajasthan\n\n C) Karnataka\n\n D) Orissa");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 15:
             system("cls");system("color f0");
             printf("\n Writers Building is the headquarters of\n");
             printf("\n A) The times of India group\n\n B) All India Writers Association\n\n C) West Bengal Government\n\n D) Press Trust of India");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 16:
             system("cls");system("color 0f");
             printf("\n Which of the following years was celebrated as the World Communication Year?\n");
             printf("\n A) 1981\n\n B) 1983\n\n C) 1985\n\n D) 1987");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 17:
             system("cls");system("color f0");
             printf("\n Who holds the Guinness Wole Record for the oldest person to be elected for the first time as PM of a nation? \n");
             printf("\n A) P V Narasimha Rao\n\n B) Chaudhary Charan Singh\n\n C) Morarji Desai\n\n D) H D Deve Gowda");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 18:
             system("cls");system("color 0f");
             printf("\n Who was the first Indian to win the Booker Prize?\n");
             printf("\n A) Dhan Gopal Mukerji\n\n B) Nirad C.Chaudhuri\n\n C) Arundhati Roy\n\n D) Aravind Adiga");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 19:
             system("cls");system("color f0");
             printf("\n Which among the following Kavya of Sanskrit, deal with court intrigues & access to power of Chandragupta Maurya?\n");
             printf("\n A) Mrichhakatika\n\n B) Ritusamhara\n\n C) Kumarasambhava\n\n D) Mudrarakshahsa");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 20:
             system("cls");system("color 0f");
             printf("\n On which of the following systems of Hindu Philosophy , Shankaracharya wrote commentary in 9th century AD?\n");
             printf("\n A) Sankhya\n\n B) Vaisheshika\n\n C) Yoga\n\n D) Uttarmimansa");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 21:
             system("cls");system("color f0");
             printf("\n Katerina Sakellaropoulou was elected the first woman President of -\n");
             printf("\n A) Greece\n\n B) Spain\n\n C) Finland\n\n D) Netherland");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 22:
             system("cls");system("color 0f");
             printf("\n What is India's rank on EIU's Global Democracy Index 2019?\n");
             printf("\n A) 48th Rank\n\n B) 50th Rank\n\n C) 53rd Rank\n\n D) 51st Rank");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 23:
             system("cls");system("color f0");
             printf("\n What is India's rank on the WEF's Global Social Mobility Index 2020?\n");
             printf("\n A) 75th Rank\n\n B) 77th Rank\n\n C) 76th Rank\n\n D) 78th Rank");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 24:
             system("cls");system("color 0f");
             printf("\n Allocation for BharatNet programme for 2020-21 is -\n");
             printf("\n A) Rs. 10000 crore\n\n B) Rs. 8000 crore\n\n C) Rs. 6000 crore\n\n D) Rs. 4000 crore");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 25:
             system("cls");system("color f0");
             printf("\n How much taxpayers money is invested as governments equity in Public Sector Banks?\n");
             printf("\n A) Rs. 430,000 crore\n\n B) Rs. 5,90,000 crore\n\n C) Rs. 6,10,000 crore\n\n D) Rs. 680,000 crore");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 26:
             system("cls");system("color 0f");
             printf("\n National Recruitment Agency (NRA) will be set up as an independent, professional, specialist organisation\n for conduct of a computer-based online Common Eligibility Test for recruitment to -\n");
             printf("\n A) Gazetted posts\n\n B) Non-Gazetted posts\n\n C) Technical posts\n\n D) All types of posts");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 27:
             system("cls");system("color f0");
             printf("\n The 'International Criminal Police Organisation' (Interpol) will hold its General Assembly in India in 2022. The 'Interpol' is an inter government organization having 194 member countries including India. It is headquartered in -\n");
             printf("\n A) Lisbon, Portugal/n/n B) London, UK/n/n C) Lyon, France/n/n D) Lucerne, Switzerland.");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 28:
             system("cls");system("color 0f");
             printf("\n The International Solar Alliance is a group of solar resource-rich countries with headquarters in -\n");
             printf("\n A) None of those given as options\n\n B) Gurugram, India\n\n C) Geneva, Switzerland\n\n D) Guangzhou, China");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 29:
             system("cls");system("color f0");
             printf("\n A new book titled How to Avoid a Climate Disaster : The Solutions We Have and the Breakthroughs We Need has been authored by philanthropist -\n");
             printf("\n 1) Warren Buffet\n\n 2) Ratan Tata\n\n 3) Azim Premji\n\n 4) Bill Gates");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                  goto wrong;}
             continue;

         case 30:
             system("cls");system("color 0f");
             printf("\n Pakyong Airport is a Greenfield RCS airport in which of the following cities?\n");
             printf("\n A) Nagpur, Maharashtra\n\n B) Guwahati, Assam\n\n C) Gangtok, Sikkim\n\n D) Dispur, Assam");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 31:
             system("cls");system("color f0");
             printf("\n Which of the following is the correct statement regarding the Navika Sagar Parikrama Project, 2017?\n");
             printf("\n A) First Indian Circumnavigation of the globe by an all women crew\n\n B) First global navigation of oceans by Indian men\n\n C)First navigation of seas and oceans by Indians\n\n D)First international circumnavigation");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 32:
             system("cls");system("color 0f");
             printf("\n Name the 70-year-old lady from Odisha who was awarded the Padmashri award for her work of preserving of hundreeds of types of paddy seeds throughout her life?\n");
             printf("\n A) S. Thimmakka\n\n B) Kamala Pujari\n\n C) Harika Dronavailli\n\n D)Muktaben Pankajkumar Dagli");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 33:
             system("cls");system("color f0");
             printf("\n The Frank Worrell Trophy is a test-match (cricket) series played between Australia and -\n");
             printf("\n A) West Indies\n\n B) Australia\n\n C) England\n\n D) New Zealand");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                 reduce(ch2);k++;k3++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 34:
             system("cls");system("color 0f");
             printf("\n Ekaterina Paltceva and Manju Rani both are associated with the sport of -\n");
             printf("\n A) Badminton\n\n B) Basketball\n\n C) Baseball\n\n D) Boxing");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 35:
             system("cls");system("color f0");
             printf("\n The Asian Amateur Boxing Championships' 2019 was held in -\n");
             printf("\n A) Delhi, India\n\n B) Moscow, Russia\n\n C) Bangkok, Thailand\n\n D)Nur-Sultan, Kazakhstan");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 36:
             system("cls");system("color 0f");
             printf("\n Former Olympic Champion, 28 year old Li Xuerul who announced (in October 2019) her retirement, was associated with -\n");
             printf("\n A) Baseball\n\n B) Boxing\n\n C) Softball\n\n D) Badminton");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 37:
             system("cls");system("color f0");
             printf("\n Salwa Eid Nasser has won the gold medal in the 400 m women's race for 2019 IAAF World Athletics Championships. She is from which country?\n");
             printf("\n A) Kenya\n\n B) Kuwait \n\n C) Peru\n\n D) Bahrain");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                  goto wrong;}
             continue;

        case 38:
             system("cls");system("color 0f");
             printf("\n What was the mascots for the 2017 FIFA Under-17 World Cup Football Tournament played in India?\n");
             printf("\n A) SHERA\n\n B) BHOLU\n\n C) KHELEO\n\n D) APPU");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 39:
             system("cls");system("color f0");
             printf("\n Which one of the following districts does not have Dharwar geological formations?\n");
             printf("\n A) Munger\n\n B) Rohtas\n\n C) Jamui\n\n D) Nawada");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 40:
             system("cls");system("color 0f");
             printf("\n Among the following countries, which one is the largest producer of saffron in the world?\n");
             printf("\n A) spain\n\n B) Greece\n\n C) New zealand\n\n D) Iran");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 41:
             system("cls");system("color f0");
             printf("\n UN-Habitat is the United Nations programme working towards a better urban future. Where is the headquarters of UN-Habitat?\n");
             printf("\n A) Johannesburg, South Africa\n\n B) Nairobi, Kenya\n\n C) Brasilia, Brazil\n\n D) Tokyo, Japan");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 42:
             system("cls");system("color 0f");
             printf("\n Who is the only person to win two individual Nobel Prizes, not shared with anyone else?\n");
             printf("\n A) Marie Curie\n\n B) Linus Pauling\n\n C) Hermann Muller\n\n D) Werner Heisenberg");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 43:
             system("cls");system("color f0");
             printf("\n Which company makes the Rafael fighter jets?\n");
             printf("\n A) Lokheed Martin\n\n B) Leonardo\n\n C) Dassault Aviation\n\n D) Raytheon Aircraft");
             ch2='C';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='C')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='C'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 44:
             system("cls");system("color 0f");
             printf("\n Which among these is also known as the \"Mountain Man\", for having carved a 110 m long road through the Gehlour Hill in Bihar? \n");
             printf("\n A) Birsa Munda\n\n B) Dashrath Manjhi\n\n C) Jalandhar Nayak\n\n D) Baba Bajrang Das");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

         case 45:
             system("cls");system("color f0");
             printf("\n Which freedom fighter is known as the Father of the Indian Petroleum industry?\n");
             printf("\n A) Keshav Dev Malaviya\n\n B) Kailash Nath Katju\n\n C) Nityananda Kanungo\n\n D) Sardar Swarna Singh");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 46:
             system("cls");system("color 0f");
             printf("\n In India which case was heard by the largest ever constitution bench of 13 supreme court judges? \n");
             printf("\n A) Golaknath Case \n\n B) Ashoka Kumar Thakur Case \n\n C) Shah Bano Case \n\n D) Keshvananda Bharti Case");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 47:
             system("cls");system("color f0");
             printf("\n Which Air force officer had the unique honour of leading the fly-post over the Red fort in Delhi on 15 August 1947?\n");
             printf("\n A) Arjan Singh \n\n B) Pratap Chandra Lal \n\n C) Subroto Mukerjee \n\n D) Aspy Engineer");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 48:
             system("cls");system("color 0f");
             printf("\n Who was the first woman to score a century in international T20 cricket? \n");
             printf("\n A) Deandra Dottin \n\n B) Shanel Daley \n\n C) Stacy-Ann King \n\n D) Cordel Jack");
             ch2='A';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='A')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='A'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


        case 49:
             system("cls");system("color f0");
             printf("\n Which is the largest passenger airliner in the world? \n");
             printf("\n A) Boeing 767\n\n B) Airbus A380 \n\n C) Ilyushin IL-96 \n\n D) Boeing 787");
             ch2='B';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='B')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='B'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;

        case 50:
             system("cls");system("color 0f");
             printf("\n Which toxic gas was first to be used in chemical warfare in World War 1?\n");
             printf("\n A) Hydrogen Sulphide \n\n B) Carbon Monoxide \n\n C) Nitrogen Dioxide \n\n D) Chlorine");
             ch2='D';
             if(k%2==1)
             {display1(p1f1,p1f2,p1f3);printf("\n\n %s Enter your choice: ",player1_name);}
             if(k%2==0)
             {display2(p2f1,p2f2,p2f3);printf("\n\n %s Enter your choice: ",player2_name);}
             call();
             choice=toupper(getch());
             if(choice=='D')
             {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                k++;
                k3++;
                getch();
             }
             if(choice=='Q')
             {
                reduce(ch2);k++;k3++;
             }
             if((choice!='D'&&choice!='Q')||res==-100){
                 goto wrong;}
             continue;


            }
        }
        if(k3>=50)
            k3=1;
        store_value(k1,k2,k3);

	result:
	    system("color f5");
	    system("cls");
	    if(k%2==0)
	    {
	        printf("\n\n\t!!! %s is the \"WINNER\" !!! ",player1_name);
	        printf("\n\n\t Score :\n\n\t\t%s scored %d points",player1_name,k/2);
	        printf("\n\t\t%s scored %d points",player2_name,k/2-1);
	    }
	    else
	     {
	        printf("\n\n\t!!! %s is the \"WINNER\" !!! ",player2_name);
	        printf("\n\n\t Score :\n\n\t\t%s scored %d* points",player2_name,k/2);
	        printf("\n\t\t%s scored %d points",player1_name,k/2);
	    }
	    printf("\n\n   Press any key to go to mainhome.....");
	    getch();
        goto mainhome;
    }
    return 1;
}

void show_record() //to view the highest score
    {system("cls");
    int max;
	FILE *f;
	f=fopen("max.txt","r");
	fscanf(f,"%d",&max);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t The Highest Score is of %d points!",max);
	printf("\n\n\t\t*************************************************************");
	fclose(f);
	getch();}

void reset_score() //to reset the score back to 0
    {system("cls");
	FILE *f;
	f=fopen("max.txt","w");
	fprintf(f,"%d",0);
    fclose(f);}

void help()  // to display help menu
	{system("cls");
    printf("\n\n Here are some rules and tips you might need to know before getting started:");
    printf("\n ----------------------------------------------------------------------------");
    printf("\n >> This battle consist of 30 questions,15 questions each for each player.\n");
    printf("\n >> These questions are divided into three sections : Easy, Medium and Hard!");
    printf("\n    First 10 questions will be of EASY level next 10 will be of MEDIUM level");
    printf("\n    and rest 10 will be of HARD level.\n");
    printf("\n >> Both players will be asked continous questions, for each correct answer");
    printf("\n    player will be awarded with 1 point !\n");
    printf("\n >> Each player will be provided with 3 LIFELINES you will get information about");
    printf("\n    LIFELINES on next page.\n");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option.\n");
    printf("\n >> If anyone choose the incorrect option,he/she will be eliminated!\n");
    printf("\n\n * Press N to go to the next page! *\n");
    printf("\n * Press any other key to return to the main menu! *");
	}
void edit_score(float score, char plnm[20]) //to edit the highest score
	{system("cls");
	float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	if (score>=sc)
	  { sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2f",plnm,sc);
	    fclose(f);}}

void battle_log()
{
    FILE *fp;
    char ch;
    system("cls");
    fp=fopen("battle_log.txt","r");
    ch=fgetc(fp);
    while(!feof(fp))
    {
        printf("%c",ch);
        ch=fgetc(fp);
    }
    fclose(fp);

}


void display1(int p1f1,int p1f2,int p1f3 )// to show the lifelines left with the player 1
{
    printf("\n\n\n >>>>> Lifelines left are : ");
    if(p1f1==1)
        printf("1.JEEVAN   ");
    if(p1f2==1)
        printf("\t 2.SKIPPER");
    if(p1f3==1)
        printf("\t3.COUNTLESS");
    printf("\n\n >>>>> NOTE : Enter Q to use  lifeline! <<<<<\n");
}


void display2(int p2f1,int p2f2,int p2f3) // to show the lifelines left with player 2
{
    printf("\n\n\n >>>>> Lifelines left are : ");
    if(p2f1==1)
        printf("1.JEEVAN   ");
    if(p2f2==1)
        printf("\t 2.SKIPPER");
    if(p2f3==1)
        printf("\t3.COUNTLESS");
    printf("\n\n >>>>> NOTE : Enter Q to use  lifeline! <<<<<\n");
}


void store_value(int k1,int k2,int k3) // we used file handling and stored the value of k1,k2,k3..so that when new pair of players will enter the game the quiz will start with new questions
{
    system("cls");
    FILE *f;
    f=fopen("store.txt","w");
    fprintf(f,"%d\n%d\n%d",k1,k2,k3);
    fclose(f);
}


int k1_value()  // to retrieve back the value of k1 which stored in last battle
{
    FILE *fp;
    int k1,k2,k3;
    fp=fopen("store.txt","r");
    fscanf(fp,"%d%d%d",&k1,&k2,&k3);
    fclose(fp);
    return k1;
}

int k2_value() // to retrieve back the value of k2 which stored in last battle
{
    FILE *fp;
    int k1,k2,k3;
    fp=fopen("store.txt","r");
    fscanf(fp,"%d%d%d",&k1,&k2,&k3);
    fclose(fp);
    return k2;
}


int k3_value() // to retrieve back the value of k3 which stored in last battle
{
    FILE *fp;
    int k1,k2,k3;
    fp=fopen("store.txt","r");
    fscanf(fp,"%d%d%d",&k1,&k2,&k3);
    fclose(fp);
    return k3;
}




int lifeline1(char a,int p1f1,int p1f2,int p1f3) //lifelines used for player 1
{
    int opt;
	printf("\n\n Enter the required lifeline:");
    scanf("%d",&opt);
	switch (opt)
        {
        if(p1f1==1){
        case 1:

            printf("\n\nEnter your first choice:");
            if(toupper(getch())!=a)
            {
                printf("\n\n oops!you selected incorrect option select another option!");
                printf("\n\nEnter your another choice:");
                if(toupper(getch())!=a)
                {
                    return -100;
                }
                else
                {
                    printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                    getch();
                    return 11;
                }
            }
            else
            {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                getch();
                return 11;
                break;
            }
        }
        else
            printf("\nYOU HAVE ALREADY USED THIS LIFELINE");
        if(p1f2==1)
        {
            case 2:
                return 12;
        }
        else
            printf("\nYOU HAVE ALREADY USED THIS LIFELINE");

       if(p1f3==1)
       {
            case 3:
                printf("\n Enter your choice :");
                if(toupper(getch())==a)
                {
                    printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                    getch();
                    return 13;
                }
                else
                {
                    return -100;
                }
       }
    }
}
int lifeline2(char a,int p2f1,int p2f2,int p2f3) //lifeline used for player 2
{
    int opt;
	printf("\n\n Enter the required lifeline:");
    scanf("%d",&opt);
	switch (opt)
    {
        if(p2f1==1)
        {
        case 1:

            printf("\n\nEnter your first chice:");
            if(toupper(getch())!=a)
            {
                printf("\n\n oops!you selected incorrect option select another option!");
                printf("\n\nEnter your another choice:");
                if(toupper(getch())!=a)
                {
                  return -100;
                }
                else
                {
                    printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                    getch();
                    return 21;
                }
            }
            else
            {
                printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                getch();
                return 21;
                break;
            }
        }
        else
            printf("\nYOU HAVE ALREADY USED THIS LIFELINE");
        if(p2f2==1)
        {
            case 2:
                return 22;
        }
        else
            printf("\nYOU HAVE ALREADY USED THIS LIFELINE");

        if(p2f3==1)
        {
            case 3:
                printf("\n Enter your choice :");
                if(toupper(getch())==a)
                {
                    printf("\n\n\t\t   !!!Your answer is Correct!!!\n\n Press enter to go to next question....!");
                    getch();
                    return 23;
                }
                else
                {
                    return -100;
                }
        }
    }
}

void out()  //when time limit exceeded it will take player outside
{
    system("cls");
    printf("\n\n You did not enter any option!You are eliminated!");
    exit(1);
}

void max(int p) //to store value of max questions so;ved
{
    int z=p,max;
    FILE *fp;
    fp=fopen("max.txt","r");
    fscanf(fp,"%d",&max);
    fclose(fp);
    if(z/2>max)
    {
    	max=(z/2);
    	fp=fopen("max.txt","w");
    	fprintf(fp,"%d",max);
    	fclose(fp);
   }
}
