/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:04:56 by esamad-j          #+#    #+#             */
/*   Updated: 2023/11/17 05:13:15 by esamad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#endif
# include <fcntl.h>
# include "mlx/mlx.h"
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define ERROR		"\33[31mError\n"

typedef struct s_player
{
    int pos_x;
    int pos_y;


    
}   t_player;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
	char	**map;
	int		num_lines;
    int     max_y;
    int     max_x;
    t_player    player;
}	t_map;


void printDoublePointer(char **matrix); //herramientas

/*PARSEO*/

void	check_input(int parameters_number, char **argv);
void	map_errors(int i, char *parameter, t_map *map_data);
int	check_cub(char *argv);
void check_empty_line(char *line);
void	check_map_param(char *line, char **param, char *param_name, int i);
void	check_map_data(t_map *all_map, char **map_data);
void	check_no_parameter(t_map *map);
int	check_chars(t_map *all_map, char value, int x, int y);
void check_player_pos(t_map *all_map);


/*Check map*/
int check_walls(t_map *map);
char **get_rectangular_map(t_map *map);
void remove_tmp_map(char **tmp);
int get_max_y(char **map);
int get_max_x(char **map);

/*map read*/
char **read_file(char *map_name, int fd_map);
char    **read_map(char *map_name);



