/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:23:47 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/12/24 15:34:47 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

/* window size */
# define WIDTH 500
# define HEIGHT 500

/* keycode */
# if __APPLE__
#  define KEY_SPACE 32
#  define KEY_B 98
#  define KEY_D 100
#  define KEY_G 103
#  define KEY_I 105
#  define KEY_R 114
#  define KEY_ESC 65307
#  define KEY_LEFT 65361
#  define KEY_UP 65362
#  define KEY_RIGHT 65363
#  define KEY_DOWN 65364
#  define KEY_SHIFT 65505
#  define KEY_CONTROL 65507
#  define MOUSE_CLICK 2
# else
#  define KEY_D 2
#  define KEY_G 5
#  define KEY_B 11
#  define KEY_R 15
#  define KEY_I 34
#  define KEY_ESC 53
#  define KEY_SPACE 49
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_UP 126
#  define KEY_CONTROL 256
#  define KEY_SHIFT 257
#  define MOUSE_CLICK 3
# endif

/* mousecode */
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* colorcode */
# define BLACK 0x000000
# define WHITE 0xffffff

typedef enum e_fractal_type {
	MANDEL,
	JULIA,
	SHIP,
	TRICORN,
}	t_fractal_type;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_info {
	int		max_iter;
	int		type;
	int		upper_limit;
	void	*mlx;
	void	*win;
	double	start_im;
	double	start_re;
	double	end_im;
	double	end_re;
	double	c_im;
	double	c_re;
	double	z_im;
	double	z_re;
	double	mouse_re;
	double	mouse_im;
	bool	shift_pressed;
	bool	space_pressed;
	bool	control_pressed;
	t_img	img;
	t_rgb	rgb;
}	t_info;

/* hooks */
int		key_press(int code, t_info *info);
int		key_release(int code, t_info *info);
int		mouse_press(int code, int x, int y, t_info *info);
void	move_fractal(int code, t_info *info);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_info(t_info *info);

/* fractal */
int		calc(t_info *info);
int		calc_loop(t_info *info);
int		calc_julia(t_info *info);
int		calc_mandelbrot(t_info *info);
void	calc_fractal(t_info *info);
#endif
