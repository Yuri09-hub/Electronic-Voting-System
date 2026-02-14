//
// Created by Yuri Rodrigues on 26/01/2026.
//

#ifndef QUEUE_VOTE_H
#define QUEUE_VOTE_H
#include "voter.h"

typedef struct {
    voter* head;
    voter* end;
}queue_vote;

queue_vote* initialize_queue_vote();
queue_vote* add(queue_vote* queue,voter* node);
queue_vote* remove_element(queue_vote* queue);
queue_vote* leave_queue(queue_vote*queue, int id);
int len_of_queue(queue_vote* queue);
int search_in_queue(queue_vote* queue1,queue_vote*queue2,queue_vote*queue3,int id);
void print_queue(queue_vote* queue);
void distribute_queue(voter* list, queue_vote** queue1, queue_vote**queue2,queue_vote** queue3);
void free_queue(queue_vote* queue);
void print_current(queue_vote*queue);

#endif //QUEUE_VOTE_H
