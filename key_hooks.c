/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:04:35 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/07/03 09:23:21 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_rgb(int code, t_info *info)
{
	if (code == KEY_R)
		info->rgb.r += 10;
	if (code == KEY_G)
		info->rgb.g += 10;
	if (code == KEY_B)
		info->rgb.b += 10;
	if (info->rgb.r >= 255)
		info->rgb.r = 0;
	if (info->rgb.g >= 255)
		info->rgb.g = 0;
	if (info->rgb.b >= 255)
		info->rgb.b = 0;
}

int	key_press(int code, t_info *info)
{
	if (code == KEY_ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	if (code == KEY_LEFT || code == KEY_RIGHT
		|| code == KEY_DOWN || code == KEY_UP)
		move_fractal(code, info);
	if (code == KEY_SHIFT)
		info->shift_pressed = true;
	if (code == KEY_SPACE)
		info->space_pressed = !info->space_pressed;
	if (code == KEY_CONTROL)
		info->control_pressed = !info->control_pressed;
	if (code == KEY_I)
		info->max_iter++;
	if (code == KEY_D)
		info->max_iter--;
	if (code == KEY_R || code == KEY_G || code == KEY_B)
		change_rgb(code, info);
	return (0);
}

int	key_release(int code, t_info *info)
{
	if (code == KEY_SHIFT)
		info->shift_pressed = false;
	return (0);
}

void	move_fractal(int code, t_info *info)
{
	if (code == KEY_RIGHT)
	{
		info->start_re += 0.05;
		info->end_re += 0.05;
	}
	if (code == KEY_LEFT)
	{
		info->start_re -= 0.05;
		info->end_re -= 0.05;
	}
	if (code == KEY_UP)
	{
		info->start_im -= 0.05;
		info->end_im -= 0.05;
	}
	if (code == KEY_DOWN)
	{
		info->start_im += 0.05;
		info->end_im += 0.05;
	}
}
