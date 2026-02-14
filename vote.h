//
// Created by Yuri Rodrigues on 11/02/2026.
//

#ifndef VOTE_H
#define VOTE_H
#include " candidate.h"
typedef struct  {
    int id;
    int hour, minute;
    int day, month, year;
    struct node *next;
}node;

typedef struct {
    node *head;
}vote;

vote*creat_voter_box();
vote*add_voter_box(vote*box,int id,int hour,int minute,int day,int month,int year);
int count(vote* box);
int date_verification(int day,int month,int year);
int time_verification(int hour,int minute);
int blank_vote(int id);
int null_vote(vote* box,candidate*list,int id);
int valid_vote(vote* box, candidate*list,int id);

#endif //VOTE_H
