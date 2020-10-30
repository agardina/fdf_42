/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:46:18 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 11:51:15 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_altitude(t_fdf *fdf, int keycode)
{
	if (keycode == 13)
		fdf->altitude += 3;
	else if (keycode == 1)
		fdf->altitude -= 3;
	do_calculations(fdf, 1);
}

void	apply_altitude(t_fdf *fdf, t_point *a)
{
	a->z2 = a->z * (fdf->altitude * fdf->zoom);
}

void	get_alt_max(t_fdf *fdf)
{
	int i;

	i = 1;
	fdf->alt_max = ((fdf->tab)[0]).z;
	while (i < fdf->total)
	{
		fdf->alt_max = ft_max(fdf->alt_max, ((fdf->tab)[i]).z);
		i++;
	}
}

void	get_alt_min(t_fdf *fdf)
{
	int i;

	i = 1;
	fdf->alt_min = ((fdf->tab)[0]).z;
	while (i < fdf->total)
	{
		fdf->alt_min = ft_min(fdf->alt_min, ((fdf->tab)[i]).z);
		i++;
	}
}
