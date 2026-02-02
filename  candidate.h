//
// Created by Yuri Rodrigues on 26/01/2026.
//

#ifndef CANDIDATE_H
#define CANDIDATE_H
typedef struct node{
    char name[50];
    int id;
    int number_of_votes;
    struct node *next;
    struct node *prev;
}candidate;


candidate* init_candidate();

// register
candidate *register_candidate(candidate* list,char *name, int id, int number_of_votes);

// remove
candidate* remove_candidate(candidate *list);

int search_candidate(candidate *list, int id);

// print
void print_candidate_list(candidate* list);


#endif //CANDIDATE_H
