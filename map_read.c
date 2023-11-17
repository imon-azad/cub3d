/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:34:29 by esamad-j          #+#    #+#             */
/*   Updated: 2023/11/17 05:13:27 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



char **read_file(char *map_name, int fd_map)
{
	char **map;
	char *lines;
	char *tmp;

	tmp = get_next_line(fd_map);
	lines = malloc(1);
	if(!lines)
	{
		printf("%s%s\n", ERROR, "Malloc error.\n");
		exit(EXIT_FAILURE);	
	}
	while (tmp != NULL)
	{
        check_empty_line(tmp);
		lines = ft_strjoin_gnl(lines, tmp);
		free(tmp);
		tmp = get_next_line(fd_map);
	}
	free(tmp);
	close(fd_map);
	map = ft_split(lines, '\n');
	free(lines);
	return(map);
}


char    **read_map(char *map_name)
{
    int fd_map;
	int read_bytes;
	char **map_txt;
	char *tmp;
    
    fd_map = open(map_name, O_RDONLY);
    if(fd_map == -1)
    {
        printf("%s%s\n", ERROR, "Opening file error.\n");
		exit (EXIT_FAILURE);
    }
	if (read(fd_map, 0, 1) == 0)
	{
		printf("%s%s\n", ERROR, "Empty map file\n");
		exit (EXIT_FAILURE);
	}
	map_txt = read_file(map_name, fd_map);

    return(map_txt);
}


void	check_map_data(t_map *all_map, char **map_data)
{
	int		i;
	
	all_map->map = map_data + 6; // MAP solo es el mapa sin datos de texturas ni color
	i = -1;
	while (map_data[++i] != NULL)
	{
		if (!ft_strncmp(map_data[i], "NO", 2))
			check_map_param(map_data[i], &(all_map->no), "NO", 3);
		else if (!ft_strncmp(map_data[i], "SO", 2))
			check_map_param(map_data[i], &(all_map->so), "SO", 3);
		else if (!ft_strncmp(map_data[i], "EA", 2))
			check_map_param(map_data[i], &(all_map->ea), "EA", 3);
		else if (!ft_strncmp(map_data[i], "WE", 2))
			check_map_param(map_data[i], &(all_map->we), "WE", 3);
		else if (!ft_strncmp(map_data[i], "F", 1))
			check_map_param(map_data[i], &(all_map->f), "F", 2);
		else if (!ft_strncmp(map_data[i], "C", 1))
			check_map_param(map_data[i], &(all_map->c), "C", 2);
	}
	check_no_parameter(all_map);//comprobar si tiene todos los datos de textura y color
	check_player_pos(all_map); //comprobar si hay un jugador o si hay mas
	if(check_walls(all_map) == -1) //comprobar si hay paredes
		map_errors(8, "", all_map);
	//printf("%s\n",all_map->f);
	//printDoublePointer(map_data);
}

int	check_chars(t_map *all_map, char value, int x, int y)
{
	if (value != '1' && value != '0' && value != 'N'
		&& value != 'S' && value != 'E' && value != 'W' && value != ' ')
		map_errors(4, "", all_map);
	if (value == 'N' || value == 'S' || value == 'E' || value == 'W')
	{
		all_map->player.pos_y = y;
		all_map->player.pos_x = x;
		return (1);
	}
	return (0);
}

void check_player_pos(t_map *all_map)
{
	int	x;
	int	y;
	int	player_flag;

	y = -1;
	player_flag = 0;
	while (all_map->map[++y])
	{
		x = -1;
		while (all_map->map[y][++x])
			player_flag += check_chars(all_map, all_map->map[y][x], x, y);		
	}
	if(player_flag > 1)
		map_errors(6, "", all_map);
	if(!player_flag)
		map_errors(7, "", all_map);
}