/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:22:16 by jhleena           #+#    #+#             */
/*   Updated: 2021/01/25 16:33:27 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arguments;
	t_buffer	buf;
	const char	*format_begining;
	
	va_start(arguments, format);
	format_begining = format;
	while (*format)
	{
		printf("ft_printf.c\n");
		if (*format == '%')
		{
			ft_initialize(&buf);
			format++;
			ft_parsing(((char **)&(format)), arguments, &buf);
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(arguments);
}