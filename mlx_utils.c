/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:19:09 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/11/27 11:35:53 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	move_julia(t_info *info)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(info->mlx, info->win, &x, &y);
	if (!x && !y)
		return ;
	info->mouse_im = (((double)x / WIDTH)
			* (info->end_re - info->start_re)) + info->start_re;
	info->mouse_re = ((1 - (double)y / HEIGHT)
			* (info->end_im - info->start_im)) + info->start_im;
	info->c_im = info->mouse_im * 0.5;
	info->c_re = info->mouse_re * 0.5;
}

static void	changing_color_loop(t_info *info)
{
	if (info->rgb.r < 255)
		info->rgb.r += 2;
	if (info->rgb.r >= 255)
		info->rgb.g += 2;
	if (info->rgb.g >= 255)
		info->rgb.b += 2;
	if (info->rgb.b >= 255)
	{
		info->rgb.r = 0;
		info->rgb.g = 0;
		info->rgb.b = 0;
	}
}

static void	auto_moving_julia(t_info *info, double *angle)
{
	*angle += 0.03;
	info->c_im = cos(*angle * 3.213);
	info->c_re = sin(*angle);
}

int	calc_loop(t_info *info)
{
	static double	angle = 0;

	if (info->control_pressed)
		auto_moving_julia(info, &angle);
	if (info->space_pressed)
		changing_color_loop(info);
	if (info->type == JULIA && info->shift_pressed)
		move_julia(info);
	calc_fractal(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}
