/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** login
*/

#include "includes/commands.h"

void login_user(client_t *client, ftp_t *ftp, char *command)
{
    (void)ftp;
    if (client->allow_pass)
    {
        dprintf(client->client_socket,
                "530 Can't change from guest user.\r\n");
        return;
    }
    dprintf(client->client_socket, "331 ");
    if (strncmp(command, "Anonymous", 9) == 0)
    {
        dprintf(client->client_socket, "User logged in, proceed.\r\n");
        client->allow_pass = true;
    }
    else
        dprintf(client->client_socket, "Wrong user.\r\n");
}

void login_password(client_t *client, ftp_t *ftp, char *command)
{
    (void)ftp;
    if (client->is_logged)
    {
        dprintf(client->client_socket,
                "530 Can't change from guest user.\r\n");
        return;
    }
    if (client->allow_pass && command[0] == '\0')
    {
        dprintf(client->client_socket,
                "230 Pass correct, successfully connected.\r\n");
        client->is_logged = true;
    }
    else
        dprintf(client->client_socket,
                "530 Pass incorrect, login failed.\r\n");
}
