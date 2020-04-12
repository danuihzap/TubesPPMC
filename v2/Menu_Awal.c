#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include <time.h>
#include "process.c"

#define MAX 100
int tampilan_awal(void)
{
    int n;

    printf("\n                  GAME OF LIFE\n");
	printf(" =====================================================\n");
	printf("             1- Tick             \n");
	printf("             2- Animate          \n");
	printf("             3- Quit             \n");
	printf(" =====================================================\n");
	printf("Enter your choice : "); scanf("%d",&n);
	return n;
}

void insertFile(FILE *fp, int *repeat){
    do
    {
        char file[MAX]="";
        printf("Insert file : ");
        scanf("%s",file);
        FILE *fp = fopen(file, "r");
        if (!fp)
        {
            printf("Can't open file, Try again \n");
            *repeat=0;
        }
        else
        {
            readFile(fp);
            fclose(fp);
            *repeat=1;
        }
    }while(repeat==0);
}


int main()
{
    int choice,x,n;
    int start=0,number,repeat=0;

    FILE *file;
    insertFile(file, &repeat);
    printf ("Gen 0 : \n");
    printf ("%d\n%d\n",baris,kolom);
    printArr();
    printf ("\n");
    while (x!=3){
        choice = tampilan_awal();
        switch(choice)
        {
            case 1:
                tick();
	        break;
            case 2:
                printf("Number of animate iteration : ");
                scanf("%d", &n);
                animate(n);
            break;
            case 3:
                start = 0;
                while (start==0)
                {
                printf("Insert a new file? \n");
                printf("1.Yes       2.No \n");
                printf("Enter your choice : "); scanf("%d",&number);
                    if(number==1)
                    {
                        start=1;
                        insertFile(file, &repeat);
                        printf ("Gen 0 : \n");
                        printf ("%d\n%d\n",baris,kolom);
                        printArr();
                        printf ("\n");
                    }
                    else if (number ==2)
                    {
                        printf("Thanks for playing! \n");
                        start=1;
                        x=3;
                    }
                    else
                    {
                        start=0;
                        printf("Invalid number! Try again \n");
                    }
                }
                break;
            default:
	    printf("Invalid number! Try again \n");
	    break;
        }
    }
}

