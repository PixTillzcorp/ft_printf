#include "ft_printf.h"

int		flag_conv(const char **fmt, va_list *args, char *flag, int minw, int pre)
{
	char *lm;
	char *ret;

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
		ret = add_flag(ft_strdup("%"), minw, flag, '%');
		ft_putstr(ret);
		(*fmt)++;
		return (ft_strlen(ret));
	}
	else
		return (0);
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
