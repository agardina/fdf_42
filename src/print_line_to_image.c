/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:48:24 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:06:46 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_line_img(t_mlx_data *data, t_point p1, t_point p2)
{
	int			dx;
	int			dy;
	t_gradient	grad;

	dx = ft_abs(p2.x2 - p1.x2);
	dy = ft_abs(p2.y2 - p1.y2);
	if (dx >= dy)
	{
		if (p1.x2 > p2.x2)
			swap_points(&p1, &p2);
		grad.start = p1;
		grad.finish = p2;
		print_line_img_case1(data, p1, p2, grad);
	}
	else
	{
		if (p1.y2 > p2.y2)
			swap_points(&p1, &p2);
		grad.start = p1;
		grad.finish = p2;
		print_line_img_case2(data, p1, p2, grad);
	}
	return (1);
}

int		print_line_img_case1(t_mlx_data *data, t_point p1, t_point p2,
		t_gradient grad)
{
	int	e;
	int	dx;
	int	dy;
	int	y_incr;

	dx = p2.x2 - p1.x2;
	dy = ft_abs(p2.y2 - p1.y2);
	y_incr = (p2.y2 >= p1.y2) ? 1 : -1;
	e = (2 * dy) + dx;
	while (p1.x2 <= p2.x2)
	{
		e -= (2 * dy);
		if (e <= 0)
		{
			p1.y2 += y_incr;
			e += (2 * dx);
		}
		if (0 <= p1.x2 && p1.x2 < WIN_WIDTH && 0 <= p1.y2 && p1.y2 < WIN_HEIGHT)
			fill_img_data(data, p1, get_gradient(grad, p1, 1));
		p1.x2++;
	}
	return (1);
}

int		print_line_img_case2(t_mlx_data *data, t_point p1, t_point p2,
		t_gradient grad)
{
	int	dx;
	int	dy;
	int	e;
	int	x_incr;

	x_incr = (p1.x2 <= p2.x2) ? 1 : -1;
	dx = ft_abs(p2.x2 - p1.x2);
	dy = p2.y2 - p1.y2;
	e = (2 * dx) + dy;
	while (p1.y2 <= p2.y2)
	{
		e -= (2 * dx);
		if (e <= 0)
		{
			p1.x2 += x_incr;
			e += (2 * dy);
		}
		if (0 <= p1.x2 && p1.x2 < WIN_WIDTH && 0 <= p1.y2 && p1.y2 < WIN_HEIGHT)
			fill_img_data(data, p1, get_gradient(grad, p1, 2));
		p1.y2++;
	}
	return (1);
}

void	fill_img_data(t_mlx_data *data, t_point p1, int color)
{
	(data->img_data)[p1.x2 * 4 + data->size_line * p1.y2] = color & 0xFF;
	(data->img_data)[p1.x2 * 4 + data->size_line * p1.y2 + 1] =
		(color >> 8) & 0xFF;
	(data->img_data)[p1.x2 * 4 + data->size_line * p1.y2 + 2] =
		(color >> 16) & 0xFF;
	(data->img_data)[p1.x2 * 4 + data->size_line * p1.y2 + 3] = 0;
}

void	swap_points(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp.x2 = a->x2;
	tmp.y2 = a->y2;
	tmp.z2 = a->z2;
	tmp.color = a->color;
	a->x2 = b->x2;
	a->y2 = b->y2;
	a->z2 = b->z2;
	a->color = b->color;
	b->x2 = tmp.x2;
	b->y2 = tmp.y2;
	b->z2 = tmp.z2;
	b->color = tmp.color;
}
