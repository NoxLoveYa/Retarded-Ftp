/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** server
*/

#pragma once

#include "my_ftp.h"

server_t *init_server_struct(int port);
void server_perform_select(ftp_t *my_ftp);
void accept_client(ftp_t *my_ftp);
void server_perform_read(client_t *client, ftp_t *ftp);
void run_server(ftp_t *my_ftp);
