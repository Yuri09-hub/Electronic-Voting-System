//
// Created by Yuri Rodrigues on 26/01/2026.
//

#ifndef CANDIDATE_H
#define CANDIDATE_H
typedef struct candidate{
    char name[50];
    int id;
    int number_of_votes;
    struct candidate *next;
    struct candidate *prev;
}candidate;


candidate* init_candidate();

// register
candidate *register_candidate(candidate* list,char *name, int id, int number_of_votes);

// remove
candidate* remove_candidate(candidate *list,int id);

int search_candidate(candidate *list, int id);
int len_candidate(candidate *list);

// print
void print_candidate_list(candidate* list);

void free_candidate_list(candidate* list);


#endif //CANDIDATE_H
