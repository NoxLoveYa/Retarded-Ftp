/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** directory_commands
*/

#include "includes/commands.h"

void directory_pwd(client_t *client, ftp_t *ftp, char *command)
{
    char *path = getcwd(NULL, 0);

    (void)ftp;
    (void)command;
    if (path == NULL)
        dprintf(client->client_socket,
                "550 Failed to get the current directory.\r\n");
    else
        dprintf(client->client_socket,
                "257 \"%s\" is the current directory.\r\n", path);
    free(path);
}

void directory_cwd(client_t *client, ftp_t *ftp, char *command)
{
    (void)ftp;
    if (chdir(command) == 0)
        dprintf(client->client_socket,
                "250 Successfully changed the working directory.\r\n");
    else
        dprintf(client->client_socket,
                "550 Couldn't change the working directory.\r\n");
}

void directory_cdup(client_t *client, ftp_t *ftp, char *command)
{
    (void)ftp;
    (void)command;
    if (chdir("..") == 0)
        dprintf(client->client_socket,
                "250 Successfully changed the working directory.\r\n");
    else
        dprintf(client->client_socket,
                "550 Couldn't change the working directory.\r\n");
}
