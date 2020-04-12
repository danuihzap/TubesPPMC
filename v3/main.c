#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include <time.h>
#include "process.h"
#include "interface.h"

int main()
{
    char tmp;
    int choice,n;
    int start=0,number,end=0,gen=0;
    FILE *file;
    system("cls");
    title();
    delay(2000);
    system("cls");
    tmp = rules();
    system("cls");
    tmp = howto();
    system("cls");
    tmp = Begin();
    insertFile(file);
    system("cls");
    printArr(&gen);
    printf ("\n");
    while (end==0){
        choice = tampilan_awal();
        switch(choice)
        {
            case 1:
                tick(&gen);
	        break;
            case 2:
                printf("Number of animate iteration : ");
                scanf("%d", &n);
                animate(n,&gen);
            break;
            case 3:
                start = 0;
                while (start==0)
                {
                system("cls");
                number = close();
                    if(number==1)
                    {
                        start=1;
                        insertFile(file);
                        system("cls");
                        gen = 0;
                        printArr(&gen);
                        printf ("\n");
                    }
                    else if (number ==2)
                    {
                        system("cls");
                        thanks();
                        delay(1000);
                        start=1;
                        end=1;
                    }
                    else
                    {
                        system("cls");
                        start=0;
                        printf("Invalid number! Try again \n");
                        delay(500);
                    }
                }
                break;
            default:
	    printf("Invalid number! Try again \n");
	    break;
        }
    }
}