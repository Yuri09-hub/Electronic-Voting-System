//
// Created by Yuri Rodrigues on 25/01/2026.
//

#ifndef VOTER_H
#define VOTER_H
typedef struct node{
    char name[50];
    int id;
    bool status;
    struct node *next;
}voter;


#endif //VOTER_H
