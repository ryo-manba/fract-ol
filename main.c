/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:23:11 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/07/01 10:08:02 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_info(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "Fractol");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->mlx || !info->win || !info->img.img)
		exit(1);
	info->img.addr = mlx_get_data_addr(info->img.img,
			&info->img.bpp, &info->img.line_len, &info->img.endian);
	info->max_iter = 30;
	info->start_im = -2;
	info->start_re = -2;
	info->end_im = 2;
	info->end_re = 2;
	info->c_re = -0.8;
	info->c_im = 0.156;
	info->mouse_re = 0;
	info->mouse_im = 0;
	info->z_re = 0;
	info->z_im = 0;
	info->rgb.r = 220;
	info->rgb.g = 220;
	info->rgb.b = 220;
	info->space_pressed = false;
	info->shift_pressed = false;
	info->control_pressed = false;
}

static bool	select_fractal(char *s, t_info *info)
{
	if (ft_strcmp("mandelbrot", s) == 0)
		info->type = MANDEL;
	else if (ft_strcmp("julia", s) == 0)
		info->type = JULIA;
	else if (ft_strcmp("burningship", s) == 0)
		info->type = SHIP;
	else if (ft_strcmp("tricorn", s) == 0)
		info->type = TRICORN;
	else
		return (false);
	return (true);
}

static int	exit_window(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

static void	print_help_message(void)
{
	printf(""
		"-----------------------help------------------------\n"
		"|[esc]          -  close the window               |\n"
		"|[r g b]        -  the color changes              |\n"
		"|[i]            -  increment max iteration        |\n"
		"|[d]            -  decrement max iteration        |\n"
		"|[space]        -  change the color automatically |\n"
		"|[scroll]       -  zoom                           |\n"
		"|[control]      -  julia set moves automatically  |\n"
		"|[mouse click]  -  reset the color and zoom       |\n"
		"|Hold down the [shift] and move the mouse         |\n"
		"|               -  julia set moves                |\n"
		"---------------------------------------------------\n");
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2 || !select_fractal(argv[1], &info))
	{
		printf("Usage: ./fractol [name] or make plot[number]\n\n"
			"Please choose one from\n"
			"1. mandelbrot\n"
			"2. julia\n"
			"3. burningship\n"
			"4. tricorn\n");
		return (1);
	}
	init_info(&info);
	print_help_message();
	mlx_hook(info.win, KeyPress, KeyPressMask, &key_press, &info);
	mlx_hook(info.win, KeyRelease, KeyReleaseMask, &key_release, &info);
	mlx_hook(info.win, 17, 1L << 17, &exit_window, &info);
	mlx_mouse_hook(info.win, &mouse_press, &info);
	mlx_loop_hook(info.mlx, &calc_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}
