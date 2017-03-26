int		flag_hl(const char **fmt, char flag, int nbr_flag)
{
	*fmt++;
	if (flag == 'h')
	{
		if (**fmt == 'h')
			return (flag_hl(fmt, 'h', nbr_flag + 1));
		else
			return (conv_hl(fmt, 'h', nbr_flag));
	}
	else if (flag == 'l')
	{
		if (**fmt == 'l')
			return (flag_hl(fmt, 'l', nbr_flag + 1));
		else
			return (conv_hl(fmt, 'l', nbr_flag));
	}
}

int		conv_hl(const char **fmt, char flag, int flag_power)
{
	*fmt++;
	if ()
}
