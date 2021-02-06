/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:08:01 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/06 14:22:36 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_p(char **format, va_list arguments, t_buffer *buf)
{
	unsigned long long num;
	int str_len;
	int am_space;
	char *s;
	
	num = (unsigned long long)va_arg(arguments, void*);
	s = ft_itoa_base(**format, num, 16);
	str_len = ft_strlen(s) * (num != 0 || buf->precision != 0);
	am_space = 0;
	if (buf->width > 0 && (buf->width > str_len + 2))
		am_space = buf->width - str_len - 2;
	buf->length += am_space + 2 + str_len;
	if (buf->minus)
	{
		write(1, "0x", 2);
		write(1, s, str_len);
		while (am_space--)
			write(1, " ", 1);
	}
	else
	{
		while (am_space--)
			write(1, " ", 1);
		write(1, "0x", 2);
		write(1, s, str_len);
	}
}