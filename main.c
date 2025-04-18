/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:01:10 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/18 06:59:55 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
    int fd_in;
    int fd_out;
    int pipe_fd[2];
    char    buffer[128];
    char    **args;
    pid_t pid;

    // =========== Verif du nombre d'args
    if (ac != 5)
    {
        fprintf(stderr, "Usage: %s file1 cmd1 cmd2 file2\n", av[0]); // A REMPLACER PAR FT_PRINTF DES QUE POSSIBLE
        return (1);
    }
    
    // ======== Test sur l'ouverture des fichiers
    fd_in = open(av[1], O_RDONLY);
    if (fd_in < 0)
        perror(av[1]);
    fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out < 0)
    {
        perror(av[4]);
        exit(EXIT_FAILURE);
    }
    
    // ============= Test sur Pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }
    
    write(pipe_fd[1], av[2], ft_strlen(av[2]));
    read(pipe_fd[0], buffer, sizeof(buffer));
    printf("Message reçu : %s\n", buffer);

    // ================== Test sur Fork + Pid
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        close(pipe_fd[1]);
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Enfant a lu : %s\n", buffer);
        close(pipe_fd[0]);
    }
    else
    {
        close(pipe_fd[0]);
        // write(pipe_fd[1], "Parent !", 8);
        close(pipe_fd[1]);
    }
    
    // ============= TEST SUR DUP2 !
    dup2(fd_in, STDIN_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[0]);
    close(fd_in);
    close(pipe_fd[1]);
    
    read(STDIN_FILENO, buffer, sizeof(buffer));
    printf("TEST a lu : %s\nNB arguments : %zu\n", buffer, ft_countword(buffer, ' '));
    // args = malloc(ft_countword(buffer, ' ') * sizeof(char *));

    args = ft_split(buffer, ' ');
    args[ft_countword(buffer, ' ') + 1] = NULL;
    printf("Affichage apres Split : %s\n", args[0]);
    printf("What ! \n");
    execve(ft_strjoin("/bin/", args[0]), args, __environ);
    printf("Fin de programme...\n");
    return (0);
}
