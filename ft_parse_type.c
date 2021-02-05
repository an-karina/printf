/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:50:27 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/05 18:21:00 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_type(char **format, va_list arguments, t_buffer *buf)
{
	if (buf->type == 'd' || buf->type == 'i' || buf->type == 'u')
	{
		ft_parse_d_u(format, arguments, buf);
		(*format)++;
	}
	else if (buf->type == 'c' || **format == '%')
	{
		ft_parse_c(format, arguments, buf);
		(*format)++;
	}
	else if (buf->type == 's')
	{
		ft_parse_s(format, arguments, buf);
		(*format)++;
	}
	else if (buf->type == 'p')
	{
		ft_parse_p(format, arguments, buf);
		(*format)++;
	}
	else if (buf->type == 'x' || buf->type == 'X')
	{
		ft_parse_x_X(format, arguments, buf);
		(*format)++;
	}
}
