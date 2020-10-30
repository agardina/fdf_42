/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:48:12 by agardina          #+#    #+#             */
/*   Updated: 2020/01/29 13:11:13 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		write(1, "usage: ./fdf <map>\n", 19);
	else
	{
		if ((fd = open((const char*)argv[1], O_RDONLY)) == -1)
			write(1, "No data found.\n", 15);
		else
			ft_fdf(fd);
	}
	return (0);
}

int		ft_fdf(int fd)
{
	t_fdf		fdf;

	init_fdf(&fdf, 1);
	if (check_map(fd, &fdf) > -1 && fdf.nbline > 0)
	{
		fdf.mlx.mlx_ptr = mlx_init();
		fdf.mlx.win_ptr = mlx_new_window(fdf.mlx.mlx_ptr, WIN_WIDTH,
				WIN_HEIGHT, "FdF");
		get_alt_max(&fdf);
		get_alt_min(&fdf);
		change_color(&fdf);
		do_calculations(&fdf, 1);
		get_edge_coord(&fdf);
		calculate_initial_zoom(&fdf);
		do_calculations(&fdf, 1);
		center(&fdf);
		ft_display(&fdf);
	}
	free_fdf(&fdf, 0);
	close(fd);
	return (1);
}

void	init_fdf(t_fdf *fdf, char proj)
{
	fdf->proj = proj;
	fdf->zoom = 1;
	fdf->magn = 30;
	fdf->altitude = 3;
	fdf->x_shift = 0;
	fdf->y_shift = 0;
	fdf->x_incr = 0;
	fdf->y_incr = 0;
	fdf->x_rotation = 0.0;
	fdf->y_rotation = 0.0;
	fdf->z_rotation = 0.0;
	fdf->mlx.mlx_ptr = NULL;
	fdf->mlx.win_ptr = NULL;
	fdf->mlx.img_ptr = NULL;
	fdf->mlx.img_data = NULL;
	fdf->nbcol = -1;
	fdf->nbline = 0;
	fdf->total = 0;
	fdf->tab = NULL;
	fdf->color_code = 1;
	fdf->display_menu = 1;
}

void	reset_fdf(t_fdf *fdf, char proj)
{
	fdf->proj = proj;
	fdf->zoom = 1;
	fdf->altitude = 3;
	fdf->x_shift = 0;
	fdf->y_shift = 0;
	fdf->x_incr = 0;
	fdf->y_incr = 0;
	fdf->x_rotation = 0.0;
	fdf->y_rotation = 0.0;
	fdf->z_rotation = 0.0;
	do_calculations(fdf, 1);
	get_edge_coord(fdf);
	calculate_initial_zoom(fdf);
	do_calculations(fdf, 1);
	center(fdf);
}
