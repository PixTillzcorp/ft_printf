int		flag_hl(const char **fmt, char flag, int nbr_flag)
{
	*fmt++;
	if (**fmt == flag)
		return (flag_hl(fmt, flag, nbr_flag + 1));
	else
		return (nbr_flag);
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

