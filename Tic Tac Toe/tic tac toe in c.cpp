#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int main();

char array[20];
int k=0,z=1;

void space(){printf("\t|");}

void line(){printf("\n---------------------\n");}

void column(){
    printf("|");
    if(++k==4){
        printf("\n");
        k=0;
    }
}

void printTitle(){
    printf("A simple Tic tac toe\n\tShubho, First Semester (11-Feb-2014)\n");
    printf("\nuse\n1\t2\t3\n\n4\t5\t6\n\n7\t8\t9\n\nto fill these empty boxes");
}

void printTable(){
    system("cls");
    printTitle();

    int zz;
    line();
    for(int i=0; i<9; i++){zz=i+1;
            if(i%3==0 && i>1) {line();}
        //column();
        if(array[zz]=='N')
            printf("      |");
        else if(array[zz]!='N')
            printf("  %c   |",array[zz]);
    }
    line();/*
    printf(""\nold one\n";
    printf(""|\t|\t|\t|\n|\t|\t|\t|\n";
    printf(""-------------------------\n";
    printf(""|\t|\t|\t|\n|\t|\t|\t|\n";
    printf(""-------------------------\n";
    printf(""|\t|\t|\t|\n|\t|\t|\t|\n";
    printf(""-------------------------\n";
    */


}

void check(){
    int flag=0;
    printTable();
    if(flag!=-1){
        if(((array[1]==array[2])&&(array[1])==array[3])||((array[1]==array[4])&&(array[1]==array[7]))||((array[1]==array[5])&&(array[1]==array[9])))
            if(array[1]!='N'){printf("%c - won\n",array[1]);flag=1;}

    if((array[2] == array[5])&&(array[2] == array[8]))
        if(array[2]!='N'){printf("%c - won\n",array[2]);flag=1;}


    if(((array[3] == array[6]) &&(array[3]==array[9]))||((array[3]==array[5])&&(array[3]== array[7])))
        if(array[3]!='N'){printf("%c - won\n",array[3]);flag=1;}


    if((array[4] == array[5])&&(array[5] == array[6]))
       if(array[4]!='N'){printf("%c - won\n",array[4]);flag=1;}


    if((array[7] == array[8])&&(array[8] == array[9]))
         if(array[7]!='N'){printf("%c - won\n",array[5]);flag=1;}

    }

    if(flag==1){
        printf("\ndo you want to play again? y/n: ");
        char ch;
        ch=getch();
        if(ch=='y')main();
        else
            exit(1);
        }
    z++;

}

int main(){
    char ch;
    int l;
    for(int i=0; i<10; i++)
        array[i]='N';
    printTable();
    for(int qq=0; qq<9; qq++){
        ch=getch();
        l = ch-'0';
        l++;
        if(z%2!=0)
            ch='x';
        else
            ch='0';
            if(array[--l]!='N'){
                    printf("you can not put here\ntry again");--qq;z++;
                   array[--l]='N';
                   getchar();
            }
        array[l]=ch;
        check();
    }

    return 0;

}

