/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:47:43 by agardina          #+#    #+#             */
/*   Updated: 2020/01/29 11:26:34 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_and_put_error(char **line, char ***stock, t_fdf *fdf, int ret)
{
	free_check_var(line, stock);
	if (ret == -1 || !fdf->nbline)
		write(1, "No data found.\n", 15);
	return (ret);
}

int	free_check_var(char **line, char ***stock)
{
	int i;

	ft_strdel(line);
	i = 0;
	if (*stock)
	{
		while ((*stock)[i])
		{
			ft_strdel(&(*stock)[i]);
			i++;
		}
		ft_strdel(&(*stock)[i]);
		free(*stock);
		*stock = NULL;
	}
	return (1);
}

int	free_fdf(t_fdf *fdf, char do_exit)
{
	free(fdf->tab);
	fdf->tab = NULL;
	if (fdf->mlx.mlx_ptr && fdf->mlx.img_ptr)
		mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->mlx.img_ptr);
	fdf->mlx.img_ptr = NULL;
	fdf->mlx.img_data = NULL;
	if (fdf->mlx.mlx_ptr && fdf->mlx.win_ptr)
		mlx_destroy_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	fdf->mlx.mlx_ptr = NULL;
	fdf->mlx.win_ptr = NULL;
	if (do_exit == 1)
		exit(0);
	return (1);
}
