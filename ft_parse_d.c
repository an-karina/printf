/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:21 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/06 15:16:14 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_write(int minus, char c, int am_space, int am_zero)
{
	
}

void	ft_parse_d_u(char **format, va_list arguments, t_buffer *buf)
{
	long	num;
	int		len_num;
	int		am_zero;
	int		am_space;
	
	am_zero = 0;
	am_space = 0;
	num = (**format == 'u') ? (unsigned long)va_arg(arguments, unsigned int)
		: (long)va_arg(arguments, int);
	len_num = (**format == 'u') ? (ft_num_len((unsigned long)num))
			: (ft_num_len((long)num));
	buf->zero = (buf->minus == 1) ? 0 : buf->zero;
	len_num = (buf->precision == 0 && (num == 0)) ? 0 : len_num;
	buf->width = (num < 0) ? (--buf->width) : buf->width;
	if ((buf->precision >= 0) && (buf->precision > len_num))
		am_zero = buf->precision - len_num;
	if ((buf->precision < 0) && buf->zero && (buf->width > len_num))
		am_zero = buf->width - len_num;
	if ((buf->width > 0) && (buf->width > len_num + am_zero))
		am_space = buf->width - len_num - am_zero;
	buf->length += (num < 0) ? (am_space + am_zero + len_num + 1) : (am_space + am_zero + len_num);
	if (buf->minus) 
	{
		if (num < 0)
		{
			num *= -1;
			write(1, "-", 1);
		}
		while (am_zero--)
			write(1, "0", 1);
		if (len_num)
			ft_putnbr_fd(num, 1);
		while (am_space--)
			write(1, " ", 1);
	}
	else
	{
		while (am_space--)
			write(1, " ", 1);
		if (num < 0)
		{
			num *= -1;
			write(1, "-", 1);
		}
		while (am_zero--)
			write(1, "0", 1);
		if (len_num)
			ft_putnbr_fd(num, 1);
	}
}
