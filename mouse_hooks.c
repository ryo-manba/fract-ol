/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:01:47 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/12/24 15:51:28 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_info *info, int code)
{
	if (code == SCROLL_UP)
	{
		info->start_re = info->mouse_re
			+((info->start_re - info->mouse_re) * 0.9);
		info->start_im = info->mouse_im
			+ ((info->start_im - info->mouse_im) * 0.9);
		info->end_re = info->mouse_re
			+ ((info->end_re - info->mouse_re) * 0.9);
		info->end_im = info->mouse_im
			+ ((info->end_im - info->mouse_im) * 0.9);
	}
	if (code == SCROLL_DOWN)
	{
		info->start_re = info->mouse_re
			+ ((info->start_re - info->mouse_re) * 1.1);
		info->start_im = info->mouse_im
			+ ((info->start_im - info->mouse_im) * 1.1);
		info->end_re = info->mouse_re
			+ ((info->end_re - info->mouse_re) * 1.1);
		info->end_im = info->mouse_im
			+ ((info->end_im - info->mouse_im) * 1.1);
	}
}

int	mouse_press(int code, int x, int y, t_info *info)
{
	info->mouse_re = (((double)x / WIDTH)
			* (info->end_re - info->start_re)) + info->start_re;
	info->mouse_im = (((double)y / HEIGHT)
			* (info->end_im - info->start_im)) + info->start_im;
	if (code == MOUSE_CLICK)
	{
		info->start_re = -2.0;
		info->start_im = -2.0;
		info->end_re = 2.0;
		info->end_im = 2.0;
		info->rgb.r = 220;
		info->rgb.g = 220;
		info->rgb.b = 220;
	}
	if (code == SCROLL_UP || code == SCROLL_DOWN)
		zoom(info, code);
	return (0);
}
