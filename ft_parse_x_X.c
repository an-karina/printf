/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:30:10 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/04 19:33:32 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_x_X(char **format, va_list arguments, t_buffer *buf)
{
	long num;
	int str_len;
	int	am_zero;
	int am_space;
	char *s;

	num = (unsigned long)va_arg(arguments, unsigned int);
	s = ft_itoa_base(**format, num, 16);
	str_len = ft_strlen(s);
	am_zero = 0;
	am_space = 0;
	if (buf->width < 0 && buf->precision == 0 && (num == 0))
		return ;
	if ((buf->precision >= 0) && (buf->precision > str_len))
		am_zero = buf->precision - str_len;
	if ((buf->width > 0) && (buf->precision < 0) && !buf->minus && buf->zero)
		am_zero = buf->width - str_len;
	if ((buf->width > 0) && (buf->width > str_len) && (buf->precision < buf->width))
		am_space = buf->width - str_len - am_zero;
	buf->length = am_zero + am_space + str_len;
	if (buf->minus)
	{
		while (am_zero--)
			write(1, "0", 1);
		write(1, s, str_len);
		while (am_space--)
			write(1, " ", 1);
	}
	else
	{		
		while (am_space--)
			write(1, " ", 1);
		while (am_zero--)
			write(1, "0", 1);
		write(1, s, str_len);
	}
}
