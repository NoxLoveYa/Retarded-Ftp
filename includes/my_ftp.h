/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** ftp
*/

#pragma once

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

typedef struct server_s
{
    int server_socket;
    int *buffer;
    struct sockaddr_in server_addr;
    fd_set readfds;
    int max_fd;
    int client_number;
} server_t;

typedef struct client_s
{
    int client_id;
    int client_socket;
    int buffer_size;
    char *buffer;
    int read_n;
    int write_n;
    bool is_logged;
    bool allow_pass;
    struct client_s *next;
} client_t;

typedef struct ftp_s
{
    server_t *server;
    client_t *client;
} ftp_t;

typedef struct command_s
{
    char *command;
    void (*func)(client_t *client, ftp_t *ftp, char *command);
} command_t;
