#ifndef KYKS_DEFS_H
#define KYKS_DEFS_H

#define KYKS_PLAYERS_S    16
#define KYKS_PORTS_S      16
#define KYKS_SHIPS_S      16
#define KYKS_NAME_S  32
#define KYKS_SOCKBUFFER_S 16

#define KYKS_MAP_OCEAN  0
#define KYKS_MAP_LAND   1
#define KYKS_MAP_PORT(n) (KYKS_MAP_LAND + 1 + n)

#define KYKS_SPEED_STOP         0
#define KYKS_SPEED_SLOW         1
#define KYKS_SPEED_NORMAL       2
#define KYKS_SPEED_FAST         3
#define KYKS_SPEED_FASTEST      4

#define KYKS_FORM_LINE          0
#define KYKS_FORM_DIMOND        0

// Ship type defs
#define KYKS_SHIP_SS 0
#define KYKS_SHIP_DD 1
#define KYKS_SHIP_CL 2
#define KYKS_SHIP_BB 3
#define KYKS_SHIP_CA 4
#define KYKS_SHIP_TR 5
// Lone aircraft
// I know, it's a little weird classifying it as a ship
// but it can interact with other ships, and whatever.
// So yah.
#define KYKS_SHIP_AI 6


typedef unsigned char kyks_mapnode;

#endif

