/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:14:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/03 15:19:27 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		num_len(unsigned long long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(char c, unsigned long long n, int base)
{
	int		len;
	char	*p;
	char	*ost;

	len = num_len((unsigned long long)n, base);
	p = (char *)malloc(sizeof(char) * (len + 1));
	ost = (c == 'x' || c == 'p') ? "0123456789abcdef" : "0123456789ABCDEF";
	if (p)
	{
		p[len] = '\0';
		while (len > 0)
		{
			p[len - 1] = ost[(n % base)];
			n = n / base;
			len--;
		}
	}
	return (p);
}