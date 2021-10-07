#ifndef KYKS_NET_H
#define KYKS_NET_H

#include "data.h"

#include <stddef.h>

int kyks_net_init(kyks_net *s, const char *port);
int kyks_net_close(kyks_net *s);

int kyks_net_accept(kyks_net *s, kyks_netcon *con);
int kyks_net_alive(kyks_netcon *con);
void kyks_net_disconnect(kyks_netcon *con);
int kyks_net_send(kyks_netcon *con, const void *data, size_t len);

#endif

