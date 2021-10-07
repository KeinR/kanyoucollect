#include "net.h"

#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

/*
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
*/

int kyks_net_init(kyks_net *s, const char *port) {
    struct addrinfo hints;
    struct addrinfo *res;
    int sockfd, err, rc, flags;

    rc = 0;

    // first, load up address structs with getaddrinfo():

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

    err = getaddrinfo(NULL, port, &hints, &res);
    if (err) {
        rc = 1;
        goto end1;
    }

    // make a socket:

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        rc = 1;
        goto end0;
    }

    s->socketfd = sockfd;

    // Don't block
    flags = fcntl(sockfd, F_GETFL, 0);
    err = fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    if (err == -1) {
        rc = 1;
        goto end0;
    }

    // bind it to the port we passed in to getaddrinfo():

    err = bind(sockfd, res->ai_addr, res->ai_addrlen);
    if (err == -1) {
        rc = 1;
        goto end0;
    }

    

end0:
    freeaddrinfo(res);
end1:
    return rc;
}

int kyks_net_listen(kyks_state *s) {
    int err = listen(s->net.socketfd, 10);
    if (err == -1)
        return 1;
    return 0;
}

int kyks_net_accept(kyks_net *s, kyks_netcon *id) {
    // struct sockaddr adr;
    // socklen_t len;
    // int sock = accept(s->net.socketfd, &adr, &len);
    int sock = accept(s->socketfd, NULL, NULL);
    if (sock == -1) return 1;
    id->socketfd = sock;
    return 0;
}

int kyks_net_close(kyks_net *s) {
    close(s->socketfd);
}

int kyks_net_alive(kyks_netcon *s) {
    return s->alive;
}

void kyks_net_disconnect(kyks_netcon *s) {
    close(s->socketfd);
}

int kyks_net_send(kyks_netcon *con, const void *data, size_t len) {
    size_t ofs = 0;
    while (ofs < len) {
        int ret = send(con->socketfd, data + ofs, len - ofs, 0);
        if (ret == 0)
            return 1;
        ofs += ret;
    }
    return 0;
}

int kyks_net_recieve(kyks_netcon *con, void *buffer, size_t bufSize, size_t *len) {
    *len = recv(con->socketfd, buffer, bufSize, 0);
    if (*len <= 0)
        return 1;
    return 0;
}


