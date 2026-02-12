//
// Created by Yuri Rodrigues on 11/02/2026.
//

#ifndef VOTE_H
#define VOTE_H
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
vote*add_voter_box(int id,int hour,int minute,int day,int month,int year);
int count(vote* box);
vote* date_verification(int day,int month,int year);
vote* time_verification(int hour,int minute);

#endif //VOTE_H
