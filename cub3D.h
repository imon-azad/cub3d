/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esamad-j <esamad-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:04:56 by esamad-j          #+#    #+#             */
/*   Updated: 2023/11/14 01:49:54 by esamad-j         ###   ########.fr       */
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

/*PARSEO*/

void	check_input(int parameters_number, char **argv);

/*map read*/
char **read_file(char *map_name, int fd_map);
char    **read_map(char *map_name);


