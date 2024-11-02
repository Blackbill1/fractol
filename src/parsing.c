/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 04:07:56 by tle-dref          #+#    #+#             */
/*   Updated: 2024/11/02 04:08:24 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	ft_printf("! ARGUMENTS INVALIDES !\n");
	ft_printf("Les arguments valides sont :\n");
	ft_printf("j 'a' 'b' pour Julia\n");
	ft_printf("m pour mandelbrot \n");
	ft_printf("b pour burningship \n");
}

int	parsing(char **av, t_mlx *data)
{
	if (av[1][0] == 'm')
	{
		data->fract.wichfract = 0;
		return (1);
	}
	else if (av[1][0] == 'j')
	{
		if (!av[2] || !av[3])
			return (0);
		data->fract.wichfract = 1;
		data->fract.a = ft_atof(av[2]);
		data->fract.b = ft_atof(av[3]);
		return (1);
	}
	else if (av[1][0] == 'b')
	{
		data->fract.wichfract = 2;
		return (1);
	}
	return (0);
}
