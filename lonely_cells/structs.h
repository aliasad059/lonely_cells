struct map_attribute{
    int point ;
    char type;
};
struct cell{
    char name[15];
    int point;
    int x;
    int y;
};
struct cells{
    int length;
    struct cells_el *head;
};
struct cells_el{
    struct cell *cell;
    struct cells_el *next;
};
