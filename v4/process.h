/**Library untuk pemrosesan utama : pembacaan file, iterasi, dan pencetakan.**/
#ifndef Process_H
#define Process_H

#define MAX 100

char file[MAX]="";
char arr[100][100];
char temp[100][100];
int kolom,baris;

void delay(int milli_seconds){                      ///Fungsi untuk menciptkan jeda
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
    ;
}

void readFile(FILE*fp){                             ///Fungsi untuk membaca file
    char str[50];
    char c;

    /// Baca kolom & baris
    fgets (str, 50, fp);
    baris=atoi(str);
    fgets (str, 50, fp);
    kolom=atoi(str);

    ///Read data
    for(int i=0;i<baris;i++){
        for(int j=0;j<kolom+1;j++){
            c=fgetc(fp);
            arr[i][j]= c;
        }
    }
}

void insertFile(FILE *fp){                          ///Fungsi untuk menampilkan file yang dibaca
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


int lifeCheck(char temp){                           ///Memeriksa sel hidup atau mati. X hidup, - Mati.
    if (temp == 'X'){
        return 1;
    }else{
        return 0;
    }
}

int hitungTetangga(int loc_r, int loc_c){           ///Menghitung tetangga dari elemen array baris loc_r dan kolom loc_c
    int total = 0;
    int i,j,A,B;                                    ///i dan j : variabel iterasi. A dan B : variabel untuk implementasi array toroidal

    for(i=loc_r-1; i<=loc_r+1; i++){                /// Cek baris atas dan bawah
        for(j = loc_c-1; j <= loc_c+1; j++){        /// Cek kolom kiri dan kanan
            if(i != loc_r || j != loc_c){           /// Exclude elemen array utama yang dicek tetangganya untuk iterasi
                ///IMPLEMENTASI ARRAY TOROIDAL
                A = i;
                B = j;
                if(i < 0){                          /// Jika elemen merupakan baris paling atas, ubah posisi elemen yang diperiksa
                    A = baris-1;                    /// menjadi elemen baris paling bawah di kolom yang sama
                }
                if(i > baris-1){                    /// Jika elemen merupakan baris paling bawah, ubah posisi elemen yang diperiksa
                    A = 0;                          /// menjadi elemen baris paling atas di kolom yang sama
                }
                if(j < 0){                          /// Jika elemen merupakan kolom paling kiri, ubah posisi elemen yang diperiksa
                    B = kolom-1;                    /// menjadi elemen kolom paling kanan di baris yang sama
                }
                if(j > kolom-1){                    /// Jika elemen merupakan kolom paling kanan, ubah posisi elemen yang diperiksa
                    B = 0;                          /// menjadi elemen kolom paling kiri di baris yang sama
                }
                total += lifeCheck(arr[A][B]);      /// Periksa kondisi elemen dan menambahkan ke variabel total tetangga
            }
        }
    }
    return total;
}

void copyTemp(){                                    ///Assign nilai array temporary ke array untuk dicetak
    int i,j;
    for(int i=0;i<baris;i++){
        for(int j=0;j<kolom+1;j++){
            arr[i][j]=temp[i][j];
        }
    }
}

void nextGen(){                                     ///Menentukan generasi untuk tick selanjutnya kedalam array temporary
    int i,j,sumTetangga = 0;
    for(i = 0; i< baris; i++){                      ///Menelusuri seluruh elemen array
        for(j= 0; j < kolom+1; j++){
            sumTetangga = hitungTetangga(i,j);      ///Mendapatkan jumlah tetangga
            temp[i][j]=arr[i][j];

            ///Assign nilai untuk generasi selanjutnya berdasarkan aturan

            if (lifeCheck(arr[i][j])){              ///Jika sel hidup
                if(sumTetangga <= 1){
                    temp[i][j] = '-';               ///Sel menjadi mati karena underpopulation
                } else if (sumTetangga >= 4){
                    temp[i][j] = '-';               ///Sel menjadi mati karena overpopulation
                }
            } else if (!lifeCheck(arr[i][j])){      ///Jika sel mati
                if (sumTetangga == 3){
                    temp[i][j] = 'X';               ///Life
                }
            }
        }
    }
    copyTemp();                                     ///Memasukkan data kedalam array untuk dicetak
}

void printArr(int *gen){                            ///Mencetak array
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

void tick(int*gen){                                 ///Mencetak 1 elemen selanjutnya
    *gen += 1;
    nextGen();
    system("cls");
    printArr(gen);
}


void animate(int n, int*gen){                       ///"Menganimasikan" sesuai input user dengan jeda 250 ms
    int i;
    system("cls");
    for (i =0; i <n; i++){
        system("cls");
        tick(gen);
        delay(250);
    }
}

#endif
