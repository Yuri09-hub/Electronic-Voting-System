//
// Created by Yuri Rodrigues on 26/01/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "voter.c"

    void display_menu(){
        printf("\n");
        printf("   _______________________________________________ \n");
        printf("  |          VOTING SYSTEM MANAGER                |\n");
        printf("  |_______________________________________________|\n");
        printf("  |  1.Register voter                             |\n");
        printf("  |  2.update voter                               |\n");
        printf("  |  3.Register candidate                         |\n");
        printf("  |  4.Remove candidate                           |\n");
        printf("  |  5.Initialize vote                            |\n");
        printf("  |  6.Voter Leave queue (give up)                |\n");
        printf("  |  7.Show Queue Size                            |\n");
        printf("  |  9.Pri                                        |\n");
        printf("  |  8.Vote                                       |\n");
        printf("  |  8.Vote                                       |\n");
        printf("  |  0. Exit                                      |\n");
        printf("  |_______________________________________________|\n");
        printf("  Selection > ");
}

int main(){
char nome[10] = {'Y','U',};
int id = 0;
voter* list = initialize_register_voter();
list = register_voter(list,nome,id);



}