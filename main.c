//
// Created by Yuri Rodrigues on 26/01/2026.
//
#include <stdio.h>
#include <locale.h>
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
        printf("  |  10.Vote                                      |\n");
        printf("  |  0. Exit                                      |\n");
        printf("  |_______________________________________________|\n");
        printf("  Selection > ");
}

int main(){
char name[50];
int id=1,status =0,option, id_candidate= 3000,number_of_votes=0;

voter* list_voter = initialize_register_voter();
candidate* list_candidate = init_candidate();
//
queue_vote* queue1 = initialize_queue_vote();
queue_vote* queue2 = initialize_queue_vote();
queue_vote* queue3 = initialize_queue_vote();

//
vote* box1=creat_voter_box();
vote* box2=creat_voter_box();
vote* box3=creat_voter_box();


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
                    break;

                case 2:
                    int i,j;
                      printf("Enter the ID you want to update.");
                      scanf("%d", &j);

                    i = search_voter(list_voter,j);
                    if (i == 1) {
                        printf("Digit your name");
                        scanf(" %[^\n]", name);

                        list_voter = update_voter_information(list_voter,name,j);

                    }else if (i == 0)
                        printf("No voter found");
                    break;

                case 3:
                    printf("Digit your name: ");
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
                    printf("\n[WARNING] Clearing all memory...\n");

                    printf("Queue is now empty.\n");
                    break;

                case 0:
                    printf("\nExiting system... Goodbye!\n");

                    break;

                default:
                    printf("\n[ERROR] Invalid option! Try again.\n");
            }

            if (option != 0) {
                printf("\nPress ENTER to continue...");
                getchar(); // Pausa para o utilizador ler o resultado
            }

        } while (option != 0);




}