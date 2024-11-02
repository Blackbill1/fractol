/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 06:02:19 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/18 07:52:42 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(va_list args)
{
	static char		tab[17] = {"0123456789abcdef"};
	static char		buff[16] = {""};
	unsigned long	ptr;
	int				i;
	int				count;

	i = 0;
	count = 0;
	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	while (ptr > 0)
	{
		buff[i] = tab[ptr % 16];
		ptr /= 16;
		i++;
	}
	write(1, "0x", 2);
	while (i--)
	{
		write(1, &buff[i], 1);
		count++;
	}
	return (count + 2);
}

int	ft_upperprinthex(va_list args)
{
	static char		tab[17] = {"0123456789ABCDEF"};
	static char		buff[16] = {""};
	unsigned int	ptr;
	int				i;
	int				count;

	i = 0;
	count = 0;
	ptr = (unsigned int)va_arg(args, unsigned int);
	if (ptr == 0)
		return (write(1, "0", 1));
	while (ptr > 0)
	{
		buff[i] = tab[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i--)
	{
		write(1, &buff[i], 1);
		count++;
	}
	return (count);
}

int	ft_lowerprinthex(va_list args)
{
	static char		tab[17] = {"0123456789abcdef"};
	static char		buff[16] = {""};
	unsigned int	ptr;
	int				i;
	int				count;

	i = 0;
	count = 0;
	ptr = (unsigned int)va_arg(args, unsigned int);
	if (ptr == 0)
		return (write(1, "0", 1));
	while (ptr > 0)
	{
		buff[i] = tab[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i--)
	{
		write(1, &buff[i], 1);
		count++;
	}
	return (count);
}
