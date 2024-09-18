/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** client
*/

#pragma once

#include "my_ftp.h"
#include "buffer_utils.h"

client_t *init_client_struct(int client_socket, int client_id);
void add_client(client_t *client, ftp_t *my_ftp);
void remove_client(client_t *client, ftp_t *my_ftp);
