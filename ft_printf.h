/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:22:03 by jhleena           #+#    #+#             */
/*   Updated: 2021/01/27 17:25:54 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
#include <stdio.h>

#define TYPE "cspdiuxX"

typedef struct	s_information
{
	int			zero;
	int			minus;
	long long	width;
	long long	precision;
	char		type;
	
}				t_buffer;

int		ft_printf(const char *format, ...);
void	ft_initialize(t_buffer *buffer);
void	ft_parsing(char **format, va_list arguments, t_buffer *buf);
void	ft_parse_type(char **format, va_list arguments, t_buffer *buf);
int		ft_num_len(long num);
void	ft_putnbr_fd(int n, int fd);
void	ft_parse_d(char **format, va_list arguments, t_buffer *buf);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

#endif
