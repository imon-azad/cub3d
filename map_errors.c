/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:07:28 by aoteo-be          #+#    #+#             */
/*   Updated: 2023/11/14 01:43:20 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_cub(char *argv)
{
	int	n;

	n = (int)ft_strlen(argv);
	if (argv[n - 1] != 'b')
		return (-1);
	if (argv[n - 2] != 'u')
		return (-1);
	if (argv[n - 3] != 'c')
		return (-1);
	if (argv[n - 4] != '.')
		return (-1);
	return (0);
}

void	check_input(int parameters_number, char **argv)
{
	
    if (parameters_number != 2)
	{
		printf("%s%s\n", ERROR, "Usage: cub3D map file name, ");
		if (parameters_number < 2)
			printf("no map file provided.\n");
		else
			printf("only one parameter allowed.\n");
		exit (EXIT_FAILURE);
	}
	else
		if(check_cub(argv[1]) == -1)
		{
			printf("%s%s\n", ERROR, "Map must be in .cub\n");
			exit(EXIT_FAILURE);
		}
		
		
		
		
}

/* void	check_map_param(char *line, char **param, char *param_name)
{
	if (*param != NULL)
		map_errors(1, param_name, NULL);
	*param = malloc(sizeof(char) * (ft_strlen(line) + 1) - 3);
	if (*param == NULL)
		map_errors(4, param_name, NULL);
	ft_memcpy(*param, line + 3, ft_strlen(line) - 3);
}

void	check_no_parameter(t_map *map)
{
	if (map->no == NULL)
		map_errors(2, "NO", map);
	if (map->so == NULL)
		map_errors(2, "SO", map);
	if (map->ea == NULL)
		map_errors(2, "EA", map);
	if (map->we == NULL)
		map_errors(2, "WE", map);
	if (map->f == NULL)
		map_errors(2, "F", map);
	if (map->c == NULL)
		map_errors(2, "C", map);
}

void	file_errors(ssize_t index, char *map_data)
{
	printf("%s", ERROR);
	if (index == -1)
		printf("Couldn't read map file.");
	if (index == 0)
		printf("Empty map file.");
	printf("\n");
	if (map_data != NULL)
		free(map_data);
	exit (EXIT_FAILURE);
}

void	map_errors(int i, char *parameter, t_map *map_data)
{
	printf("%s", ERROR);
	if (i == 0)
		printf("Memory error.");
	else if (i == 1)
		printf("parameter %s duplicated.", parameter);
	else if (i == 2)
		printf("parameter %s not defined.", parameter);
	else if (i == 3)
		printf("Initial row should have optional leading spaces and 1's.");
	else if (i == 4)
		printf("Unknown map symbol.");
	else if (i == 5)
		printf("Map should be surrounded by walls.");
	printf("\n");
	if (map_data->no != NULL)
		free(map_data->no);
	if (map_data->so != NULL)
		free(map_data->so);
	if (map_data->ea != NULL)
		free(map_data->ea);
	if (map_data->we != NULL)
		free(map_data->we);
	if (map_data != NULL)
		free(map_data);
	exit (EXIT_FAILURE);
} */
