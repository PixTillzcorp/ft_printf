#include "ft_printf.h"

char	*base_swap_bin(va_list *args, char *lm, int pre)
{
	t_types num;

	num.ll = va_arg(*args, long long);
	if (!lm)
		return (ft_dec_to_bin(num.ud));
	else if (ft_strcmp(lm, "l"))
		return (ft_ldec_to_bin((long long)num.l));
	else if (ft_strcmp(lm, "ll"))
		return (ft_ldec_to_bin(num.ll));
	else
		return (NULL);
}

char	*base_swap_sci(va_list *args, char *lm, int pre, char conv)
{
	t_types num;

	num.dbl = va_arg(*args, double);
	if (!lm)
		return (ft_dec_to_sci(num.dbl, conv, pre));
	else
		return (NULL);
}

int		chrct(va_list *args, char *flag, char *lm, int minw, char conv)
{
	t_types num;
	int len;

	num.ll = va_arg(*args, long long);
	len = 0;
	if (!ft_strchr(flag, '-'))
		ft_putxchar((ft_strchr(flag, '0') ? '0' : ' '), minw - 1);
	if (conv == 'C')
		len += ft_putwchar(num.wc);
	else if (conv == 'c' && !lm)
	{
		ft_putchar(num.c);
		len++;
	}
	else if (!ft_strcmp(lm, "l"))
		len += ft_putwchar(num.wc);
	if (ft_strchr(flag, '-'))
		ft_putxchar(' ', minw - 1);
	return ((minw > 0 ? (minw + (len - 1)) : len));
}

int		string(char *str, char *flag, char *lm, int minw, int pre)
{
	int len;
	int i;
	int strl;

	len = 0;
	i = 0;
	if (str == NULL)
		str = ft_strdup("(null)");
	strl = ft_strlen(str);
	if (minw > (pre >= 0 && pre < strl ? pre : strl) && !ft_strchr(flag, '-'))
		len += ft_putxchar((ft_strchr(flag, '0') ? '0' : ' '), minw - (pre >= 0 && pre < strl ? pre : strl));
	while ((pre >= 0 && pre < strl ? i != pre : str[i]))
	{
		ft_putchar(str[i++]);
		len += 1;
	}
	if (minw > (pre >= 0 && pre < strl ? pre : strl) && ft_strchr(flag, '-'))
		len += ft_putxchar(' ', minw - (pre >= 0 && pre < strl ? pre : strl));
	return (len);
}

int		wstring(wint_t *str, char *flag, char *lm, int minw, int pre)
{
	int len;
	int i;
	int count;
	int strl;

	len = 0;
	i = 0;
	count = 0;
	if (!str)
		return (string(NULL, flag, lm, minw, pre));
	strl = ft_wstrlen(str);
	pre = pre_wstr(str, pre);
	if (ft_is_wstring(str) && MB_CUR_MAX == 1 && pre < 0)
		return (-1);
	if (minw > (pre >= 0 && pre < strl ? pre : strl) && !ft_strchr(flag, '-'))
		len += ft_putxchar((ft_strchr(flag, '0') ? '0' : ' '), minw - (pre >= 0 && pre < strl ? pre : strl));
	while ((pre >= 0 && pre < strl ? count < pre : str[i]))
	{
		count += (ft_is_wstring(str) && MB_CUR_MAX == 1 ? ft_ret_putchar(str[i++]) : ft_putwchar(str[i++]));
		if (ft_wcharlen(str[i]) > pre - count && pre >= 0)
			break;
	}
	len += count;
	if (minw > (pre >= 0 && pre < strl ? pre : strl) && ft_strchr(flag, '-'))
		len += ft_putxchar(' ', minw - (pre >= 0 && pre < strl ? pre : strl));
	return (len);
}
