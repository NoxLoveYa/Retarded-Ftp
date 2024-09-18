/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** file_commands
*/

#include "includes/commands.h"

void file_delete(client_t *client, ftp_t *ftp, char *command)
{
    (void)ftp;
    if (remove(command) == 0)
        dprintf(client->client_socket, "250 deleted file/dir at path.\r\n");
    else
        dprintf(client->client_socket, "550 path invalid.\r\n");
}
