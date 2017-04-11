/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:50:05 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/02 16:50:06 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		choice(const char **format, va_list *args)
{
	char *flag;
	int len;

	flag = flag_flag(format);
	ft_putstr("flags = ");
	ft_putstr(flag);
	ft_putchar('\n');
	len = flag_conv(format, args, flag, flag_minw(format), flag_pre(format));
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	char **ad;
	int len;

	len = 0;
	va_start (args, format);
	while (*format)
	{
		ad = (char **)(&format);
		if (*format == '%')
		{
			*ad += 1;
			len = choice((const char **)ad, &args);
		}
		else
		{
			ft_putchar(*(format++));
			len++;
		}
	}
	va_end(args);
	return (len);
}
