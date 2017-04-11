#include "ft_printf.h"

int		flag_conv(const char **fmt, va_list *args, char *flag, int minw, int pre)
{
	char *lm;

	lm = ft_strdup("");
	if (ft_islm(**fmt))
		flag_lm(fmt, &lm, **fmt);
	else
		lm = NULL;
	if (ft_isconv(**fmt))
	{
		flag = ft_chrjoin_free(flag, **fmt, 1);
		(*fmt)++;
		return (convert(args, flag, minw, pre, lm));
	}
	else if (**fmt == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else
		return (-1);
	// if (**fmt == 'd' || **fmt == 'i')
	// 	ft_putnbr(va_arg(*args, int));
	// else if (**fmt == 'D')
	// 	ft_putlnbr(va_arg(*args, long long int));
	// else if (**fmt == 's')
	// 	ft_putnstr(va_arg(*args, char *), pre);
	// else if (**fmt == 'S')
	// 	ft_putlstr(va_arg(*args, wchar_t *));
	// else if (**fmt == 'c')
	// 	ft_putchar(va_arg(*args, int));
	// else if (**fmt == 'C')
	// 	ft_putlchar(va_arg(*args, wchar_t));
	// else if (**fmt == 'e' || **fmt == 'E')
	// 	ft_putstr(ft_dec_to_sci(va_arg(*args, double), **fmt, ft_itoa(pre)));
	// else if (**fmt == 'o')
	// 	ft_putstr(ft_dec_to_base(va_arg(*args, unsigned int), 8));
	// else if (**fmt == 'O')
	// 	ft_putstr(ft_ldec_to_base(va_arg(*args, long long int), 8));
	// else if (**fmt == 'x' || **fmt == 'X')
	// 	ft_putstr(ft_dec_to_hex(va_arg(*args, unsigned int), **fmt));
	// else if (**fmt == 'p')
	// 	ft_putstr(ft_ptr_to_hex(va_arg(*args, void *)));
	// (*fmt)++;
	// return (1);
}

int		flag_minw(const char **format)
{
	int ret;

	ret = 0;
	if (!ft_isdigit(**format))
		return (0);
	else
	{
		ret = ft_atoi(*format);
		*format += ft_strlen(ft_itoa(ret));
		return (ret);
	}
}

int		flag_pre(const char **format)
{
	int pre;

	if (**format != '.')
		return (-1);
	else
	{
		(*format)++;
		pre = 0;
		if (ft_isdigit(**format))
		{
			pre = ft_atoi(*format);
			if (pre <= 0)
				pre = 0;
			*format += (ft_isalpha(**format) ? 0 : ft_strlen(ft_itoa(pre)));
		}
		else
			return(0);
	}
	return (pre);
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

char 	*flag_flag(const char **format)
{
	char *ret;

	ret = ft_strdup("");
	while (ft_isflag(*format))
	{
		if (ft_strchr(ret, **format))
			(*format)++;
		else
		{
			ret = ft_chrjoin_free(ret, **format, 1);
			(*format)++;
		}
	}
	return (ret);
}
