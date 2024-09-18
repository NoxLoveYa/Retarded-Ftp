/*
** EPITECH PROJECT, 2024
** B-NWP-400-MPL-4-1-myftp-censured.censured
** File description:
** main_server
*/

#include "includes/my_ftp.h"
#include "includes/server.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

int display_help(const char *cmd)
{
    if (strcmp(cmd, "-help") == 0 || strcmp(cmd, "--help") == 0)
    {
        printf("USAGE: ./myftp port path\n");
        printf("\tport is the port number on which the server socket");
        printf(" listens\n");
        printf("\tpath is the path to the home directory for the Anonymous");
        printf(" user\n");
        return 0;
    }
    return 84;
}

int check_dir(const char *path)
{
    struct stat sb;

    if (stat(path, &sb) || !S_ISDIR(sb.st_mode))
    {
        fprintf(stderr, "Error: %s is not a directory\n", path);
        return 84;
    }
    return 0;
}

void sig_int_handler(int sig_num)
{
    (void)sig_num;
    printf("\nCtrl+C. Exiting...\n");
    exit(0);
}

int main(int ac, char **av)
{
    ftp_t my_ftp = {.server = NULL, .client = NULL};

    if (ac != 3)
    {
        if (ac >= 2)
            return display_help(av[1]);
        return 84;
    }
    if (check_dir(av[2]) == 84)
        return 84;
    signal(SIGINT, sig_int_handler);
    my_ftp.server = init_server_struct(atoi(av[1]));
    my_ftp.client = NULL;
    if (!my_ftp.server)
        return 84;
    chdir(av[2]);
    run_server(&my_ftp);
    return 0;
}
