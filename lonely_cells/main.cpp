#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "structs.h"
#include "linklists_operations.h"
#include "cells_operations.h"
#include "load_save.h"
#include "map_printer.h"

int flag = 1;
int main(){
    struct cells * player_1;
    player_1 = cells_new(player_1);
    struct cells * player_2;
    player_2 = cells_new(player_2);
    FILE *fp;
    fp = fopen("map.bin", "rb");
    if(fp == NULL)
    {
        printf("Cannot read from map.bin\n");
    }
    int n;
    fread(&n,sizeof(int),1,fp);
    struct map_attribute *bin_map = (struct map_attribute*) malloc(sizeof(struct map_attribute )* n*n);

    while(1){
            system("cls");
    int choice;
    printf("[1]Load\n[2]New single player game\n[3]New Multi-Player game\n[4]Exit\n");
    scanf("%d",&choice);
    system("cls");
    int players_number = 0;
    if(choice == 1){
            players_number = load_fun(bin_map,player_1,player_2);
            if(players_number == 0) {printf("There is no save to load\n"); Sleep(2000);continue;}
    }
    if(choice == 2 || players_number == 1) {
        if (choice == 2) {
            for (int i = 0; i <n*n; i++)
            {

                fread( &bin_map[i].type, sizeof(char), 1, fp);
                if(bin_map[i].type == '1')
                    bin_map[i].point = 100;
                else
                    bin_map[i].point = 0;
            }
            player_1 =  player_maker(n,bin_map);
        }
        while(1){
        map_printer(player_1,NULL,bin_map,n);
        system("cls");
        printf("Player 1:\n");
        printf("Please choose one of your cells:\n");
        struct cells_el * player_1_copy = player_1 ->head;
        for(int i = 1 ;  player_1_copy != NULL; i++ ,player_1_copy = player_1_copy->next)
            printf("[%d] %s (%d , %d) : %d\n",i,player_1_copy->cell->name, player_1_copy->cell->x,player_1_copy->cell->y , player_1_copy->cell->point );
        int cell_to_do;
        scanf("%d",&cell_to_do);
        system("cls");
        printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n");
        int choice_2;
        scanf("%d",&choice_2);
        if(choice_2 == 1){move_fun(player_1,cell_to_do,bin_map,n);}
        else if (choice_2 == 2){split_fun(player_1,cell_to_do,bin_map,n);}
        else if (choice_2 == 3){boost_fun(player_1,cell_to_do,bin_map,n);}
        else if (choice_2 == 4){save_fun(player_1,bin_map,n,1);}
        else if (choice_2 == 5){break;}
        }
    }
    else if(choice == 3 || players_number == 2) {
            if(choice ==3){
                for (int i = 0; i <n*n; i++){
                    fread( &bin_map[i].type, sizeof(char), 1, fp);
                    if(bin_map[i].type == '1')
                        bin_map[i].point = 100;
                    else
                        bin_map[i].point = 0;
                }
                system("cls");
                printf("Player 1:\n");
                player_1 =  player_maker(n,bin_map);
                system("cls");
                printf("Player 2:\n");
                player_2 =  player_maker(n,bin_map);
        }
        while(1){
        map_printer(player_1,player_2,bin_map,n);
        system("cls");
        printf("Player 1:\n");
        printf("Please choose one of your cells:\n");
        struct cells_el * player_1_copy = player_1 ->head;
        for(int i = 0 ; i < player_1->length ; i++ ,player_1_copy = player_1_copy->next)
            printf("[%d] %s (%d , %d) : %d\n",i+1,player_1_copy->cell->name, player_1_copy->cell->x,player_1_copy->cell->y , player_1_copy->cell->point );
        int cell_to_do_1;
        scanf("%d",&cell_to_do_1);
        system("cls");
        printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n");
        int choice_2_1;
        scanf("%d",&choice_2_1);
        if(choice_2_1 == 1){move_fun(player_1,cell_to_do_1,bin_map,n);}
        else if (choice_2_1 == 2){split_fun(player_1,cell_to_do_1,bin_map,n);}
        else if (choice_2_1 == 3){boost_fun(player_1,cell_to_do_1,bin_map,n);}
        else if (choice_2_1 == 4){save_fun(player_1,bin_map,n,1);save_fun(player_2,bin_map,n,2);}
        else if (choice_2_1 == 5){break;}
        system("cls");
        map_printer(player_1,player_2,bin_map,n);
        printf("Player 2:\n");
        printf("Please choose one of your cells:\n");
        struct cells_el * player_2_copy = player_2 ->head;
        for(int i = 0 ; i < player_2->length ; i++ ,player_2_copy = player_2_copy->next)
            printf("[%d] %s (%d , %d) : %d\n",i+1,player_2_copy->cell->name, player_2_copy->cell->x,player_2_copy->cell->y , player_2_copy->cell->point );
        int cell_to_do_2;
        scanf("%d",&cell_to_do_2);
        system("cls");
        printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]Save\n[5]Exit\n");
        int choice_2_2;
        scanf("%d",&choice_2_2);
        if(choice_2_2 == 1){move_fun(player_2,cell_to_do_2,bin_map,n);}
        else if (choice_2_2 == 2){split_fun(player_2,cell_to_do_2,bin_map,n);}
        else if (choice_2_2 == 3){boost_fun(player_2,cell_to_do_2,bin_map,n);}
        else if (choice_2_2 == 4){save_fun(player_1,bin_map,n,1);save_fun(player_2,bin_map,n,2);}
        else if (choice_2_2 == 5){break;}
        }
        }
    else if(choice == 4) {
            int player_1_points=0;
            for(struct cells_el *player_1_copy = player_1->head;player_1_copy!= NULL;player_1_copy = player_1_copy ->next )
                player_1_points += player_1_copy ->cell->point;
            int player_2_points=0;
            for(struct cells_el *player_2_copy = player_2->head;player_2_copy!= NULL;player_2_copy = player_2_copy ->next )
                player_2_points += player_2_copy ->cell->point;
            printf("Player 1 catched %d points\n",player_1_points);
            printf("Player 2 catched %d points\n",player_2_points);
            if(player_1_points>player_2_points) printf("Player 1 won the game!\n");
            if(player_1_points<player_2_points) printf("Player 2 won the game!\n");
            if(player_1_points==player_2_points) printf("No winner!\n");
        break;
    }

    else {printf("Invalid choice please try again.\n");Sleep(2000);}

    }
    fclose(fp);
    return 0;
}
