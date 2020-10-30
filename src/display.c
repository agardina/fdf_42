/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:47:17 by agardina          #+#    #+#             */
/*   Updated: 2020/02/03 19:41:05 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_segment(t_fdf *fdf, t_point a, t_point b)
{
	if (b.x > -1)
		print_line_img(&(fdf->mlx), a, b);
}

void	ft_display(t_fdf *fdf)
{
	if (fdf->mlx.img_ptr)
		ft_bzero(fdf->mlx.img_data, WIN_WIDTH * WIN_HEIGHT * 4);
	if (fdf->mlx.img_ptr == NULL)
	{
		fdf->mlx.img_ptr = mlx_new_image(fdf->mlx.mlx_ptr, WIN_WIDTH,
				WIN_HEIGHT);
		fdf->mlx.img_data = mlx_get_data_addr(fdf->mlx.img_ptr,
				&(fdf->mlx.bpp), &(fdf->mlx.size_line), &(fdf->mlx.endian));
	}
	draw_map(fdf);
	display_menu(fdf);
	mlx_hook(fdf->mlx.win_ptr, 2, 0, &key_hook, fdf);
	mlx_loop(fdf->mlx.mlx_ptr);
}

void	display_menu(t_fdf *fdf)
{
	if (fdf->display_menu)
	{
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 2, 0xFDEE00,
				"----- LIST OF COMMANDS (hide: 1) -----");
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 32, 0xFDEE00,
				"Zoom out/in: -/+");
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 52, 0xFDEE00,
				"Lower/increase altitude: W/S");
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 72, 0xFDEE00,
				"Move camera: up/down/left/right arrow");
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 92, 0xFDEE00,
				"Center: C");
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 112, 0xFDEE00,
				"X/Y/Z/all axes rotation: 3-4/5-6/7-8/9-0");
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 132, 0xFDEE00,
				"Change color: 2");
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 152, 0xFDEE00,
				"Change/reset projection: X/Z");
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 172, 0xFDEE00,
				"Exit: ESC");
	}
	else
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 10, 2, 0xFDEE00,
				"----- LIST OF COMMANDS (show: 1) -----");
}

void	draw_map(t_fdf *fdf)
{
	int		i;
	t_point	a;
	t_point	b;

	i = -1;
	while (++i < fdf->total)
	{
		a = fdf->tab[i];
		get_point_on_the_right(fdf, i, a, &b);
		draw_segment(fdf, a, b);
		get_point_under(fdf, i, a, &b);
		draw_segment(fdf, a, b);
	}
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr,
			fdf->mlx.img_ptr, 0, 0);
}
