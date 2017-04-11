#include "ft_printf.h"

char	*ptr(va_list *args, char *lm, int pre, char conv)
{
	t_types num;
	char *ret;

	num.ptr = va_arg(*args, void *);
	if (!lm)
		return (ret = ft_ptr_to_hex(num.ptr));
	else
		return (NULL);
}

char	*add_flag(char *ret, int minw, char *flag, char conv)
{
	ft_putstr("flags = ");
	ft_putstr(flag);
	ft_putchar('\n');
	if (ft_strchr(flag, '#'))
	{
		if (conv == 'o' && ft_strcmp(ret, "0"))
			ret = ft_strjoin_free("0", ret, 'r');
		else if ((conv == 'x' || conv == 'X' ) && ft_strcmp(ret, "0"))
			ret = ft_strjoin_free((conv == 'x' ? "0x" : "0X"), ret, 'r');
	}
	if (conv == 'd' || conv == 'D' || conv == 'i' || conv == 'e' || conv == 'E')
	{
		if (ft_strchr(flag, '+') && !ft_strchr(ret, '-'))
			ret = ft_strjoin_free("+", ret, 'r');
		else if (ft_strchr(flag, ' ') && !ft_strchr(ret, '-'))
			ret = ft_strjoin_free(" ", ret, 'r');
	}
	while ((int)(ft_strlen(ret)) < minw)
	{
		if (ft_strchr(flag, '-'))
			ret = ft_chrjoin_free(ret, ' ', 1);
		else if (ft_strchr(flag, '0'))
			ret = ft_strjoin_free("0", ret, 'r');
		else
			ret = ft_strjoin_free(" ", ret, 'r');
	}
	return (ret);
}
