/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:47:52 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:03:31 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_gradient(t_gradient grad, t_point current, char axe)
{
	float	percent;
	int		red;
	int		green;
	int		blue;

	if (axe == 1)
		percent = get_percentage(grad.start.x2, grad.finish.x2, current.x2);
	else if (axe == 2)
		percent = get_percentage(grad.start.y2, grad.finish.y2, current.y2);
	else
		percent = get_percentage(grad.start.z, grad.finish.z, current.z);
	red = get_gradient_mix((grad.start.color >> 16) & 0xFF,
			(grad.finish.color >> 16) & 0xFF, percent);
	green = get_gradient_mix((grad.start.color >> 8) & 0xFF,
			(grad.finish.color >> 8) & 0xFF, percent);
	blue = get_gradient_mix(grad.start.color & 0xFF,
			grad.finish.color & 0xFF, percent);
	return ((red << 16) + (green << 8) + blue);
}

float	get_percentage(int start, int finish, int current)
{
	float	distance;
	float	position;

	distance = (float)finish - (float)start;
	position = (float)current - (float)start;
	return (distance == 0.0 ? 1.0 : position / distance);
}

int		get_gradient_mix(int start, int finish, float percent)
{
	return ((int)(start * (1 - percent) + finish * percent));
}
