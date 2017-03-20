#include "ft_printf.h"

void	flag_conv(const char *fmt, va_list *args, char *flag, int minw, int pre)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(*args, int));
	// else if (*format == 'D')
	// 	ft_putlnbr(va_arg(*args, long long int));
	else if (*format == 's')
		ft_putnstr(va_arg(*args, char *), presc);
	else if (*format == 'S')
		ft_putlstr(va_arg(*args, wchar_t *));
	else if (*format == 'c')
		ft_putchar(va_arg(*args, int));
	else if (*format == 'C')
		ft_putlchar(va_arg(*args, wchar_t));
	else if (*format == 'e' || *format == 'E')
		ft_putstr(ft_dec_to_sci(va_arg(*args, double), *format, ft_itoa(presc)));
	else if (*format == 'o')
		ft_putstr(ft_dec_to_base(va_arg(*args, unsigned int), 8));
	// else if (*format == 'O')
	// 	ft_putstr(ft_ldec_to_base(va_arg(*args, long long int), 8));
	else if (*format == 'x' || *format == 'X')
		ft_putstr(ft_dec_to_hex(va_arg(*args, unsigned int), *format));
	// else if (*format == 'p')
	// 	ft_putstr(ft_ptr_to_hex(va_arg(*args, void *)));
}

char	*flag_presc(const char *format, va_list *args, char flag)
{
	int presc;

	presc = 0;
	if (ft_isalnum(*format))
	{
		presc = ft_atoi(format);
		if (presc <= 0)
			presc = 0;
		format += (ft_isalpha(*format) ? 0 : ft_strlen(ft_itoa(presc)));
	}
	if (ft_isalpha(*format))
		flag_conv(format++, args, flag, presc);
	return ((char *)format);
}

// char	*flag_minw(const char *format, va_list *args)
// {
// 	int minw;

// 	minw = ft_itoa(*format);

// }

char 	*flag_flag(const char **format)
{
	char *ret;

	ret = ft_strdup("");
	while (ft_isflag(*format))
	{
		if (ft_strchr(ret, **format))
			*(format)++;
		else
			ret = ft_chrjoin_free(ret, **(*(format++)), 1);
	}
	return (ret);
}

int		ft_isflag(const char *format)
{
	int ret;

	ret = 0;
	ret += (*format == '#' ? 1 : 0);
	ret += (*format == '-' ? 1 : 0);
	ret += (*format == '+' ? 1 : 0);
	ret += (*format == ' ' ? 1 : 0);
	ret += (*format == '0' ? 1 : 0);
	return (ret);
}


























