void	flag_lm(const char **fmt, char **ret, char flag)
{
	*fmt++;
	*ret = ft_chrjoin_free(*ret, flag, 1);
	if (**fmt == flag && (flag == 'h' || flag != 'l'))
		*ret = ft_chrjoin_free(*ret, flag, 1);
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

	conv = recup_conv(&flag);
	if (conv == 'i' || conv == 'd')
		ret = decimal(args, lm, pre);
	else if (conv == 'c' || conv == 'C')
		ret = chrct(args, lm, pre);
	else if (conv == 's' || conv == 'S')
		ret = string(args, lm, pre);
	else if (conv == 'o' || conv == 'O' || conv == 'x' || conv == 'X')
		ret = base_swap(args, lm, pre, conv);
	else if (conv == 'e' || conv == 'E')
		ret = base_swap(args, lm, pre, conv);
}

char	recup_conv(char **flag)
{
	while (**flag)
	{
		if (ft_isconv(**flag))
		{
			**flag = '\0';
			return (**flag);
		}
		else
			(*flag)++;
	}
	return (NULL);
}