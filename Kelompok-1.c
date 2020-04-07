/*  Kelompok 1
    13218022 - Danu Ihza Pamungkas
    13218015 - Reihan Augeetiansyah
    13218026 - Ilham Rayhan
    13218012 - Ratu Raihan Amany
    13218003 - Feroz Fernando

    Program Simulasi Conways Game of Life
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char kondisi;
    struct node* topleft;
    struct node* topright;
    struct node* top;
    struct node* left;
    struct node* right;
    struct node* bottomleft;
    struct node* bottomright;
    struct node* bottom;
}node;

void readFile(char namaFile[64]){

}

int iterasi(struct node**head){

}

void printData(struct node*head){

}

int main(){
    struct node* head=NULL;
    char namafile[64];
    printf("Input nama file: ");
    scanf("%s",&namafile);
    readFile(namafile);
    printData(head);
    //while(){
        iterasi(&head);
        printData(head);
    //}
}