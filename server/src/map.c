#include "map.h"

#include <stdlib.h>

int kyks_map_gen(kyks_map *m, int w, int h) {
    int size = w * h;
    kyks_mapnode *map = (kyks_mapnode *) calloc(size, sizeof(kyks_mapnode));
    map[0 + w * 0] = KYKS_MAP_PORT(0);
    map[2 + w * 2] = KYKS_MAP_PORT(1);
    map[3 + w * 3] = KYKS_MAP_PORT(2);
    map[1 + w * 0] = KYKS_MAP_PORT(3);
    m->map = map;
    m->w = w;
    m->h = h;
    return 0;
}

void kyks_map_free(kyks_map *m) {
    free(m->map);
}



