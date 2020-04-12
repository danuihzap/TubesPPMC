char arr[100][100];
char temp[100][100];
int kolom,baris;

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
            //printf("%c",c);
        }
    }
}

int lifeCheckTest(char temp, int baris, int kolom){
    if (temp == 'X'){
        printf("(%d,%d) Found \n",baris,kolom);
        return 1;
    }else{
        printf("(%d,%d)\n",baris,kolom);
        return 0;
    }
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



void printArr(){
    int i,j;
    for(i = 0; i<=baris; i++){
        for(j= 0; j <= kolom+1; j++){
            printf("%c",arr[i][j]);
        }
    }
}

void tick(){
    nextGen();
    printArr();
}


void delay(int milli_seconds)
{

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
    ;
}

void animate(int n){            /// n = number of iteration
    int i;
    system("cls");
    for (i =0; i <n; i++){
        system("cls");
        tick();
        delay(250);
    }
}
