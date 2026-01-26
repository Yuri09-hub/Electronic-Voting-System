//
// Created by Yuri Rodrigues on 26/01/2026.
//

#ifndef CANDIDATE_H
#define CANDIDATE_H
typedef struct no {
    char name[50];
    int id;
    int number_of_votes;
    struct node *next;
}candidate;

candidate *create_candidate(char *name, int id, int number_of_votes);

#endif //CANDIDATE_H
