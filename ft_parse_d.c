/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:21 by jhleena           #+#    #+#             */
/*   Updated: 2021/01/30 16:11:16 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_d(char **format, va_list arguments, t_buffer *buf)
{
	int num;
	int len_num;
	int	am_zero;
	int am_space;
	
	num = va_arg(arguments, int);
	len_num =  ft_num_len((long)num);
	am_zero = 0;
	am_space = 0;
	if (num < 0)
		buf->width--;
	if ((buf->precision >= 0) && (buf->precision > len_num))
		am_zero = buf->precision - len_num;
	if ((buf->precision < 0) && !buf->minus && buf->zero)
		am_zero = buf->width - len_num;
	if ((buf->width > 0) && (buf->width > len_num) && (buf->precision < buf->width))
		am_space = buf->width - len_num - am_zero;
	// if ((buf->precision >= 0) && (buf->precision > len_num) && (buf->width != -1) && (am_space))
	// 	am_space = am_space - am_zero;
	if (buf->minus)
	{
		if (num < 0)
		{
			num *= -1;
			write(1, "-", 1);
			//am_space--;
		}
		while (am_zero--)
			write(1, "0", 1);
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
		ft_putnbr_fd(num, 1);

	}	
}
