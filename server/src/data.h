#ifndef KYKS_DATA_H
#define KYKS_DATA_H

#include "defs.h"

#include <stdbool.h>

typedef struct {
    int socketfd;
    char *ip;
    char *port;
    unsigned char buffer[KYKS_SOCKBUFFER_S];
} kyks_connection;

typedef struct {
    // See KYKS_SHIP_*
    int type;

    double health;
    double fuel;
    int crew;

    int fleet;
    char name[KYKS_NAME_S];
} kyks_ship;

typedef struct {
    int ships[KYKS_SHIPS_S];
    char name[KYKS_NAME_S];
    double x;
    double y;

    // Target destination
    double tx;
    double ty;

    // KYKS_FAST, ...
    int speed;
    // Radio reporting enabled
    bool radio;
    // see KYKS_FORM_*
    int formation;
    // If will bombard when near port
    // bool bombard;
    // Kindof useless idea, right
} kyks_fleet;

typedef struct {
    double x;
    double y;
    char name[KYKS_NAME_S];
    // Index of player, or -1 for none
    int owner;
    // Land defense resistance
    double resistance;
} kyks_port;

typedef struct {
    // The actual socket connection
    kyks_connection c;
    // The number of ships used in `ships`
    int numShips;
    kyks_ship ships[KYKS_SHIPS_S];
} kyks_player;

typedef struct {
    kyks_mapnode *map;
    int w;
    int h;
} kyks_map;

typedef struct {
    kyks_player players[KYKS_PLAYERS_S];
    kyks_port ports[KYKS_PORTS_S];
    kyks_map m;
} kyks_state;

#endif

