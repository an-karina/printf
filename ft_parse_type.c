/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:50:27 by jhleena           #+#    #+#             */
/*   Updated: 2021/01/30 15:35:46 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_type(char **format, va_list arguments, t_buffer *buf)
{
	if (buf->type == 'd' || buf->type == 'i')
	{
		ft_parse_d(format, arguments, buf);
		(*format)++;
	}
	//if (buf->type == )
}
