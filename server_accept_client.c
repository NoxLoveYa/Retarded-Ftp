/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** server_accept_client
*/

#include "includes/my_ftp.h"
#include "includes/socket.h"
#include "includes/client.h"

void accept_client(ftp_t *my_ftp)
{
    int new_socket;
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);
    int server_socket = my_ftp->server->server_socket;

    new_socket = accept_socket(server_socket, &client_addr, &addrlen);
    if (new_socket < 0)
        exit(84);
    add_client(
        init_client_struct(new_socket, my_ftp->server->client_number), my_ftp);
    if (my_ftp->server->max_fd < new_socket)
        my_ftp->server->max_fd = new_socket;
    my_ftp->server->client_number++;
    dprintf(new_socket, "220 Service ready for new user.\r\n");
    printf("A new client has connected: id = %d\n",
           my_ftp->server->client_number - 1);
}
