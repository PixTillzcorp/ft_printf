#include "ft_printf.h"

void	flag_lm(const char **fmt, char **ret, char flag)
{
	(*fmt)++;
	*ret = ft_chrjoin_free(*ret, flag, 1);
	if (**fmt == flag && (flag == 'h' || flag == 'l'))
	{
		*ret = ft_chrjoin_free(*ret, flag, 1);
		(*fmt)++;
	}
}

int		ft_isconv(const char tag)
{
	int ret;

	ret = 0;
	ret += (tag == 'd' || tag == 'D' ? 1 : 0);
	ret += (tag == 's' || tag == 'S' ? 1 : 0);
	ret += (tag == 'c' || tag == 'C' ? 1 : 0);
	ret += (tag == 'x' || tag == 'X' ? 1 : 0);
	ret += (tag == 'o' || tag == 'O' ? 1 : 0);
	ret += (tag == 'e' || tag == 'E' ? 1 : 0);
	ret += (tag == 'p' || tag == 'i' ? 1 : 0);
	ret += (tag == 'b' ? 1 : 0);
	return (ret);
}

int		ft_islm(const char tag)
{
	int ret;

	ret = 0;
	ret += (tag == 'l' || tag == 'h' ? 1 : 0);
	ret += (tag == 'j' || tag == 'z' ? 1 : 0);
	return (ret);
}

int		convert(va_list *args, char *flag, int minw, int pre, char *lm)
{
	char *ret;
	char conv;

	conv = recup_conv(flag);
	if (conv == 'i' || conv == 'd' || conv == 'D')
		ret = decimal(args, lm, pre, conv);
	else if (conv == 'c' || conv == 'C')
		ret = chrct(args, lm, pre, conv);
	else if (conv == 's' || conv == 'S')
		ret = string(args, lm, pre, conv);
	else if (conv == 'o' || conv == 'O')
		ret = base_swap_oct(args, lm, pre, conv, flag);
	else if (conv == 'x' || conv == 'X')
		ret = base_swap_hex(args, lm, pre, conv);
	else if (conv == 'e' || conv == 'E')
		ret = base_swap_sci(args, lm, pre, conv);
	else if (conv == 'p')
		ret = ptr(args, lm, pre);
	else if (conv == 'b')
		ret = base_swap_bin(args, lm, pre);
	else
		return (0);
	ret = add_flag(ret, minw, flag, conv);
	ft_putstr(ret);
	return ((!ret ? 0 : ft_strlen(ret)));
}

char	recup_conv(char *flag)
{
	char ret;
	int i;

	i = 0;
	while (flag[i])
	{
		if (ft_isconv(flag[i]))
		{
			ret = flag[i];
			flag[i] = 0;
			return (ret);
		}
		else
			i++;
	}
	return (0);
}
