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

int		choice(const char *format, va_list *args)
{
	char *flag;
	int len;

	flag = flag_flag(&format);
	len = flag_conv(&format, args, flag_flag(&format), flag_minw(&format), flag_pre(&format));
	if (ft_isalpha(*format))
		len = flag_conv(&format, args, flag, 0, 0);
	else if (ft_isnum(*format))
	{
		minw = ft_atoi(format);
		format += ft_strlen(ft_itoa(minw));
	}
	else if (*format == '.')
		 = flag_pre(format + 1);
	else if (*format == '%')
	{
		ft_putchar('%');
		format++;
	}
	free(flag);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list args;

	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
			format = choice(++format, &args);
		else
			ft_putchar(*(format++));
	}
	va_end(args);
	return (ft_strlen(format));
}
