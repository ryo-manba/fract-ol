/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:10:47 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/11/27 14:04:22 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(t_info *info)
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
			info->z_re = info->start_re + x * pixel_width;
			info->z_im = info->start_im + y * pixel_height;
			my_mlx_pixel_put(&info->img, x, y, calc(info));
			x++;
		}
		y++;
	}
	return (0);
}
