//
// Created by Yuri Rodrigues on 26/01/2026.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include " candidate.h"

candidate* init_candidate(){
    return NULL;
}

// register
candidate *register_candidate(candidate* list,char *name, int id, int number_of_votes){
           candidate* new_candidate = (candidate*)malloc(sizeof(candidate));
            if(new_candidate== NULL){
            printf("Error in memory allocation\n");
            return NULL;}

            strcpy(new_candidate->name,name);
            new_candidate->id = id;
            new_candidate->number_of_votes = number_of_votes;
            new_candidate->prev = NULL;
            new_candidate->next = list;
            if(list == NULL){
            list-> prev = new_candidate;
            }
            list = new_candidate;
            return list;
}

// remove
candidate* remove_candidate(candidate *list,int id){
            candidate* aux = list;
            while(aux != NULL) {

                if(aux-> id == id) {
                    if (aux->prev == NULL )
                        aux -> prev->next = aux->next;
                    else
                        list = aux->next;
                    if (aux->next == NULL)
                        aux->next->prev = aux->prev;

                    free(aux);
                    return list;
                }
                aux = aux->next;
            }
            printf("Error: id not found\n");
            return list;
}

int search_candidate(candidate *list, int id);

// print
void print_candidate_list(cadidate* list);
