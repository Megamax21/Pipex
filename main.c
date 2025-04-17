/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:01:10 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/16 01:20:28 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
    if (ac != 5)
    {
        fprintf(stderr, "Usage: %s file1 cmd1 cmd2 file2\n", av[0]); // A REMPLACER PAR FT_PRINTF DES QUE POSSIBLE
        return 1;
    }

    // Reste du programme ici...
    return 0;
}