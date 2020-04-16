/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 1
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Rizky Ardi Maulana (13217054)
* Nama File : main.c
* Deskripsi : Program Utama
*/

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include <time.h>
#include "process.h"
#include "interface.h"

int main()
{
	///KAMUS
    char tmp;							///Variabel untuk mengimplementasi fungsi interface
    int choice,n;
    int start=0,number,end=0,gen=0;
    FILE *file;
	
	///INTERFACE
    system("cls");
    title();
    delay(2000);
    system("cls");
    tmp = rules();						///Peraturan
    system("cls");
    tmp = howto();						///Cara penggunaan program
    system("cls");
    tmp = Begin();
    insertFile(file);
    system("cls");
    printArr(&gen);						///Cetak input file
    printf ("\n");
	
    while (end==0){
        choice = tampilan_awal();		///Mendapatkan input user
        switch(choice)
        {
            case 1:						///Tick
                tick(&gen);
	        break;
            case 2:						///Animate
                printf("Number of animate iteration : ");
                scanf("%d", &n);
                animate(n,&gen);
            break;
            case 3:						///Quit dan prompt input file baru
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