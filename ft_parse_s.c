/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:27:53 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/04 21:45:49 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_s(char **format, va_list arguments, t_buffer *buf)
{
	char *str;
	int	str_len;
	int	am_zero;
	int am_space;
	int am_symb;
	
	str = va_arg(arguments, char *);
	if (str)
		str_len = ft_strlen(str);
	else
		str_len = 0;
		
	am_zero = 0;
	am_space = 0;
	if ((buf->precision >= 0) && (buf->precision < str_len))
		str_len = buf->precision;
	if ((buf->width > 0) && (buf->zero) && !(buf->minus))
		am_zero = buf->width - str_len;
	if ((buf->width > 0) && !(buf->zero) && (buf->width > str_len))
		am_space = buf->width - str_len;
	buf->length += str_len + am_space + am_zero;
	if (buf->minus)
	{
		if (!str)
		{
			write(1, "(null)", 6);
			buf->length += 6;
			am_space -= 6;
		}
		while (str_len--)
			write(1, str++, 1);
		while (am_space--)
			write(1, " ", 1);
	}
	else
	{
		if (!str)
			am_space -= 6;
		while (am_space--)
			write(1, " ", 1);
		while (am_zero--)
			write(1, "0", 1);
		if (!str)
		{
			write(1, "(null)", 6);
			buf->length += 6;
		}
		while (str_len--)
			write(1, str++, 1);
	}
}
