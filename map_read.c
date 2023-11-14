/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:34:29 by esamad-j          #+#    #+#             */
/*   Updated: 2023/11/14 03:13:08 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_empty_line(char *line)
{
    static int count = 0;
    static int init_map = 0;
    static int finish_map = 0;
    int line_len;

    line_len = ft_strlen(line);
    if(count == 6 && line_len > 1 && !init_map)
        init_map = 1;
    if(count < 6 && line_len > 1)
        count++;
    if (init_map && ft_strlen(line) == 1 && !finish_map)
		finish_map++;
    if((line_len > 1 || *line != '\n') && finish_map)
    {
        printf("%s%s\n", ERROR, "Empty line in map.\n");
		exit(EXIT_FAILURE);	
    }

    
}

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