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

void	choice(char *format)
{
	if (ft_isalpha(*format))
		flag_conv(*format);
	else if (*format == ('#' || ' ' || '+' || '-' || '0'))
		flag_cara(*format);
	else if (*format == '.')
		flag_presc(*format)
	else if (*format == '%')
		ft_putchar('%');
}

int		ft_printf(const char *format, ...)
{
	va_list args;

	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			// if (*(format + 1) == '.')
			// {
			// 	if (*(format + 2) == '*')

			// }
			if (*(format + 1) == 'd' || *(format + 1) == 'i')
				ft_putnbr(va_arg(args, int));
			if (*(format + 1) == 'D')
				ft_putlnbr(va_arg(args, long long int));
			if (*(format + 1) == 's')
				ft_putstr(va_arg(args, char *));
			if (*(format + 1) == 'S')
				ft_putlstr(va_arg(args, wchar_t *));
			if (*(format + 1) == 'c')
				ft_putchar(va_arg(args, int));
			if (*(format + 1) == 'C')
				ft_putlchar(va_arg(args, wchar_t));
			if (*(format + 1) == 'e' || *(format + 1) == 'E')
				ft_putstr(ft_dec_to_sci(va_arg(args, double), *(format + 1), "6"));
			if (*(format + 1) == 'o')
				ft_putstr(ft_dec_to_base(va_arg(args, unsigned int), 8));
			if (*(format + 1) == 'O')
				ft_putstr(ft_ldec_to_base(va_arg(args, long long int), 8));
			if (*(format + 1) == 'x' || *(format + 1) == 'X')
				ft_putstr(ft_dec_to_hex(va_arg(args, unsigned int), *(format + 1)));
			if (*(format + 1) == 'p')
				ft_putstr(ft_ptr_to_hex(va_arg(args, void *)));
			if (*(format + 1) == '%')
				ft_putchar('%');
			format += 2;
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (ft_strlen(format));
}