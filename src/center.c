/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:46:35 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 11:46:39 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_edge_coord(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->total)
	{
		calc_edge_coord(fdf, i);
		i++;
	}
}

void	calc_edge_coord(t_fdf *fdf, int index)
{
	if (!index)
	{
		fdf->x_min = fdf->tab[index].x2;
		fdf->x_max = fdf->tab[index].x2;
		fdf->y_min = fdf->tab[index].y2;
		fdf->y_max = fdf->tab[index].y2;
	}
	else
	{
		fdf->x_min = ft_min(fdf->x_min, fdf->tab[index].x2);
		fdf->x_max = ft_max(fdf->x_max, fdf->tab[index].x2);
		fdf->y_min = ft_min(fdf->y_min, fdf->tab[index].y2);
		fdf->y_max = ft_max(fdf->y_max, fdf->tab[index].y2);
	}
}

void	center(t_fdf *fdf)
{
	int dx;
	int dy;

	get_edge_coord(fdf);
	dx = fdf->x_max - fdf->x_min;
	dy = fdf->y_max - fdf->y_min;
	fdf->x_incr = 0;
	fdf->y_incr = 0;
	fdf->x_incr = (WIN_WIDTH / 2) - (dx / 2) - fdf->x_min;
	fdf->y_incr = (WIN_HEIGHT / 2) - (dy / 2) - fdf->y_min;
	fdf->x_shift += fdf->x_incr;
	fdf->y_shift += fdf->y_incr;
	do_calculations(fdf, 2);
}
