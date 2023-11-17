/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:56:12 by esamad-j          #+#    #+#             */
/*   Updated: 2023/11/17 05:14:10 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void printDoublePointer(char **matrix) {
    while (*matrix != NULL && **matrix != '\0') {
        printf("%s\n", *matrix);
        matrix++;
    }
}

t_map	*create_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		map_errors(0, "", NULL);
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->f = NULL;
	map->c = NULL;
	map->map = NULL; //solo mapa sin datos de textura
	map->player.pos_x = 0;
	map->player.pos_y = 0;
	return (map);
}

int	main(int argc, char **argv)
{
    char	**map_data;

    check_input(argc, argv); //Comprueba lo basico, si hay argv etc
    map_data = read_map(argv[1]); // Lee el mapa con gnl y lo devuelve con split 
	check_map_data(create_map(), map_data); 
	
	//printDoublePointer(map_data);

	return (0);
}