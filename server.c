/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** server
*/

#include "includes/server.h"
#include "includes/my_ftp.h"
#include "includes/socket.h"

int init_server_socket(server_t *server)
{
    int server_socket = create_socket(AF_INET, SOCK_STREAM, 0);

    bind_socket(server_socket, &server->server_addr);
    listen_socket(server_socket, 10);
    return server_socket;
}

server_t *init_server_struct(int port)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server || port < 1024 || port > 65535)
        return NULL;
    server->buffer = malloc(sizeof(char) * 1024);
    server->server_addr = (struct sockaddr_in){0};
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_port = htons(port);
    server->server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server->server_socket = init_server_socket(server);
    server->max_fd = server->server_socket;
    server->client_number = 0;
    FD_ZERO(&server->readfds);
    return server;
}

void server_perform_select(ftp_t *my_ftp)
{
    int activity = select(
        my_ftp->server->max_fd + 1, &my_ftp->server->readfds, NULL, NULL, NULL);

    if (activity < 0)
    {
        perror("select");
        exit(84);
    }
}

void run_server(ftp_t *my_ftp)
{
    client_t *tmp = NULL;

    while (true)
    {
        FD_ZERO(&my_ftp->server->readfds);
        FD_SET(my_ftp->server->server_socket, &my_ftp->server->readfds);
        for (tmp = my_ftp->client; tmp; tmp = tmp->next)
        {
            FD_SET(tmp->client_socket, &my_ftp->server->readfds);
        }
        server_perform_select(my_ftp);
        if (FD_ISSET(my_ftp->server->server_socket, &my_ftp->server->readfds))
            accept_client(my_ftp);
        for (tmp = my_ftp->client; tmp; tmp = tmp->next)
        {
            server_perform_read(tmp, my_ftp);
        }
    }
}
