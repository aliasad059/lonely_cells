#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "structs.h"

#include"linklists_operations.h"

void save_fun(struct cells * player, struct map_attribute * bin_map, int n ,int player_number){

    FILE *fp1;
    if(player_number == 1)
        fp1 = fopen("Player_1_Info.bin", "wb");
    else
        fp1 = fopen("Player_2_Info.bin", "wb");
    if(fp1 == NULL){
    printf("Cannot create file\n");
    return;
    }
    fwrite(&player->length, sizeof(int), 1, fp1);
    for(struct cells_el * player_copy = player->head; player_copy != NULL ;player_copy = player_copy ->next){
        fwrite(player_copy->cell, sizeof(struct cell), 1, fp1);
    }
    fclose(fp1);
    FILE *fp2;
    fp2 = fopen("MapInfo.bin", "wb");
    if(fp1 == NULL){
    printf("Cannot create file\n");
    return ;
    }
    fwrite(&n, sizeof(int), 1, fp2);
    for(int i = 0 ; i < n*n ; i++)
        fwrite(&bin_map[i], sizeof(struct map_attribute), 1, fp2);
    fclose(fp2);
    printf("The game has successfully saved for player %d\n",player_number);
}
int load_fun(struct map_attribute * bin_map , struct cells * player_1 , struct cells * player_2){
    FILE * fmap;
    fmap = fopen("MapInfo.bin","rb");
    int n;
    if(fmap == NULL) {return 0;}
    fread(&n,sizeof(int),1,fmap);
    for (int i = 0 ; i<n*n;i++ )
        fread( &bin_map[i], sizeof(struct map_attribute), 1, fmap);
    fclose(fmap);

    FILE *fplayer_1;
    fplayer_1 =  fopen("Player_1_Info.bin","rb");
    if(fplayer_1 == NULL) {return 0;}
    int sizeof_p1;
    fread(&sizeof_p1,sizeof(int),1 ,fplayer_1);
    //player_1 = cells_new(player_1);
    for(int i = 0 ; i< sizeof_p1 ; i++)
    {
        struct cell *new_cell = (struct cell *)malloc(sizeof(struct cell ));
        fread(new_cell, sizeof(struct cell),1,fplayer_1);
        cells_push_back(player_1,new_cell);
    }
    fclose(fplayer_1);

    FILE *fplayer_2;
    fplayer_2 =  fopen("Player_2_Info.bin","rb");
    if(fplayer_2 == NULL) return 1;
    int sizeof_p2;
    fread(&sizeof_p2,sizeof(int),1 ,fplayer_2);
    //player_2 = cells_new(player_2);
    for(int i = 0 ; i< sizeof_p2 ; i++)
    {
        struct cell *new_cell = (struct cell *)malloc(sizeof(struct cell ));
        fread(new_cell, sizeof(struct cell),1,fplayer_2);
        cells_push_back(player_2,new_cell);
    }
    fclose(fplayer_2);
    return 2;
}
