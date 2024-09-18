/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** socket
*/

#include "includes/socket.h"

int create_socket(int domain, int type, int protocol)
{
    int sockfd = socket(domain, type, protocol);

    if (sockfd == -1)
    {
        perror("socket");
        exit(84);
    }
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
    return sockfd;
}

int bind_socket(int sockfd, const struct sockaddr_in *addr)
{
    int binded = bind(sockfd, (struct sockaddr *)addr, sizeof(*addr));

    if (binded == -1)
    {
        perror("bind");
        exit(84);
    }
    return binded;
}

int listen_socket(int sockfd, int backlog)
{
    int listened = listen(sockfd, backlog);

    if (listened == -1)
    {
        perror("listen");
        exit(84);
    }
    return listened;
}

int accept_socket(int sockfd, struct sockaddr_in *addr, socklen_t *addrlen)
{
    int new_socket = accept(sockfd, (struct sockaddr *)addr, addrlen);

    if (new_socket == -1)
    {
        perror("accept");
        exit(84);
    }
    return new_socket;
}
