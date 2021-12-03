/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:10:14 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/30 22:59:33 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static long long	calc_rgb(int r, int g, int b)
{
	long long	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

static int	get_color(t_info *info, int i)
{
	if (i == info->max_iter)
		return (BLACK);
	{
		if (i % 2 == 0)
			return (calc_rgb(info->rgb.r, info->rgb.g, info->rgb.b));
		if (i % 3 == 0)
			return (calc_rgb(info->rgb.r * 2, info->rgb.g * 2,
					info->rgb.b * 2));
		if (i % 5 == 0)
			return (calc_rgb(info->rgb.r * 3, info->rgb.g * 3,
					info->rgb.b * 3));
		if (i % 7 == 0)
			return (calc_rgb(info->rgb.r * 4, info->rgb.g * 4,
					info->rgb.b * 4));
		return (calc_rgb(info->rgb.r * 5, info->rgb.g * 5, info->rgb.b * 5));
	}
}

void	calc_fractal(t_info *info)
{
	if (info->type == JULIA)
		calc_julia(info);
	else
		calc_mandelbrot(info);
}

int	calc(t_info *info)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < info->max_iter && pow(info->z_re, 2) + pow(info->z_im, 2) <= 4)
	{
		tmp = pow(info->z_re, 2) - pow(info->z_im, 2) + info->c_re;
		if (info->type == SHIP)
			info->z_im = fabs(2 * info->z_re * info->z_im) + info->c_im;
		else if (info->type == TRICORN)
			info->z_im = -2 * info->z_re * info->z_im + info->c_im;
		else
			info->z_im = 2 * info->z_re * info->z_im + info->c_im;
		info->z_re = tmp;
		i++;
	}
	return (get_color(info, i));
}
