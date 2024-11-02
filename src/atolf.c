/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atolf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:19:00 by tle-dref          #+#    #+#             */
/*   Updated: 2024/11/02 03:57:53 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_parse_decimal(const char *str, int *i)
{
	double	result;
	double	fraction;

	result = 0.0;
	fraction = 0.1;
	while (ft_isdigit(str[*i]))
	{
		result += (str[*i] - '0') * fraction;
		fraction *= 0.1;
		(*i)++;
	}
	return (result);
}

static double	ft_parse_number(const char *str, int *i)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		result += ft_parse_decimal(str, i);
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_parse_number(str, &i);
	return (result * sign);
}
