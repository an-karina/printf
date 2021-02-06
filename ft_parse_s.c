/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:27:53 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/06 17:13:16 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_write_null_str(int precision, char *str, int str_len)
{
	if (!str && (precision != 0))
		write(1, "(null)", str_len);
	while ((str_len)--)
		write(1, str++, 1);
}

static void		ft_init_var(t_buffer *buf, int *zero, int *space, int *str_len)
{
	*zero = 0;
	*space = 0;
	buf->zero = (buf->minus == 1) ? 0 : buf->zero;
	if ((buf->precision >= 0) && (buf->precision <= *str_len))
		*str_len = buf->precision;
	if ((buf->width > 0) && (buf->zero) && (buf->width > *str_len))
		*zero = buf->width - *str_len;
	if ((buf->width > 0) && !(buf->zero) && (buf->width > *str_len))
		*space = buf->width - *str_len;
	buf->length += *str_len + *space + *zero;
}

void			ft_parse_s(char **format, va_list arguments, t_buffer *buf)
{
	char	*str;
	int		str_len;
	int		am_zero;
	int		am_space;

	str = va_arg(arguments, char *);
	str_len = (!str) ? (6) : (ft_strlen(str));
	ft_init_var(buf, &am_zero, &am_space, &str_len);
	if (buf->minus)
	{
		ft_write_null_str(buf->precision, str, str_len);
		while (am_space--)
			write(1, " ", 1);
	}
	else
	{
		while (am_space--)
			write(1, " ", 1);
		while (am_zero--)
			write(1, "0", 1);
		ft_write_null_str(buf->precision, str, str_len);
	}
}
