#ifndef Process_H
#define Process_H

#define MAX 100

char file[MAX]="";
char arr[100][100];
char temp[100][100];
int kolom,baris;

void delay(int milli_seconds){
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
    ;
}

void readFile(FILE*fp){
    char str[50];
    char c;

    // Baca kolom & baris
    fgets (str, 50, fp);
    baris=atoi(str);
    fgets (str, 50, fp);
    kolom=atoi(str);

    /* Read data*/
    for(int i=0;i<baris;i++){
        for(int j=0;j<kolom+1;j++){
            c=fgetc(fp);
            arr[i][j]= c;
        }
    }
}

void insertFile(FILE *fp){  
    int repeat = 0;
    do
    {
        system("cls");
        printf("=======================================================\n");
        printf("        Please insert the initial setup file\n");
        printf("=======================================================\n");
        printf("Setup File : ");
        scanf("%s",file);
        FILE *fp = fopen(file, "r");
        if (!fp)
        {
            system("cls");
            printf("=======================================================\n");
            printf("            Can't open file, Try again \n");
            printf("=======================================================\n");
            delay(1000);
            repeat=0;
        }
        else
        {
            readFile(fp);
            fclose(fp);
            repeat=1;
        }
    }while(repeat==0);
}


int lifeCheck(char temp){
    if (temp == 'X'){
        return 1;
    }else{
        return 0;
    }
}

int hitungTetangga(int loc_r, int loc_c){
    int total = 0;
    int i,j,A,B;

    for(i=loc_r-1; i<=loc_r+1; i++){
        for(j = loc_c-1; j <= loc_c+1; j++){
            if(i != loc_r || j != loc_c){
                A = i; B= j;
                if(i < 0){
                    A = baris-1;
                }
                if(i > baris-1){
                    A = 0;
                }
                if(j < 0){
                    B = kolom-1;
                }
                if(j > kolom-1){
                    B = 0;
                }
                total += lifeCheck(arr[A][B]);
            }
        }
    }
    return total;
}

void copyTemp(){
    int i,j;
    for(int i=0;i<baris;i++){
        for(int j=0;j<kolom+1;j++){
            arr[i][j]=temp[i][j];
        }
    }
}

void nextGen(){
    int i,j,sumTetangga = 0;
    for(i = 0; i< baris; i++){
        for(j= 0; j < kolom+1; j++){
            sumTetangga = hitungTetangga(i,j);
            temp[i][j]=arr[i][j];
            if (lifeCheck(arr[i][j])){
                if(sumTetangga <= 1){
                    temp[i][j] = '-'; //DIE
                } else if (sumTetangga >= 4){
                    temp[i][j] = '-'; //DIE
                }
            } else if (!lifeCheck(arr[i][j])){
                if (sumTetangga == 3){
                    temp[i][j] = 'X'; //Life
                }
            }
        }
    }
    copyTemp();
}

void printArr(int *gen){
    int i,j;
    printf("=======================================================\n");
    printf("                Setup file : %s\n",file);
    printf("                Baris data : %d\n",baris);
    printf("                Kolom data : %d\n",kolom);
    printf("                Gen        : %d\n",*gen);
    printf("=======================================================\n");
    printf("\n");
    printf(" ");
    for(i = 0; i<=baris; i++){
        for(j= 0; j <= kolom+1; j++){
            printf("%c",arr[i][j]);
        }
    }
}

void tick(int*gen){
    *gen += 1;
    nextGen();
    system("cls");
    printArr(gen);
}


void animate(int n, int*gen){            
    int i;
    system("cls");
    for (i =0; i <n; i++){
        system("cls");
        tick(gen);
        delay(250);
    }
}

#endif