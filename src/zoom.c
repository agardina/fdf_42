/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:49:16 by agardina          #+#    #+#             */
/*   Updated: 2020/01/29 15:53:47 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_zoom(t_fdf *fdf, t_point *a)
{
	a->x2 = a->x * (fdf->magn * fdf->zoom);
	a->y2 = a->y * (fdf->magn * fdf->zoom);
}

void	calculate_initial_zoom(t_fdf *fdf)
{
	int		dx;
	int		dy;
	float	incr;

	if (fdf->total > 1)
	{
		incr = 0.0;
		dx = fdf->x_max - fdf->x_min;
		dy = fdf->y_max - fdf->y_min;
		if (dx < (WIN_WIDTH / 4) && dy < (WIN_HEIGHT / 4))
		{
			while ((dx / fdf->zoom) * (fdf->zoom + incr) < WIN_WIDTH / 1.3
				&& (dy / fdf->zoom) * (fdf->zoom + incr) < WIN_HEIGHT / 1.3)
				incr += 0.02;
		}
		else if (dx > (WIN_WIDTH / 1.3) || dy > (WIN_HEIGHT / 1.3))
		{
			while (incr < 0.98
					&& ((dx / fdf->zoom) * (fdf->zoom + incr) > WIN_WIDTH / 1.3
				|| (dy / fdf->zoom) * (fdf->zoom + incr) > WIN_HEIGHT / 1.3))
				incr -= 0.02;
		}
		fdf->zoom += incr;
	}
}

void	change_zoom(t_fdf *fdf, int keycode)
{
	if (keycode == 24)
		fdf->zoom += 0.02;
	else if (keycode == 27)
	{
		fdf->zoom -= 0.02;
		if (fdf->zoom < 0.02)
			fdf->zoom = 0.02;
	}
	do_calculations(fdf, 1);
}
