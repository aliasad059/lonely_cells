#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "structs.h"
extern int flag;
void map_printer(struct cells * player_1 , struct cells * player_2 ,struct map_attribute * bin_map,int n){
    int a = 40;
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    if(flag) initwindow(n*125,n*125);
    flag =0 ;
    cleardevice();
    int coordinate_for_text[n*n][2];
    for (int j = 0;j  <n; j++)
    {
        for (int  i = 0; i < n; i++)
        {
            coordinate_for_text[i +j*n][0] = (2*i+1)*a+20;
            coordinate_for_text[i +j*n][1] = (2*j+1)*sqrt(3)*(a)/2 + (i%2+1)* sqrt(3)*(a)/2+10;
            int coordinates[14];
            coordinates[0]=(2*i+1)*a-a +20;
            coordinates[1] = (2*j+1)*sqrt(3)*(a)/2 + (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[2] = (2*i+1)*(a)-a/2+20;
            coordinates[3] = (2*j+1)*sqrt(3)*(a)/2+sqrt(3)*a/2 + (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[4] = (2*i+1)*(a)+a/2+20;
            coordinates[5] = (2*j+1)*sqrt(3)*(a)/2+sqrt(3)*a/2+ (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[6] = (2*i+1)*(a)+a+20;
            coordinates[7] = (2*j+1)*sqrt(3)*(a)/2 + (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[8] = (2*i+1)*(a)+a/2+20;
            coordinates[9] = (2*j+1)*sqrt(3)*(a)/2-sqrt(3)*a/2+ (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[10] = (2*i+1)*(a)-a/2+20;
            coordinates[11] = (2*j+1)*sqrt(3)*(a)/2-sqrt(3)*a/2+ (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[12] = (2*i+1)*(a)-a+20;
            coordinates[13] = (2*j+1)*sqrt(3)*(a)/2+ (i%2+1)* sqrt(3)*(a)/2+10;
            setcolor(BROWN);
            if(((int)bin_map[j * n + i].type)-48 == 1)
                setfillstyle(10, YELLOW);
            else if(((int)bin_map[j * n + i].type)-48 == 2)
                setfillstyle(10, GREEN);
            else if(((int)bin_map[j * n + i].type)-48 == 3)
                setfillstyle(8, DARKGRAY);
            else if(((int)bin_map[j * n + i].type)-48 == 4)
                setfillstyle(10, MAGENTA);
            fillpoly(7,coordinates);
            //3 , 10 , 9,11

        }
    }

    for(int i =0 ; i < n ; i++){
        for(int j =0 ; j < n ; j++){
            char coordinate[10];
            sprintf(coordinate, "[%d,%d]", i,j);
            setcolor(BROWN);
            outtextxy(coordinate_for_text[n*j+i][0] -13,coordinate_for_text[n* j +i][1]-20,coordinate);
        }
    }

     struct cells_el* player_1_copy  = player_1->head;
    for(int i =0 ; i < player_1->length ; i++ , player_1_copy = player_1_copy->next)
    {
        int x =  player_1_copy->cell->x ;
        int y =  player_1_copy->cell->y ;
        setcolor(RED);
            outtextxy(coordinate_for_text[n*y+x][0]-15 ,coordinate_for_text[n* y +x][1],player_1_copy->cell->name);
    }
    if(player_2 != NULL){
        struct cells_el* player_2_copy  = player_2->head;
        for(int i =0 ; i < player_2->length ; i++ , player_2_copy = player_2_copy->next)
        {
            int x = player_2_copy->cell->x ;
            int y = player_2_copy->cell->y ;
            setcolor(CYAN);
            outtextxy(coordinate_for_text[n*y+x][0] -15,coordinate_for_text[n*y+x][1],player_2_copy->cell->name);
        }
    }

        setcolor(YELLOW);
        outtextxy(0,5,"Energy : YELLOW");
        setcolor(GREEN);
        outtextxy(150,5,"Mitosis : GREEN");
        setcolor(RED);
        outtextxy(300,5,"Player 1 cells : RED");
        setcolor(MAGENTA);
        outtextxy(0,20,"Normal : MAGENTA");
        setcolor(DARKGRAY);
        outtextxy(150,20,"Forbidden : GRAY");
        setcolor(CYAN);
        outtextxy(300,20,"Player 2 cells : CYAN");

}
