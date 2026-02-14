//
// Created by Yuri Rodrigues on 26/01/2026.
//

#include "voter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


voter* initialize_register_voter(){
	return NULL;
}
voter* register_voter(voter* list,char name[50], int id){
	voter* node = (voter*)malloc(sizeof(voter));
	if(node){

		strcpy(node->name,name);
		node->id = id;
		node->status =0;
		node->next = list;
		if(list == NULL)
		list = node;
		else{
		node->next = list;
		list = node;
		}
		printf("successfully registered");
	}
	else
		printf("Allocation error");
	return list;
}
voter* update_voter_information(voter*list,char name[50],int id){
	voter* aux = list;
        while (aux != NULL ) {
            if (aux->id == id) {
				printf("edited");
                strcpy(aux->name,name);
                return list;
            }
            aux = aux->next;
        }
	printf("Not found");
    return list;
}
int search_voter(voter* list,int id) {
	if(list == NULL) {
		printf("List is empty");
		return 0;
	}
	voter* aux = list;
	while (aux != NULL) {
		if (aux->id == id) {
			printf("found");
			return 1;
		}
		aux = aux->next;
	}
	printf("Not found");
	return 0;
}

int length_voter(voter* list) {
	if (list == NULL)
		return 0;
	voter* aux = list;
	int count = 0;
	while (aux != NULL) {
		count++;
		aux = aux->next;
	}
	return count;
}

void print_voter(voter*list){
	if (list==NULL) {
		printf("Empty list");
		return;
	}
    else {
        voter* aux = list;
        while (aux != NULL) {
            printf(" %s %d %d\n",aux->name,aux->id,aux->status);
            aux = aux->next;
        }
    }

}

//free
void free_voter_list(voter*list) {
	if (list==NULL) {
		printf("Empty list");
		return;
	}
	voter* aux = list;
	while (aux != NULL) {
		list = list->next;
		free(aux);
		aux = list;
	}
	list = NULL;
}