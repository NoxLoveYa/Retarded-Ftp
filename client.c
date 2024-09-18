/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** client
*/

#include "includes/client.h"

client_t *init_client_struct(int client_socket, int client_id)
{
    client_t *client = malloc(sizeof(client_t));

    client->client_socket = client_socket;
    client->buffer_size = sizeof(char) * 1024;
    client->buffer = init_buffer_command(client->buffer_size);
    client->client_id = client_id;
    client->read_n = 0;
    client->write_n = 0;
    client->is_logged = false;
    client->allow_pass = false;
    client->next = NULL;
    return client;
}

void add_client(client_t *client, ftp_t *my_ftp)
{
    client_t *tmp = my_ftp->client;

    if (my_ftp->client == NULL)
    {
        my_ftp->client = client;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = client;
}

void remove_client(client_t *client, ftp_t *my_ftp)
{
    client_t *tmp = my_ftp->client;

    close(client->client_socket);
    free(client->buffer);
    if (my_ftp->client == NULL)
        return;
    if (my_ftp->client->client_id == client->client_id)
    {
        my_ftp->client = my_ftp->client->next;
        return;
    }
    while (tmp->next != NULL)
    {
        if (tmp->next->client_socket == client->client_socket)
        {
            tmp->next = tmp->next->next;
            return;
        }
        tmp = tmp->next;
    }
    free(client);
}
