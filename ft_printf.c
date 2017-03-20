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

char	*choice(const char *format, va_list *args)
{
	char *flag;

	flag = flag_flag(&format);
	if (ft_isalpha(*format))
		flag_conv(format++, args, 0);
	// else if (*format == ('#' || ' ' || '+' || '-' || '0'))
	// 	i += flag_cara(format, i);
	// else if (ft_isnum(*format))
	// 	format = flag_minw(format, args);
	else if (*format == '.')
		format = flag_presc(format + 1, args);
	else if (*format == '%')
	{
		ft_putchar('%');
		format++;
	}
	return ((char *)format);
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
