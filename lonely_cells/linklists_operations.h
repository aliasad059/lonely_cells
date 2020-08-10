
struct cells *cells_new(struct cells *new_cells);
void cells_push_back(struct cells *cells, struct cell *cell);
void cells_remove(struct cells *cells, int index);
int cells_search_coordinate(struct cells *cells, int x, int y);
struct cells* player_maker(int n,struct map_attribute * bin_map);
