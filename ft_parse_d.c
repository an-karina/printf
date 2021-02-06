/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:21 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/06 16:19:10 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_minus_write(long num, int space, int zero, int len)
{
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	while (zero--)
		write(1, "0", 1);
	if (len)
		ft_putnbr_fd(num, 1);
	while (space--)
		write(1, " ", 1);
}

static void		ft_write(long num, int space, int zero, int len)
{
	while (space--)
		write(1, " ", 1);
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	while (zero--)
		write(1, "0", 1);
	if (len)
		ft_putnbr_fd(num, 1);
}

void			ft_parse_d_u(char **format, va_list arguments, t_buffer *buf)
{
	long	num;
	int		len;
	int		zero;
	int		space;

	zero = 0;
	space = 0;
	num = (**format == 'u') ? (unsigned long)va_arg(arguments, unsigned int)
		: (long)va_arg(arguments, int);
	len = (**format == 'u') ? (ft_num_len((unsigned long)num))
			: (ft_num_len((long)num));
	buf->zero = (buf->minus == 1) ? 0 : buf->zero;
	len = (buf->precision == 0 && (num == 0)) ? 0 : len;
	buf->width = (num < 0) ? (--buf->width) : buf->width;
	if ((buf->precision >= 0) && (buf->precision > len))
		zero = buf->precision - len;
	if ((buf->precision < 0) && buf->zero && (buf->width > len))
		zero = buf->width - len;
	if ((buf->width > 0) && (buf->width > len + zero))
		space = buf->width - len - zero;
	buf->length += (num < 0) ? (space + zero + (++len)) : (space + zero + len);
	if (buf->minus)
		ft_minus_write((long)num, space, zero, len);
	else
		ft_write((long)num, space, zero, len);
}
