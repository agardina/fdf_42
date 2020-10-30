/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:48:47 by agardina          #+#    #+#             */
/*   Updated: 2020/02/03 18:59:26 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_rotation(t_fdf *fdf, int keycode)
{
	if (keycode == 20 || keycode == 25)
		fdf->x_rotation -= 0.261799;
	if (keycode == 21 || keycode == 29)
		fdf->x_rotation += 0.261799;
	if (keycode == 23 || keycode == 25)
		fdf->y_rotation -= 0.261799;
	if (keycode == 22 || keycode == 29)
		fdf->y_rotation += 0.261799;
	if (keycode == 26 || keycode == 25)
		fdf->z_rotation -= 0.261799;
	if (keycode == 28 || keycode == 29)
		fdf->z_rotation += 0.261799;
	do_calculations(fdf, 1);
}

void	apply_rotation(t_fdf *fdf, t_point *a, t_rot_data *r)
{
	int old_x2;
	int old_y2;
	int old_z2;

	old_x2 = a->x2 - ((fdf->x_max - fdf->x_min) / 2);
	old_y2 = a->y2 - ((fdf->y_max - fdf->y_min) / 2);
	old_z2 = a->z2;
	a->x2 = old_x2 * r->c * r->e - old_y2 * r->c * r->f + r->d * old_z2;
	a->y2 = old_x2 * r->bd * r->e + old_x2 * r->a * r->f
		- old_y2 * r->bd * r->f + old_y2 * r->a * r->e - old_z2 * r->b * r->c;
	a->z2 = -r->ad * r->e * old_x2 + r->b * r->f * old_x2
		+ r->ad * r->f * old_y2 + r->b * r->e * old_y2 + r->a * r->c * old_z2;
}

void	set_rot_data(t_fdf *fdf, t_rot_data *r)
{
	r->a = cos(fdf->x_rotation);
	r->b = sin(fdf->x_rotation);
	r->c = cos(fdf->y_rotation);
	r->d = sin(fdf->y_rotation);
	r->e = cos(fdf->z_rotation);
	r->f = sin(fdf->z_rotation);
	r->ad = r->a * r->d;
	r->bd = r->b * r->d;
}
