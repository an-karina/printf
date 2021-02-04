/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:22:03 by jhleena           #+#    #+#             */
/*   Updated: 2021/02/04 16:45:36 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TYPE "cspdiuxX"

typedef struct	s_information
{
	int			zero;
	int			minus;
	long long	width;
	long long	precision;
	char		type;
	int 		length;
}				t_buffer;

int		ft_printf(const char *format, ...);
void	ft_initialize(t_buffer *buffer);
void	ft_parsing(char **format, va_list arguments, t_buffer *buf);
void	ft_parse_type(char **format, va_list arguments, t_buffer *buf);
int		ft_num_len(long num);
void	ft_putnbr_fd(long n, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_parse_d_u(char **format, va_list arguments, t_buffer *buf);
void	ft_parse_c(char **format, va_list arguments, t_buffer *buf);
void	ft_parse_s(char **format, va_list arguments, t_buffer *buf);
void	ft_parse_p(char **format, va_list arguments, t_buffer *buf);
void	ft_parse_x_X(char **format, va_list arguments, t_buffer *buf);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa_base(char c, unsigned long long n, int base);

#endif
