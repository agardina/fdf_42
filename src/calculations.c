/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:58:04 by agardina          #+#    #+#             */
/*   Updated: 2020/02/03 19:00:27 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_calculations(t_fdf *fdf, char c)
{
	int		i;
	t_point	*a;

	if (c == 1)
	{
		do_calculations1(fdf);
		do_calculations2(fdf);
	}
	else
	{
		i = 0;
		while (i < fdf->total)
		{
			a = &(fdf->tab[i]);
			apply_only_shift(fdf, a);
			i++;
		}
	}
}

void	do_calculations1(t_fdf *fdf)
{
	int		i;
	t_point	*a;

	i = 0;
	while (i < fdf->total)
	{
		a = &(fdf->tab[i]);
		apply_altitude(fdf, a);
		apply_zoom(fdf, a);
		i++;
	}
}

void	do_calculations2(t_fdf *fdf)
{
	int			i;
	t_point		*a;
	t_rot_data	r;

	i = 0;
	set_rot_data(fdf, &r);
	get_edge_coord(fdf);
	while (i < fdf->total)
	{
		a = &(fdf->tab[i]);
		apply_rotation(fdf, a, &r);
		apply_proj(fdf, a);
		apply_shift(fdf, a);
		i++;
	}
}
