/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:11:24 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/11/27 14:08:09 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandelbrot(t_info *info)
{
	int				x;
	int				y;
	const double	pixel_width = (info->end_re - info->start_re) / WIDTH;
	const double	pixel_height = (info->end_im - info->start_im) / HEIGHT;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->c_re = info->start_re + x * pixel_width;
			info->c_im = info->start_im + y * pixel_height;
			info->z_re = 0;
			info->z_im = 0;
			my_mlx_pixel_put(&info->img, x, y, calc(info));
			x++;
		}
		y++;
	}
	return (0);
}
