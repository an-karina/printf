/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:22:16 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/06 17:33:44 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arguments;
	char		*str;
	t_buffer	buf;

	str = (char *)format;
	va_start(arguments, format);
	buf.length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_initialize(&buf);
			str++;
			ft_parsing(&str, arguments, &buf);
		}
		else
		{
			write(1, str, 1);
			str++;
			buf.length++;
		}
	}
	va_end(arguments);
	return (buf.length);
}
