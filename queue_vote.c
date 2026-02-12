//
// Created by Yuri Rodrigues on 26/01/2026.
//

#include "queue_vote.h"
#include <stdio.h>
#include <stdlib.h>

queue_vote* initialize_queue_vote() {
    queue_vote* queue = (queue_vote*)malloc(sizeof(queue_vote));
    if (queue != NULL) {
        queue->head = NULL;
        queue->end = NULL;
    }else
        printf("Error in initialize_queue_vote\n");
    return queue;
}

queue_vote* add(queue_vote* queue,voter* node) {
    if (queue == NULL) {
        printf("error in add\n");
        return queue;
    }
    node->next = NULL;

    if (queue->head == NULL) {
        queue->head = node;
        queue->end = node;
    }else {
        queue->end->next = node;
        queue->end = node;
    }
    return queue;
}

queue_vote* remove(queue_vote* queue) {
    if (queue == NULL || queue->head == NULL) {
        printf(" empty or uninitialized queue \n");
        return queue;
    }
    voter* aux = queue->head;
    queue->head = aux->next;
    if (queue->head == NULL) {
        queue->end = NULL;
    }
    aux->next = NULL;
    return queue;
}

queue_vote* leave_queue(queue_vote*queue, int id) {
    if (queue == NULL || queue->head == NULL) {
        printf("Fila vazia\n");
        return queue;
    }

    voter* aux = queue->head;
    voter* aux2 = NULL;

    while (aux != NULL && aux->id != id) {
        aux2 = aux;
        aux2 = aux->next;
    }
    if (aux==NULL) {
        printf("not found");
        return queue;
    }

    // Remove the fist
    if (aux2 == NULL) {
        queue->head = aux->next;
        if (queue->head == NULL)
            queue->end = NULL;
    }
    //Remove in the middle or at the end.
    else {
        aux2->next = aux->next;
        if (aux == queue->end)
            queue->end = aux2;
    }
    aux->next = NULL;
    free(aux);
    return queue;

}

int len_of_queue(queue_vote* queue) {
    if (queue == NULL || queue->head == NULL) {
        printf("empty or uninitialized queue \n");
        return 0;
    }
    voter* aux = queue->head;
    int count = 0;
    while (aux != NULL) {
        count++;
        aux = aux->next;
    }
    return count;
}

int search_in_queue(queue_vote* queue,int id) {
    if (queue == NULL || queue->head == NULL) {
        printf("empty or uninitialized queue \n");
        return 0;
    }
    voter* aux = queue->head;
    while (aux != NULL) {
        if (aux->id == id) {
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

void print_queue(queue_vote* queue) {
    if (queue == NULL || queue->head == NULL) {
        printf("empty or uninitialized queue \n");
        return;
    }
    voter* aux = queue->head;
    while (aux != NULL) {
        printf("%s %d %d\n" , aux->name,aux->id,aux->status);
        aux = aux->next;
    }
}

void distribute_queue(voter* list, queue_vote** queue1, queue_vote**queue2,queue_vote** queue3) {
    *queue1 = initialize_queue_vote();
    *queue2 = initialize_queue_vote();
    *queue3 = initialize_queue_vote();
    voter* aux =list;
    voter* aux2 = NULL;
    int pass = 1;

    while (aux != NULL) {
        aux2 = aux->next;
        aux = NULL;
        if (pass == 1) {
            *queue1 = add(*queue1,aux);
            pass = 2;
        }else if (pass == 2) {
            *queue2 = add(*queue2,aux);
            pass = 3;
        }else if (pass == 3) {
            *queue3 = add(*queue3,aux);
            pass = 1;
        }
        aux = aux2;
    }
}

void free_queue(queue_vote* queue) {
    if (queue == NULL || queue->head == NULL) {
        printf("empty or uninitialized queue \n");
        return;
    }
    voter* aux = queue->head;
    voter* aux2 = NULL;
    while (aux != NULL) {
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    queue->head = NULL;
    queue->end = NULL;
}