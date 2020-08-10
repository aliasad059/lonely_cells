#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "structs.h"

struct cells *cells_new(struct cells *new_cells){
    new_cells = (struct cells *)malloc(sizeof(struct cells));
    new_cells->head = NULL;
    new_cells->length = 0;
    return new_cells;
}
void cells_push_back(struct cells *cells, struct cell *cell){
    struct cells_el*el = (struct cells_el*)malloc(sizeof(struct cells_el));
    el->cell = cell;
    el->next = NULL;
    if( cells->head == NULL )
    {
        cells->head = el;
    }
    else
    {
        struct cells_el* x =cells->head;
        for (; x->next!=NULL; x= x->next);
        x->next=el;
    }
    cells->length++;
}
void cells_remove(struct cells *cells, int index){
    struct cells_el *el = cells->head;
    if (index == 0)
    {
        cells->head = el->next;

    }
    else
    {
        int i = 0;
        while (el && i + 1 < index)
        {
            el = el->next;
            i++;
        }
        if (i + 1 == index)
        {
            struct cells_el *p = el->next->next;
            el->next = p;
        }
    }
    cells->length --;
}
int cells_search_coordinate(struct cells *cells, int x, int y){
    int index = -1;
    int i = 0;

    struct cells_el *p = cells->head;
    while (p)
    {
        if (p -> cell -> x == x && p -> cell -> y == y)
        {
            index = i;
            break;
        }
        i++;
        p = p->next;
    }
    return index;
}
struct cells* player_maker(int n,struct map_attribute * bin_map){
    struct cells *new_player;
    new_player = cells_new(new_player);

    printf("Enter how many cells do you need \n");
    int cell_num;
    scanf("%d",&cell_num);
    srand(time(0));
    for(int i = 0 ; i< cell_num ; i++)
    {
        struct cell *new_cell = (struct cell *)malloc(sizeof(struct cell ));
        new_cell->x = rand() % n;
        new_cell->y = rand() % n;
        int index = cells_search_coordinate(new_player,new_cell->x, new_cell->y);
        if(bin_map[new_cell->y *n + new_cell->x].type == '3') i--;
        else if (index == -1 )
        {
            printf("Enter the name of cell\n");
            getchar();
            gets(new_cell->name);
            printf("Enter the point of cell\n");
            scanf("%d", &new_cell->point);
            cells_push_back(new_player,new_cell);
        }
        else
        {
            free(new_cell);
            i--;
        }
    }
    return new_player;
}
