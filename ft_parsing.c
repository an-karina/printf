/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:22:09 by jhleena           #+#    #+#             */
/*   Updated: 2021/01/30 15:45:28 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_offset(char *string)
{
	int count;
	
	count = 0;
	while (*string >= '0' && *string <= '9')
	{
		count++;
		string++;
	}
	return (count);
}

static int		ft_flag(char **format, t_buffer *buf)
{
	if (**format == '0' || **format == '-')
	{
		if (**format == '-')
			buf->minus = 1;
		buf->zero = 1;
		(*format)++;
		return (1);
	}
	return (0);
}

static int		ft_width(char **format, va_list arguments, t_buffer *buf)
{
	if (**format <= '9' && **format > '0')
	{
		buf->width = ft_atoi(*format);
		(*format)+=ft_offset(*format);
		return (1);
	}
	if (**format == '*')
	{
		buf->width = va_arg(arguments, int);
		if (buf->width < 0)
		{
			buf->minus = 1;
			buf->width *= -1;
		}
		(*format)++;
		return (1);
	}
	return (0);
}

static int		ft_precision(char **format, va_list arguments, t_buffer *buf)
{
	if (**format == '.')
	{
		buf->precision = 0;
		(*format)++;
		if (**format == '*')
		{
			buf->precision = va_arg(arguments, int);
			(*format)++;
		}
		if (**format <= '9' && **format >= '0')
		{
			buf->precision = ft_atoi(*format);
			(*format)+=ft_offset(*format);
		}
	}
	return (0);
}

void		ft_parsing(char **format, va_list arguments, t_buffer *buf)
{
	while (**format)
	{
		if (ft_flag(format, buf))
			continue ;
		if (ft_width(format, arguments, buf))
			continue ;
		if (ft_precision(format, arguments, buf))
			continue ;
		if (ft_strchr(TYPE, **format))
		{
			buf->type = **format;
			ft_parse_type(format, arguments, buf);
			break;
		}
		(*format)++;
	}
}