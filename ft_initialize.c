/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 03:35:25 by jhleena           #+#    #+#             */
/*   Updated: 2021/01/27 17:26:26 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize(t_buffer *buffer)
{
	buffer->zero = 0;
	buffer->minus = 0;
	buffer->width = -1;
	buffer->precision = -1;
	buffer->type = '\0';
	printf("ft_initialize\n");
}
