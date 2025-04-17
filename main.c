/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:01:10 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/17 14:57:24 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
    int fd_in;
    int fd_out;

    if (ac != 5)
    {
        fprintf(stderr, "Usage: %s file1 cmd1 cmd2 file2\n", av[0]); // A REMPLACER PAR FT_PRINTF DES QUE POSSIBLE
        return (1);
    }
    fd_in = open(av[1], O_RDONLY);
    if (fd_in < 0)
        perror(av[1]);
    fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out < 0)
    {
        perror(av[4]);
        exit(EXIT_FAILURE);
    }

    
    return (0);
}