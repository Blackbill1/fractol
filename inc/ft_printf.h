/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:44:02 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/18 08:07:48 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_putchar(va_list args);
int		ft_putstr(va_list args);
int		ft_printhex(va_list args);
int		ft_upperprinthex(va_list args);
int		ft_lowerprinthex(va_list args);
int		ft_putnbr(int n);
int		ft_putnbr_scam(va_list args);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbru_scam(va_list args);
int		ft_percent(va_list args);
