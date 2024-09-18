/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** buffer_utils
*/

#include "includes/buffer_utils.h"

char *init_buffer_command(int size)
{
    char *buffer = malloc(size);

    if (!buffer)
        return NULL;
    memset(buffer, '\0', size);
    return buffer;
}

void fill_command_from_circular_buffer(
    client_t *client, int read_start, int size, char *command)
{
    for (int i = 0; i < size; i++)
    {
        command[i] = client->buffer[read_start];
        read_start++;
        if (read_start >= client->buffer_size)
            read_start = 0;
    }
}

char *get_command_from_circular_buffer(client_t *client)
{
    int size = 0;
    char *command = NULL;
    int o_read = client->read_n;

    for (size = 0; client->read_n != client->write_n; size++)
    {
        if (client->buffer[client->read_n] == '\r' &&
            client->buffer[client->read_n + 1] == '\n')
        {
            client->read_n += 2;
            break;
        }
        client->read_n++;
        if (client->read_n >= client->buffer_size)
            client->read_n = 0;
    }
    client->read_n--;
    command = malloc(size + 1);
    command[size] = '\0';
    fill_command_from_circular_buffer(client, o_read, size, command);
    return command;
}
