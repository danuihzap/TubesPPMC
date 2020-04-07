#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#define MAX 100
int main()
{
    int choice,x;
    int start=0,number,repeat=0;
    char file[MAX]="";

    while(repeat==0)
    {
        printf("Insert file : "); scanf("%s",&file);
        FILE *fp = fopen(file, "r");
        if (!fp)
        {
            printf("Can't open file, Try again \n");
            repeat=0;
        }
        else
        {
            //load_file()
            //print_file()
            repeat=1;
        }

    }

   while (x!=3)
    {
        choice = tampilan_awal();
        switch(choice)
        {
            case 1:
                //tick()
	        break;
	    case 2:
		//animate() delay()
		break;
            case 3:
                while (start==0)
                {
                printf("Insert a new file? \n");
                printf("1.Yes       2.No \n");
                printf("Enter your choice : "); scanf("%d",&number);
                    if(number==1)
                    {
                        start=1;
                        repeat=0;
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

int tampilan_awal(void)
{
    int n;

    	printf("                  GAME OF LIFE\n");
	printf(" =====================================================\n");
	printf("             1- Tick             \n");
	printf("             2- Animate          \n");
	printf("             3- Quit             \n");
	printf(" =====================================================\n");
	printf("Enter your choice : "); scanf("%d",&n);
	return n;
}

