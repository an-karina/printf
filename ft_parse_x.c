/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:30:10 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/06 17:31:16 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_minus_write(char *s, int space, int zero, int len)
{
	while (zero--)
		write(1, "0", 1);
	write(1, s, len);
	while (space--)
		write(1, " ", 1);
}

static void		ft_write(char *s, int space, int zero, int len)
{
	while (space--)
		write(1, " ", 1);
	while (zero--)
		write(1, "0", 1);
	write(1, s, len);
}

void			ft_parse_x(char **format, va_list arguments, t_buffer *buf)
{
	long	num;
	int		len;
	int		am_zero;
	int		am_space;
	char	*s;

	num = (unsigned long)va_arg(arguments, unsigned int);
	s = ft_itoa_base(**format, num, 16);
	len = ft_strlen(s);
	am_zero = 0;
	am_space = 0;
	if (buf->precision == 0 && (num == 0))
		len = 0;
	if ((buf->precision >= 0) && (buf->precision > len))
		am_zero = buf->precision - len;
	if ((buf->width > 0) && (buf->precision < 0)
		&& buf->zero && (buf->width > len))
		am_zero = buf->width - len;
	if ((buf->width > 0) && (buf->width > len) && (buf->precision < buf->width))
		am_space = buf->width - len - am_zero;
	buf->length += am_zero + am_space + len;
	if (buf->minus)
		ft_minus_write(s, am_space, am_zero, len);
	else
		ft_minus_write(s, am_space, am_zero, len);
}
