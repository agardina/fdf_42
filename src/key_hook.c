/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:48:02 by agardina          #+#    #+#             */
/*   Updated: 2020/01/28 11:57:14 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *param)
{
	if (keycode == 53)
		free_fdf((t_fdf*)param, 1);
	else if (keycode == 13 || keycode == 1)
		change_altitude((t_fdf*)param, keycode);
	else if (keycode == 24 || keycode == 27)
		change_zoom((t_fdf*)param, keycode);
	else if (keycode == 123 || keycode == 124 || keycode == 125
			|| keycode == 126)
		change_shift((t_fdf*)param, keycode);
	else if (keycode == 6)
		reset_fdf((t_fdf*)param, ((t_fdf*)param)->proj);
	else if (keycode == 7)
		change_proj((t_fdf*)param);
	else if (keycode == 19 && ++(((t_fdf*)param)->color_code))
		change_color((t_fdf*)param);
	else if (keycode == 18)
		((t_fdf*)param)->display_menu =
			((t_fdf*)param)->display_menu == 1 ? 0 : 1;
	else if (20 <= keycode && keycode <= 29 && keycode != 27 && keycode != 24)
		change_rotation((t_fdf*)param, keycode);
	else if (keycode == 8)
		center((t_fdf*)param);
	ft_display((t_fdf*)param);
	return (1);
}
