/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 04:29:40 by esamad-j          #+#    #+#             */
/*   Updated: 2023/11/17 04:30:45 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int get_max_x(char **map)
{
	int max_x;
	int x;
	int y;

	max_x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if(max_x < x)
			max_x = x;	
		y++;	
	}
	return(max_x);
}

int get_max_y(char **map)
{
	int y;

	y = 0;
	while (map[y])
			y++;
	return(y);
}


void remove_tmp_map(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

char **get_rectangular_map(t_map *map)
{
	char **tmp_map;
	int x;
	int y;

	map->max_x = get_max_x(map->map);
	map->max_y = get_max_y(map->map);
	tmp_map = ft_calloc(map->max_y + 3, sizeof(char*));
	if(!tmp_map)
		map_errors(0, "", map);
	y = -1;
	while (++y < map->max_y + 2)
	{
		tmp_map[y] = ft_calloc(map->max_x + 3, sizeof(char *));
		if(!tmp_map[y])
			map_errors(0, "", map);
		x = -1;
		while (++x < map->max_x + 2)
			tmp_map[y][x] = ' ';
		tmp_map[y][x]  = '\0';
	}
	tmp_map[y] = NULL;
	y = 0;
	while (++y < map->max_y + 1)
	{
		x = 0;
		while (++x < ft_strlen(map->map[y - 1]) + 1)
			tmp_map[y][x] = map->map[y-1][x-1];
	}
	//printDoublePointer(tmp_map);
	return(tmp_map);
}

int check_walls(t_map *map)
{
	char **tmp;
	int x;
	int y;
	
	y = -1;
	tmp = get_rectangular_map(map); //obtemer un mapa rectangular rodeado de ' ' por todos lados
	while (++y < get_max_y(tmp))
	{
		x = -1;
		while (++x < get_max_x(tmp))
		{
		if(tmp[y][x] == '0' ||tmp[y][x] == 'N' || tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E')
			if(tmp[y + 1][x] == ' ' || tmp[y - 1][x] == ' ' || tmp[y][x + 1] == ' '|| tmp[y][x - 1] == ' ')
				return (remove_tmp_map(tmp), -1);
		}
	}
	remove_tmp_map(tmp);
	return 0;
}