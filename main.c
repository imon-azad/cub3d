/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:56:12 by esamad-j          #+#    #+#             */
/*   Updated: 2023/11/14 01:59:46 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void printDoublePointer(char **matrix) {
    while (*matrix != NULL && **matrix != '\0') {
        printf("%s\n", *matrix);
        matrix++;
    }
}

int	main(int argc, char **argv)
{
    char	**map_data;
    int		fd;
    
    check_input(argc, argv);
    map_data = read_map(argv[1]);
	
	printDoublePointer(map_data);

	return (0);
}