/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:46:45 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 12:04:36 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(int fd, t_fdf *fdf)
{
	char	*line;
	char	**stock;
	int		ret;

	line = NULL;
	stock = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		fdf->nbline++;
		if (!split_line(&line, &stock))
			return (free_and_put_error(&line, &stock, fdf, -1));
		if (!deal_nb_col(fdf, stock))
			return (free_and_put_error(&line, &stock, fdf, -1));
		fdf->total += fdf->nbcol;
		if (!add_to_tab(fdf, stock))
			return (free_and_put_error(&line, &stock, fdf, -1));
		free_check_var(&line, &stock);
	}
	return (free_and_put_error(&line, &stock, fdf, ret));
}

int	split_line(char **line, char ***stock)
{
	if (!(*stock = ft_split(*line, " ")))
		return (0);
	if (!((*stock)[0]))
		return (0);
	return (1);
}

int	add_to_tab(t_fdf *fdf, char **stock)
{
	t_point	*new;
	int		i;
	int		start;

	i = 0;
	start = fdf->nbcol * (fdf->nbline - 1);
	if (!(new = (t_point*)malloc(sizeof(t_point) * fdf->nbcol * fdf->nbline)))
		return (0);
	if (fdf->tab)
		ft_memcpy(new, fdf->tab, sizeof(t_point) * fdf->nbcol
				* (fdf->nbline - 1));
	i = 0;
	while (stock[i])
	{
		new[start + i].x = i;
		new[start + i].y = fdf->nbline - 1;
		new[start + i].z = ft_atoi(stock[i]);
		i++;
	}
	free(fdf->tab);
	fdf->tab = new;
	return (1);
}

int	deal_nb_col(t_fdf *fdf, char **stock)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (fdf->nbcol == -1)
	{
		while (stock[i])
		{
			res++;
			i++;
		}
		(fdf->nbcol) = res;
		return (1);
	}
	else
	{
		while (stock[i])
		{
			res++;
			i++;
		}
	}
	return ((res == fdf->nbcol));
}
