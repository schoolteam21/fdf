/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:12:23 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:12:26 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, const char **argv)
{
	int		fd;
	t_fdf	*fdf;

	if (argc == 1)
		empty_error();
	else if (argc != 2)
		bad_file_error();
	fd = open(argv[1], O_RDONLY);
	valid_map(fd);
	close(fd);
	fdf = fdf_instance();
	fd = open(argv[1], O_RDONLY);
	read_map(fd, 0, 0);
	vec_init();
	rotation(ENTER_KEY);
	mlx_hook(fdf->win, 2, 0, key_press, NULL);
	mlx_loop(fdf->mlx);
	return (0);
}
