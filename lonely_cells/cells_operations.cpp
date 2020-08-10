#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "structs.h"
#include"linklists_operations.h"
void move_fun(struct cells * player,int cell_num,struct map_attribute *bin_map,int n){
    system("cls");

    struct cells_el * player_copy = player->head;
    for (int i = 1 ; i< cell_num ; i++ , player_copy  = player_copy ->next);
    int choice;
    printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
    scanf("%d",&choice);
    if (choice == 1) {
            if( bin_map[(player_copy->cell->y - 1)*n +player_copy->cell->x].type == '3' ) {printf("Can not move to forbidden place\n") ;Sleep(2000);return;}
            (player_copy ->cell-> y )--;
    }
    else if (choice == 2) {
            if( bin_map[(player_copy->cell->y + 1)*n +player_copy->cell->x].type == '3' ) {printf("Can not move to forbidden place\n"); Sleep(2000);return;}
            (player_copy ->cell-> y )++;
    }
    else if (choice == 3) {
            if( bin_map[(player_copy->cell->y - 1)*n +player_copy->cell->x + 1].type == '3' ) {printf("Can not move to forbidden place\n"); Sleep(2000);return;}

            if ( player_copy->cell->x %2 ==  0){(player_copy ->cell-> y )-- ;(player_copy ->cell-> x )++ ;}
            else if ( player_copy->cell->x %2 ==  1)(player_copy ->cell-> x )++ ;
    }
    else if (choice == 4) {
            if( bin_map[(player_copy->cell->y - 1)*n +player_copy->cell->x - 1].type == '3' ) {printf("Can not move to forbidden place\n");Sleep(2000); return;}
            if ( player_copy->cell->x %2 ==  0){(player_copy ->cell-> y )-- ;(player_copy ->cell-> x )-- ;}
            else if ( player_copy->cell->x %2 ==  1)(player_copy ->cell-> x )-- ;
    }
    else if (choice == 5) {
            if( bin_map[(player_copy->cell->y + 1)*n +player_copy->cell->x + 1].type == '3' ) {printf("Can not move to forbidden place\n") ;Sleep(2000);return;}
            if ( player_copy->cell->x %2 ==  1){(player_copy ->cell-> y )++ ;(player_copy ->cell-> x )++ ;}
            else if ( player_copy->cell->x %2 ==  0)(player_copy ->cell-> x )++ ;
    }
    else if (choice == 6) {
            if( bin_map[(player_copy->cell->y + 1)*n +player_copy->cell->x - 1].type == '3' ) {printf("Can not move to forbidden place\n") ;Sleep(2000);return;}
            if ( player_copy->cell->x %2 ==  1){(player_copy ->cell-> y )++ ;(player_copy ->cell-> x )-- ;}
            else if ( player_copy->cell->x %2 ==  0)(player_copy ->cell-> x )-- ;
    }
}
void split_fun(struct cells * player , int cell_num,struct map_attribute *bin_map,int n){
    struct cells_el * player_copy = player->head;
    for (int i = 1 ; i < cell_num ; i++, player_copy = player_copy->next);
    if ( bin_map[player_copy->cell->y * n + player_copy->cell->x].type != '2' ){printf("You are not at mitosis place\n");Sleep(2000);return;}
    else if(player_copy->cell->point < 80) {printf("Not enough energy\n");Sleep(2000);return;}
    else{
        struct cell* new_cell1 =  (struct cell *)malloc(sizeof(struct cell ));
        struct cell* new_cell2 =  (struct cell *)malloc(sizeof(struct cell ));
        new_cell1->x = player_copy->cell->x; new_cell1->y = player_copy->cell->y;
        cells_remove(player,cells_search_coordinate(player, player_copy ->cell->x, player_copy->cell->y ));
        char cell1_name[15] ,cell2_name[15];
        printf("Enter name of the first cell\n");
        getchar();
        gets(cell1_name);
        printf("Enter name of the second cell\n");
        gets(cell2_name);
        strcpy(new_cell1->name,cell1_name);
        strcpy(new_cell2->name,cell2_name);
        new_cell1->point = 40;
        new_cell2->point = 40;
        printf("Choose location of %s compared to %s:\n[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n",new_cell2->name,new_cell1->name);
        int choice;
        scanf("%d",&choice);
        if (choice == 1) {
                new_cell2->y =  (new_cell1 -> y )-1;new_cell2->x = (new_cell1 -> x );
        }
        if (choice == 2) {
                new_cell2->y =  (new_cell1 -> y )+1;new_cell2->x = (new_cell1 -> x );
        }
        if (choice == 3) {
                if(new_cell1->x %2 == 0){new_cell2->y =  new_cell1 -> y - 1; new_cell2->x = new_cell1 -> x +1 ;}
                else{new_cell2->y =  new_cell1 -> y ; new_cell2->x = new_cell1 -> x +1 ;}
        }
        if (choice == 4) {
                if(new_cell1->x %2 == 0){new_cell2->y =  new_cell1 -> y - 1; new_cell2->x = new_cell1 -> x -1 ;}
                else{new_cell2->y =  new_cell1 -> y ; new_cell2->x = new_cell1 -> x -1 ;}
        }
        if (choice == 5) {
                if(new_cell1->x %2 == 1){new_cell2->y =  new_cell1 -> y + 1; new_cell2->x = new_cell1 -> x +1 ;}
                else{new_cell2->y =  new_cell1 -> y ; new_cell2->x = new_cell1 -> x +1 ;}
        }
        if (choice == 6) {
                if(new_cell1->x %2 == 1){new_cell2->y =  new_cell1 -> y + 1; new_cell2->x = new_cell1 -> x -1 ;}
                else{new_cell2->y =  new_cell1 -> y ; new_cell2->x = new_cell1 -> x -1 ;}
        }
        cells_push_back(player,new_cell1);
        cells_push_back(player,new_cell2);
    }
}
void boost_fun(struct cells * player , int cell_num,struct map_attribute *bin_map,int n){
    struct cells_el * player_copy = player->head;
    for(int i = 1 ; i< cell_num ; i++ ,player_copy = player_copy->next);
    if(bin_map[player_copy->cell->y * n + player_copy->cell->x].type != '1'){printf("You are not at energy place\n");Sleep(2000); return;}
    printf("Energy of this place is : %d\n",bin_map[player_copy->cell->y * n + player_copy->cell->x].point);
    printf("How much energy do you want ? (at most 15 energy each time)\n");
    int energy;
    scanf("%d",&energy);
    if(energy > 15) {printf("You are can get energy at most 15 each time\n"); Sleep(2000);return;}
    if(bin_map[player_copy->cell->y * n + player_copy->cell->x].point < energy) {printf("Not enough energy \n");Sleep(2000); return;}
    player_copy->cell->point += energy;
    bin_map[player_copy->cell->y * n + player_copy->cell->x].point -= energy;
};
