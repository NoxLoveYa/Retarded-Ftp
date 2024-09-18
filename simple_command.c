/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** simple_command
*/

#include "includes/commands.h"

void simple_noop(client_t *client, ftp_t *ftp, char *command)
{
    (void)ftp;
    (void)command;
    dprintf(client->client_socket, "200 did nothing :).\r\n");
}

void simple_help(client_t *client, ftp_t *ftp, char *command)
{
    (void)ftp;
    (void)command;
    dprintf(client->client_socket, "214 i'm too lazy, you guess ;)\r\n");
}

void simple_quit(client_t *client, ftp_t *ftp, char *command)
{
    (void)command;
    dprintf(client->client_socket, "221 Goodbye.\r\n");
    remove_client(client, ftp);
}
