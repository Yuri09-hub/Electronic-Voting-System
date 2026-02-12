//
// Created by Yuri Rodrigues on 11/02/2026.
//

#include "vote.h"
#include <stdlib.h>
#include <stdio.h>

vote*creat_voter_box() {
    vote* box = (vote*)malloc(sizeof(vote));
    if (box != NULL) {
        box -> head = NULL;
    }else
        printf("malloc error (box)");
    return box;
}

// to vote
vote*add_voter_box(vote* box,int id,int hour,int minute,int day,int month,int year) {
    if (box == NULL) {
        printf("Error in add_voter_box");
        return box;
    }
    node * new = (node*)malloc(sizeof(node));
    if (new != NULL) {
        new -> id = id;
        new -> day = day;
        new -> month = month;
        new -> year = year;
        new -> hour = hour;
        new -> minute = minute;

        // put in box
        new-> next = box -> head;
        box -> head = new;
    }else
        printf("malloc error in add_voter_box");
    return box;
}

// counting the number of votes
int count(vote* box) {
    if (box == NULL || box -> head == NULL) {
        printf("empty or uninitialized box");
        return 0;
    }
    int count = 0;
    node* aux = box -> head;
    while (aux != NULL) {
        count++;
        aux = aux -> next;
    }
    return count;
}

// date verify
vote* date_verification(int day,int month,int year) {
    if (year < 1 || month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return 0;
    }

    if (month == 2) {
        int leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leap_year) {
            if (day > 29) return 0;
        } else {
            if (day > 28) return 0;
        }
    }
    return 1;
}

// time verify
vote* time_verification(int hour,int minute) {
    if ((8 > hour > 21 ) && (0 >minute > 59))
        return 0;
    else
        return 1;
}