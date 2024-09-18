/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** commands
*/

#pragma once

#include "my_ftp.h"
#include "client.h"

void login_user(client_t *client, ftp_t *ftp, char *command);
void login_password(client_t *client, ftp_t *ftp, char *command);

void simple_noop(client_t *client, ftp_t *ftp, char *command);
void simple_help(client_t *client, ftp_t *ftp, char *command);
void simple_quit(client_t *client, ftp_t *ftp, char *command);

void file_delete(client_t *client, ftp_t *ftp, char *command);

void directory_pwd(client_t *client, ftp_t *ftp, char *command);
void directory_cwd(client_t *client, ftp_t *ftp, char *command);
void directory_cdup(client_t *client, ftp_t *ftp, char *command);
