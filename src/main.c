/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:00:08 by gbruscan          #+#    #+#             */
/*   Updated: 2024/11/02 04:28:01 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

int	data_init(t_mlx *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!data->mlx)
		return (1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		mlx_terminate(data->mlx);
		return (1);
	}
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		return (1);
	data->width = WIDTH;
	data->height = HEIGHT;
	data->ratio = (double)data->width / (double)data->height;
	data->ymax = 2.0;
	data->ymin = -2.0;
	data->xmax = 2.0 * data->ratio;
	data->xmin = -2.0 * data->ratio;
	return (0);
}

void	clean_data(t_mlx *data)
{
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	exit(0);
}

void	draw_image(void *param)
{
	t_mlx	*data;

	data = param;
	if (data->fract.wichfract == 0)
		draw_mandelbrot(0, 0, data);
	else if (data->fract.wichfract == 1)
		draw_julia(data->fract.a, data->fract.b, data);
	else if (data->fract.wichfract == 2)
		draw_burning_ship(0.4, 0.3, data);
}

int	main(int ac, char **av)
{
	static t_mlx	data = {};

	if (ac == 1)
		return (error(), 1);
	if (!parsing(av, &data))
		return (error(), 1);
	if (data_init(&data))
		return (1);
	mlx_resize_hook(data.mlx, resize_hook, &data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_scroll_hook(data.mlx, scroll_hook, &data);
	mlx_loop_hook(data.mlx, draw_image, &data);
	mlx_loop(data.mlx);
	clean_data(&data);
	return (0);
}
