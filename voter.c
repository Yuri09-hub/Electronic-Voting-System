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
		strcpy(node->status,"not Voted");
		node->next = list;
		if(list == NULL)
		list = node;
		else{
		node->next = list;
		list = node;
		}
	}
	else
		printf("Allocation error");
	return list;
}
voter* update_voter_information(voter*list,char name[50],int id){
	voter* aux = list;
        while (aux != NULL ) {
            if (aux->id == id) {
				printf("found");
                strcpy(aux->nome,nome);
                return list;
            }
            aux = aux->next;
        }
	printf("Not found");
    return list;
}
void print_voter(voter*list){
	if (lista==NULL) {
		printf("Empty list");
		return;
	}
    else {
        voter* aux = lista;
        while (aux != NULL) {
            printf(" %s %d %d\n",aux->name,aux->id,aux->status);
            aux = aux->next;
        }
    }

}

void free_voter_list(voter*list) {
	if (list==NULL) {
		printf("Empty list");
		return;
	}
	free_voter(list->next);
	free(list);
}