/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:33:36 by agardina          #+#    #+#             */
/*   Updated: 2020/02/03 19:07:50 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIN_HEIGHT 650
# define WIN_WIDTH 1000
# define AQUA_MARINE 0x7FFFD4
# define BEIGE 0xF5F5DC
# define BLUE 0x0000CD
# define CORAL 0xFF7F50
# define DARK_GREEN 0x006400
# define GOLDEN_ROD 0xEDDA74
# define GREEN 0x9ACD32
# define MIDNIGHT_BLUE 0x151B54
# define ORANGE 0xFFA500
# define RED 0xFF2500
# define SADDLEBROWN 0x8B4513
# define GREEN_YELLOW 0xADFF2F
# define YELLOW 0xFFD700
# define WHITE 0xFFFFFF
# define WHITE_SMOKE 0xF5F5F5
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					x2;
	int					y2;
	int					z2;
	int					color;
}						t_point;

typedef struct			s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_mlx_data;

typedef struct			s_fdf
{
	t_mlx_data			mlx;
	int					nbcol;
	int					nbline;
	int					total;
	t_point				*tab;
	float				zoom;
	int					altitude;
	int					x_shift;
	int					y_shift;
	int					x_incr;
	int					y_incr;
	int					x_min;
	int					x_max;
	int					y_min;
	int					y_max;
	float				x_rotation;
	float				y_rotation;
	float				z_rotation;
	char				proj;
	int					color;
	int					color_code;
	int					alt_min;
	int					alt_max;
	int					magn;
	char				display_menu;
}						t_fdf;

typedef struct			s_gradient
{
	t_point				start;
	t_point				finish;
}						t_gradient;

typedef struct			s_rot_data
{
	float				a;
	float				b;
	float				c;
	float				d;
	float				e;
	float				f;
	float				ad;
	float				bd;
}						t_rot_data;

int						add_to_tab(t_fdf *fdf, char **stock);
void					apply_altitude(t_fdf *fdf, t_point *a);
void					apply_only_shift(t_fdf *fdf, t_point *a);
void					apply_proj(t_fdf *fdf, t_point *a);
void					apply_rotation(t_fdf *fdf, t_point *a, t_rot_data *r);
void					apply_shift(t_fdf *fdf, t_point *a);
void					apply_zoom(t_fdf *fdf, t_point *a);
void					cabinet(t_point *p);
void					calc_edge_coord(t_fdf *fdf, int index);
void					calculate_initial_zoom(t_fdf *fdf);
void					center(t_fdf *fdf);
void					change_altitude(t_fdf *fdf, int keycode);
void					change_proj(t_fdf *fdf);
void					change_shift(t_fdf *fdf, int keycode);
void					change_rotation(t_fdf *fdf, int keycode);
void					change_zoom(t_fdf *fdf, int keycode);
int						check_map(int fd, t_fdf *fdf);
int						deal_nb_col(t_fdf *fdf, char **stock);
void					display_menu(t_fdf *fdf);
void					do_calculations(t_fdf *fdf, char c);
void					do_calculations1(t_fdf *fdf);
void					do_calculations2(t_fdf *fdf);
void					draw_map(t_fdf *fdf);
void					draw_segment(t_fdf *fdf, t_point a, t_point b);
void					fill_img_data(t_mlx_data *data, t_point p1, int color);
int						free_and_put_error(char **line, char ***stock,
		t_fdf *fdf, int ret);
int						free_check_var(char **line, char ***stock);
int						free_fdf(t_fdf *fdf, char do_exit);
void					ft_display(t_fdf *fdf);
int						ft_fdf(int fd);
int						geo_mode_alt(int z, char a);
int						geo_mode_alt2(int z, char a);
int						geo_mode_color(int z);
int						geo_mode_color2(int z);
void					get_alt_max(t_fdf *fdf);
void					get_alt_min(t_fdf *fdf);
void					get_edge_coord(t_fdf *fdf);
int						get_gradient(t_gradient grad, t_point current,
		char axe);
int						get_gradient_mix(int start, int finish, float percent);
float					get_percentage(int start, int finish, int current);
void					get_point_on_the_right(t_fdf *fdf, int index, t_point a,
		t_point *b);
void					get_point_under(t_fdf *fdf, int index, t_point a,
		t_point *b);
void					init_fdf(t_fdf *fdf, char proj);
void					iso(t_point *p);
int						key_hook(int keycode, void *param);
int						print_line_img(t_mlx_data *data, t_point p1,
		t_point p2);
int						print_line_img_case1(t_mlx_data *data, t_point p1,
		t_point p2, t_gradient grad);
int						print_line_img_case2(t_mlx_data *data, t_point p1,
		t_point p2, t_gradient grad);
void					reset_fdf(t_fdf *fdf, char proj);
int						set_fdf_color(t_fdf *fdf);
void					set_point_color(t_fdf *fdf, t_point *a);
void					set_rot_data(t_fdf *fdf, t_rot_data *r);
void					change_color(t_fdf *fdf);
int						split_line(char **line, char ***stock);
void					swap_points(t_point *a, t_point *b);

#endif
