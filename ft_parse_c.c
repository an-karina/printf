/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:02:24 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/04 21:37:20 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_c(char **format, va_list arguments, t_buffer *buf)
{
	char c;
	int	am_zero;
	int am_space;
	
	if (**format == '%')
	{
		buf->zero = (buf->minus == 1) ? 0 : buf->zero;
		c = '%';
	}
	else 
		c = va_arg(arguments, int);
	am_zero = 0;
	am_space = 0;
	if (buf->zero && !buf->minus && (buf->width > 0))
		am_zero = --buf->width;
	if (!buf->zero && (buf->width > 0))
		am_space = --buf->width;
	buf->length += am_zero + am_space + 1;
	if (buf->minus)
	{
		write(1, &c, 1);
		while (am_space--)
			write(1, " ", 1);
	}
	else
	{
		while (am_space--)
			write(1, " ", 1);
		while (am_zero--)
			write(1, "0", 1);
		write(1, &c, 1);
	}
}