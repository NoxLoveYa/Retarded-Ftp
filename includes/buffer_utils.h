/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** buffer_utils
*/

#pragma once

#include "my_ftp.h"
#include <stdlib.h>
#include <string.h>

char *init_buffer_command(int size);
char *get_command_from_circular_buffer(client_t *client);
