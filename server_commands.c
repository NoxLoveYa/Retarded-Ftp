/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** server_commands
*/

#include "includes/my_ftp.h"
#include "includes/socket.h"
#include "includes/client.h"
#include "includes/buffer_utils.h"
#include "includes/commands.h"

command_t commands[] = {
    {"USER", login_user},
    {"PASS", login_password},
    {"CWD", directory_cwd},
    {"CDUP", directory_cdup},
    {"QUIT", simple_quit},
    {"DELE", file_delete},
    {"PWD", directory_pwd},
    {"PASV", NULL},
    {"PORT", NULL},
    {"HELP", simple_help},
    {"NOOP", simple_noop},
    {"RETR", NULL},
    {"STOR", NULL},
    {"LIST", NULL},
    {NULL, NULL}};

void server_exec_command(client_t *client, ftp_t *ftp)
{
    char *command = get_command_from_circular_buffer(client);
    bool cmd_found = false;
    int cmd_len = 0;

    for (int i = 0; commands[i].command != NULL; i++)
    {
        cmd_len = strlen(commands[i].command);
        if (!strncasecmp(command, commands[i].command, cmd_len) == 0)
            continue;
        cmd_found = true;
        if ((i >= 2 && !client->is_logged) || commands[i].func == NULL)
            dprintf(client->client_socket, "530 Not authentified.\r\n");
        else
            commands[i].func(client, ftp, command + cmd_len + 1);
        break;
    }
    if (!cmd_found)
        dprintf(client->client_socket, "500 Unknown command.\r\n");
    if (command != NULL)
        free(command);
}

void server_perform_read(client_t *client, ftp_t *ftp)
{
    char *buffer = init_buffer_command(client->buffer_size);
    int read_size = 0;

    if (!FD_ISSET(client->client_socket, &ftp->server->readfds))
        return;
    read_size = read(client->client_socket, buffer, client->buffer_size);
    if (read_size <= 0)
    {
        remove_client(client, ftp);
        return;
    }
    for (int i = 0; i < read_size; i++)
    {
        client->buffer[client->write_n] = buffer[i];
        client->write_n++;
        if (client->write_n >= client->buffer_size)
            client->write_n = 0;
    }
    client->write_n--;
    if (strstr(buffer, "\r\n") != NULL)
        server_exec_command(client, ftp);
    free(buffer);
}
