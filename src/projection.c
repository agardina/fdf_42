/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:48:36 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 11:48:39 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_proj(t_fdf *fdf)
{
	if (fdf->proj == 1)
		fdf->proj = 2;
	else
		fdf->proj = 1;
	reset_fdf(fdf, fdf->proj);
}

void	apply_proj(t_fdf *fdf, t_point *a)
{
	if (fdf->proj == 1)
		iso(a);
	else
		cabinet(a);
}

void	iso(t_point *p)
{
	int old_x2;
	int old_y2;

	old_x2 = p->x2;
	old_y2 = p->y2;
	p->x2 = (old_x2 - old_y2) * cos(0.523599);
	p->y2 = -(p->z2) + (old_x2 + p->y2) * sin(0.523599);
}

void	cabinet(t_point *p)
{
	int old_x2;
	int old_y2;

	old_x2 = p->x2;
	old_y2 = p->y2;
	p->x2 = old_x2 + p->z2 * cos(-1) * 0.5;
	p->y2 = old_y2 + p->z2 * sin(-1) * 0.5;
}
