char	*decimal(va_list *args, char *lm, int pre)
{
	t_types num;
	int ret;

	num.ll = (long long)(va_arg(*args, int));
	if (!ft_strcmp(lm, "ll") || !ft_strcmp(lm, "l"))
		return (ret = ft_litoa(num.ll));
	else if (!ft_strcmp(lm, "h"))
		return (ret = ft_itoa(num.i));
	else if (!ft_strcmp(lm, "j"))
		return (ret = ft_itoa(num.imt))
}
