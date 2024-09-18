/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** socket
*/

#pragma once

#include "my_ftp.h"

int create_socket(int domain, int type, int protocol);
int bind_socket(int sockfd, const struct sockaddr_in *addr);
int listen_socket(int sockfd, int backlog);
int accept_socket(int sockfd, struct sockaddr_in *addr, socklen_t *addrlen);
