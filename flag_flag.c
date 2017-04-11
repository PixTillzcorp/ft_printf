#include "ft_printf.h"

char	*add_flag(char *ret, int minw, char *flag, char conv)
{
	if (!ret)
		return (ret = add_minw(ft_strdup(""), minw, flag, conv));
	if (ft_strchr(flag, '#'))
	{
		if (!ft_strchr(flag, '0') || ft_strchr(flag, '-'))
		{
			if (conv == 'o' && ft_strcmp(ret, "0"))
				ret = ft_strjoin_free("0", ret, 'r');
			else if ((conv == 'x' || conv == 'X' ) && ft_strcmp(ret, "0"))
				ret = ft_strjoin_free((conv == 'x' ? "0x" : "0X"), ret, 'r');
		}
		else if (conv == 'b')
			ret = add_bin_oct(ret);
	}
	if (conv == 'd' || conv == 'D' || conv == 'i' || conv == 'e' || conv == 'E')
	{
		if (ft_strchr(flag, '+') && !ft_strchr(ret, '-'))
			ret = ft_strjoin_free("+", ret, 'r');
		else if (ft_strchr(flag, ' ') && !ft_strchr(ret, '-'))
			ret = ft_strjoin_free(" ", ret, 'r');
	}
	return (ret = add_minw(ret, minw, flag, conv));
}

char	*add_minw(char *ret, int minw, char *flag, char conv)
{
	while ((int)(ft_strlen(ret)) < minw)
	{
		if (ft_strchr(flag, '-'))
			ret = ft_chrjoin_free(ret, ' ', 1);
		else if (ft_strchr(flag, '0'))
		{
			if (ft_strchr(flag, '#') && (ft_strlen(ret) + 2) == minw &&\
				(conv == 'x' || conv == 'X' ) && ft_strcmp(ret, "0"))
				ret = ft_strjoin_free((conv == 'x' ? "0x" : "0X"), ret, 'r');
			else
				ret = ft_strjoin_free("0", ret, 'r');
		}
		else
			ret = ft_strjoin_free(" ", ret, 'r');
	}
	if (conv == 'b' && ft_strcmp(flag, "#"))
		ret = add_bin_oct(ret);
	return (ret);
}

char	*add_bin_oct(char *str)
{
	char *ret;
	int i;

	i = 0;
	ret = ft_strdup("");
	str = ft_strrev(str);
	while (str[i])
	{
		if (i % 8 == 0 && i != 0)
			ret = ft_chrjoin_free(ret, '.', 1);
		else
			ret = ft_chrjoin_free(ret, str[i], 1);
		i++;
	}
	return (ft_strrev(ret));
}
