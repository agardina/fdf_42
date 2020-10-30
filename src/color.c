/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:46:58 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:07:28 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(t_fdf *fdf)
{
	int		i;
	t_point	*a;

	fdf->color = set_fdf_color(fdf);
	i = 0;
	while (i < fdf->total)
	{
		a = &(fdf->tab[i]);
		set_point_color(fdf, a);
		i++;
	}
}

int		set_fdf_color(t_fdf *fdf)
{
	fdf->color_code %= 7;
	if (fdf->color_code == 1)
		return (BLUE);
	if (fdf->color_code == 2)
		return (GREEN);
	if (fdf->color_code == 3)
		return (ORANGE);
	if (fdf->color_code == 4)
		return (RED);
	if (fdf->color_code == 5)
		return (YELLOW);
	if (fdf->color_code == 6)
		return (WHITE);
	return (-1);
}

void	set_point_color(t_fdf *fdf, t_point *a)
{
	t_gradient	grad;

	if (fdf->color > -1)
	{
		grad.start.z = fdf->alt_min;
		grad.start.color = fdf->color;
		grad.finish.z = fdf->alt_max;
		grad.finish.color =
		fdf->alt_min == fdf->alt_max ? fdf->color : 0xFFFFFF;
		a->color = get_gradient(grad, *a, 3);
	}
	else
	{
		grad.start.z = geo_mode_alt(a->z, 1);
		grad.start.color = geo_mode_color(grad.start.z);
		grad.finish.z = geo_mode_alt(a->z, 2);
		grad.finish.color = geo_mode_color(grad.finish.z);
		a->color = get_gradient(grad, *a, 3);
	}
}

int		geo_mode_alt(int z, char a)
{
	if (z <= -10)
		return (-10);
	if (-10 < z && z < 0)
		return (a == 1 ? -10 : 0);
	if (z == 0)
		return (0);
	if (0 < z && z <= 10)
		return (a == 1 ? 0 : 10);
	if (10 < z && z <= 20)
		return (a == 1 ? 10 : 20);
	if (20 < z && z <= 30)
		return (a == 1 ? 20 : 30);
	if (30 < z)
		return (geo_mode_alt2(z, a));
	return (100);
}

int		geo_mode_alt2(int z, char a)
{
	if (30 < z && z <= 40)
		return (a == 1 ? 30 : 40);
	if (40 < z && z <= 50)
		return (a == 1 ? 40 : 50);
	if (50 < z && z <= 100)
		return (a == 1 ? 50 : 100);
	if (100 < z)
		return (100);
	return (100);
}
