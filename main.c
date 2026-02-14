//
// Created by Yuri Rodrigues on 26/01/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "voter.c"
#include " candidate.c"
#include "vote.c"
#include "queue_vote.c"


    void display_menu(){
        printf("\n");
        printf("   _______________________________________________ \n");
        printf("  |          VOTING SYSTEM MANAGER                |\n");
        printf("  |_______________________________________________|\n");
        printf("  |  1.Register voter                             |\n");
        printf("  |  2.update voter                               |\n");
        printf("  |  3.Register candidate                         |\n");
        printf("  |  4.Remove candidate                           |\n");
        printf("  |  5.Initialize vote                            |\n");
        printf("  |  6.Voter Leave queue (give up)                |\n");
        printf("  |  7.Vote                                       |\n");
        printf("  |  8.Print candidate                            |\n");
        printf("  |  9.Show Queue Size                            |\n");
        printf("  |  10.Partial results                           |\n");
        printf("  |  11.Final results                             |\n");
        printf("  |  0. Exit                                      |\n");
        printf("  |_______________________________________________|\n");
        printf("  Selection > ");
}

int main(){
char name[50];
int id=1,status =0,option, id_candidate= 3000,number_of_votes=0;
int day,month,year,verification;
int valid=0,blank=0,null=0,total_vote=0;

voter* list_voter = initialize_register_voter();
candidate* list_candidate = init_candidate();

//queue
queue_vote* queue1 = initialize_queue_vote();
queue_vote* queue2 = initialize_queue_vote();
queue_vote* queue3 = initialize_queue_vote();

//box
vote* box1=creat_voter_box();
vote* box2=creat_voter_box();
vote* box3=creat_voter_box();

        printf("Before starting the voting system, you must register the day, month, and year\n");
        printf("if the day or month is below 10, enter only one digit.\n");
        printf("Enter the day of vote: ");
        scanf("%d",&day);
        printf("Enter the month of vote");
        scanf("%d",&month);
        printf("Enter the year of vote: ");
        scanf("%d",&year);

        verification = date_verification(day,month,year);
        while (verification ==0) {
            printf("Invalid date");
            printf("Please enter a valid date: ");
            printf("Enter the day of vote: ");
            scanf("%d",&day);
            printf("Enter the month of vote");
            scanf("%d",&month);
            printf("Enter the year of vote: ");
            scanf("%d",&year);
            verification = date_verification(day,month,year);
        }

        do {

            display_menu();
            scanf("%d", &option);
            getchar();


            switch (option) {
                case 1:

                    printf("Digit your name");
                    scanf(" %[^\n]", name);

                    id = id + 1;
                    list_voter = register_voter(list_voter, name,id);
                    print_voter(list_voter);
                    break;

                case 2:
                    int i,j;
                      printf("Enter the ID you want to update.");
                      scanf("%d", &j);

                    i = search_voter(list_voter,j);
                    if (i == 1) {
                        printf("Enter your name");
                        scanf(" %[^\n]", name);

                        list_voter = update_voter_information(list_voter,name,j);

                    }else if (i == 0)
                        printf("No voter found");
                    break;

                case 3:
                    printf("Enter your name: ");
                    scanf(" %[^\n]", name);
                    id_candidate++;
                    list_candidate = register_candidate(list_candidate,name,id_candidate,number_of_votes);
                    break;

                case 4:

                    printf("\n Enter the ID of the candidate you wish to remove:" );
                    scanf("%d", &i);
                    list_candidate = remove_candidate(list_candidate,i);
                    break;

                case 5:
                    int len = length_voter(list_voter);
                    int len2 = len_candidate(list_candidate);
                    if (len >= 10 && status == 0 && len2 > 1 ) {
                        status =1;
                        distribute_queue(list_voter,&queue1,&queue2,&queue3);
                        printf("The voters were distributed and organized by:\n");
                        printf("first queue:\n");
                        print_queue(queue1);
                        printf("second queue:\n");
                        print_queue(queue2);
                        printf("third queue:\n");
                        print_queue(queue3);
                    }else if (status == 1)
                        printf("The vote has already been initiated.");
                    else if (len2 < 2)
                        printf("At least two candidates are required to initiate the voting process.");
                    else
                        printf("A minimum of 10 voters is required to begin the voting process..\n");
                    break;

                case 6:
                    if (status == 0)
                        printf("Voting must be initialized to use this option.");
                    else {
                        printf("Enter the id:");
                        scanf("%d", &i);
                        int p = search_in_queue(queue1,queue2,queue3,i);

                        if (p == 1) {
                            printf("the id %d",i);
                            queue1 = leave_queue(queue1,i);

                        }else if (p == 2) {
                            printf("the id %d",i);
                            queue2 = leave_queue(queue2,i);
                        }else if (p == 3) {
                            printf("the id %d",i);
                            queue3 = leave_queue(queue3,i);
                        }else
                            printf("not found");
                    }

                    break;
                case 7:
                    if (status == 0)
                        printf("Voting must be initialized to use this option.");
                    else {
                        printf("--------------------------- Voting begins ------------------------------------\n");
                        int hour,minutes;
                        int vote,verify1,ln;
                        printf("Enter the number of queue to vote:[1,2,3]");
                        scanf("%d", &i);

                        if (i ==1) {
                            ln = len_of_queue(queue1);
                            if (ln==0) {
                                printf("empty queue");
                            }else {
                                printf("Note1:the hour must be over 8h and under 21h.\n");
                                printf("Note2:the minute must be over 0 and under 59.\n");
                                printf("Note3:if the time is below 10, enter only one digit.\n");

                                printf("Enter the hour:");
                                scanf("%d",&hour);

                                printf("Enter the minute:");
                                scanf("%d",&minutes);

                                verify1 = time_verification(hour,minutes);
                                if (verify1 == 1) {
                                    print_current(queue1);
                                    printf("Selection:");
                                    printf("You must vote using a valid candidate ID.\n");
                                    printf("Otherwise, it will be considered an invalid vote.\n");
                                    printf("Enter 0 for a blank vote.\n");
                                    candidate_list_vote(list_candidate);
                                    printf("Enter your vote:");
                                    scanf("%d",&vote);
                                    box1 = add_voter_box(box1,vote,hour,minutes,day,month,year);
                                    list_candidate =counter_candidate_vote(list_candidate,vote);

                                    blank=+ blank_vote(vote);
                                    null =+ null_vote(box1,list_candidate,vote);
                                    valid=+ valid_vote(box1,list_candidate,vote);


                                }else
                                    printf("Invalid time");
                            }

                        }else if (i==2) {
                            ln = len_of_queue(queue2);
                            if (ln == 0) {
                                printf("empty queue");
                            }else {
                                printf("Note1:the hour must be over 8h and under 21h.\n");
                                printf("Note2:the minute must be over 0 and under 59.\n");
                                printf("Note3:if the time is below 10, enter only one digit.\n");

                                printf("Enter the hour:");
                                scanf("%d",&hour);

                                printf("Enter the minute:");
                                scanf("%d",&minutes);

                                system("clear");

                                verify1 = time_verification(hour,minutes);
                                if (verify1 == 1) {
                                    print_current(queue1);
                                    printf("Selection:");
                                    printf("You must vote using a valid candidate ID.\n");
                                    printf("Otherwise, it will be considered an invalid vote.\n");
                                    printf("Enter 0 for a blank vote.\n");
                                    candidate_list_vote(list_candidate);
                                    printf("Enter your vote:");
                                    scanf("%d",&vote);
                                    box2 = add_voter_box(box2,vote,hour,minutes,day,month,year);
                                    list_candidate =counter_candidate_vote(list_candidate,vote);

                                    blank =+ blank_vote(vote);
                                    null =+ null_vote(box2,list_candidate,vote);
                                    valid=+ valid_vote(box2,list_candidate,vote);

                                }else
                                    printf("Invalid time\n");
                            }

                        }else if (i==3) {
                            ln = len_of_queue(queue3);
                            if (ln == 0) {
                                printf("empty queue");
                            }else {
                                printf("Note1:the hour must be over 8h and under 21h.\n");
                                printf("Note2:the minute must be over 0 and under 59.\n");
                                printf("Note3:if the time is below 10, enter only one digit.\n");
                                printf("Enter the hour:");
                                scanf("%d",&hour);

                                printf("Enter the minute:");
                                scanf("%d",&minutes);

                                system("clear");

                                verify1 = time_verification(hour,minutes);
                                if (verify1 == 1) {
                                    print_current(queue1);
                                    printf("Selection:");
                                    printf("You must vote using a valid candidate ID.\n");
                                    printf("Otherwise, it will be considered an invalid vote.\n");
                                    printf("Enter 0 for a blank vote.\n");
                                    candidate_list_vote(list_candidate);
                                    printf("Enter your vote:");
                                    scanf("%d",&vote);
                                    box3 = add_voter_box(box3,vote,hour,minutes,day,month,year);
                                    list_candidate =counter_candidate_vote(list_candidate,vote);

                                    blank =+ blank_vote(vote);
                                    null =+ null_vote(box2,list_candidate,vote);
                                    valid=+ valid_vote(box2,list_candidate,vote);
                                }else
                                    printf("Invalid time\n");
                            }
                        }else
                            printf("Invalid option!\n");

                    }
                    break;
                case 8:
                    if (status == 0)
                        printf("Voting must be initialized to use this option.");
                    else {
                        printf("queue1:");
                        print_queue(queue1);
                        printf("queue2:");
                        print_queue(queue2);
                        printf("queue3:");
                        print_queue(queue3);
                    }
                    break;
                case 9:
                    if (status == 0)
                        printf("Voting must be initialized to use this option.");
                    else {
                        int l1= len_of_queue(queue1),l2=len_of_queue(queue2),l3=len_of_queue(queue3);
                        printf("len of queue1:");
                        printf("%d",l1);
                        printf("len of queue2:");
                        printf("%d",l2);
                        printf("len of queue1:");
                        printf("%d",l3);
                    }
                    break;
                case 10:
                    if (status == 0)
                        printf("Voting must be initialized to use this option.");
                    else {
                        printf("Partial result:\n");
                        print_candidate_list(list_candidate);
                    }

                    break;
                case 11:
                    if (status==0)
                        printf("Voting must be initialized to use this option.");
                    else {
                        total_vote = total_vote + count(box1)+ count(box2)+ count(box3);
                        FILE *f =fopen("Report.txt","w");
                        fprintf(f,"----------------------------------------------final Report-----------------------------------\n");
                        fprintf(f,"Number of votes: %d\n",total_vote);
                        fprintf(f,"Blank votes: %d\n",blank);
                        fprintf(f,"Null votes: %d\n",null);
                        fprintf(f,"Valid votes: %d\n",valid);
                        candidate* aux = list_candidate;
                        fprintf(f,"Number of votes for candidates: \n");
                        while (aux!=NULL) {
                            fprintf(f,"%s %d %d\n", aux->name,aux->id,aux->number_of_votes);
                            aux = aux->next;
                        }


                    }
                    break;
                case 0:
                    printf("\nExiting system... Goodbye!\n");

                    break;

                default:
                    printf("\n[ERROR] Invalid option! Try again.\n");
            }


        } while (option != 0);




}