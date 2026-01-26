//
// Created by Yuri Rodrigues on 25/01/2026.
//

#ifndef VOTER_H
#define VOTER_H
typedef struct node{
    char name[50];
    int id;
    char status[20];
    struct node *next;
}voter;

voter* initialize_register_voter();
voter* register_voter(voter* list,char name[50], int id);
voter* update_voter_information(char name[50],int id);
void print_voter(voter*list);
#endif //VOTER_H
