#include "ft_printf.h"

char	*decimal(va_list *args, char *lm, int pre, char conv)
{
	t_types num;
	char *ret;

	num.ll = va_arg(*args, long long);
	if (!lm)
	{
		if (conv == 'D')
			return (ret = ft_litoa((long long)num.l));
		return (ret = ft_itoa(num.d));
	}
	else if (!ft_strcmp(lm, "ll"))
		return (ret = ft_litoa(num.ll));
	else if (!ft_strcmp(lm, "l"))
		return (ret = ft_litoa((long long)num.l));
	else if (!ft_strcmp(lm, "hh"))
		return (ret = ft_itoa((int)num.c));
	else if (!ft_strcmp(lm, "h"))
		return (ret = ft_itoa((int)num.i));
	else if (!ft_strcmp(lm, "j"))
		return (ret = ft_litoa((long long)num.imt));
	else if (!ft_strcmp(lm, "z"))
		return (ret = ft_litoa((long long)num.z));
	else
		return (NULL);
}

char	*chrct(va_list *args, char *lm, int pre, char conv)
{/*a modifier*/
	t_types num;
	char *ret;

	num.ll = va_arg(*args, long long);
	ret = ft_strdup("");
	if (!lm)
		return (ret = ft_chrjoin_free(ret, num.c, 1));
	else if (!ft_strcmp(lm, "l") || conv == 'C')
		return (ret = ft_chrjoin_free(ret, num.wc, 1));
	else
	{
		free(ret);
		return (NULL);
	}
}

char	*string(va_list *args, char *lm, int pre, char conv)
{ /* faire une fonction pour chacun des types*/
	t_types num;
	char *ret;

	num.ws = (wchar_t *)(va_arg(*args, char *));
	if (!lm)
	// 	return (ft_strwdup(num.ws));
	// else if (!ft_strcmp(lm, "l") || conv == 'S')
		return (ft_strdup(num.s));
	else
		return (NULL);
}

char	*base_swap_oct(va_list *args, char *lm, int pre, char conv)
{
	t_types num;
	char *ret;

	num.ll = va_arg(*args, long long);
	if (!lm)
	{
		if (conv == 'O')
			return (ret = ft_ldec_to_base((long long)num.l, 8));
		return (ret = ft_dec_to_base(num.d, 8));
	}
	else if (!ft_strcmp(lm, "l"))
		return (ret = ft_ldec_to_base((long long)num.l, 8));
	else if (!ft_strcmp(lm, "hh"))
		return (ret = ft_dec_to_base((int)num.c, 8));
	else if (!ft_strcmp(lm, "h"))
		return (ret = ft_dec_to_base((int)num.i, 8));
	else if (!ft_strcmp(lm, "j"))
		return (ret = ft_ldec_to_base((long long)num.imt, 8));
	else if (!ft_strcmp(lm, "z"))
		return (ret = ft_ldec_to_base((long long)num.z, 8));
	else if (!ft_strcmp(lm, "ll"))
		return (ret = ft_ldec_to_base(num.ll, 8));
	else
		return (NULL);
}

char	*base_swap_hex(va_list *args, char *lm, int pre, char conv)
{
	t_types num;
	char *ret;

	num.ll = va_arg(*args, long long);
	if (!lm)
		return (ret = ft_dec_to_hex((unsigned int)num.d, conv));
	else if (!ft_strcmp(lm, "l"))
		return (ret = ft_ldec_to_hex((unsigned long long)num.l, conv));
	else if (!ft_strcmp(lm, "hh"))
		return (ret = ft_dec_to_hex((unsigned int)num.c, conv));
	else if (!ft_strcmp(lm, "h"))
		return (ret = ft_dec_to_hex((unsigned int)num.i, conv));
	else if (!ft_strcmp(lm, "j"))
		return (ret = ft_ldec_to_hex((unsigned long long)num.imt, conv));
	else if (!ft_strcmp(lm, "z"))
		return (ret = ft_dec_to_hex((unsigned int)num.z, conv));
	else if (!ft_strcmp(lm, "ll"))
		return (ret = ft_dec_to_hex((unsigned long long)num.ll, conv));
	else
		return (NULL);
}

char	*base_swap_sci(va_list *args, char *lm, int pre, char conv)
{
	t_types num;
	char *ret;

	num.ll = va_arg(*args, long long);
	if (!lm)
		return (ret = ft_dec_to_sci((unsigned int)num.d, conv, ft_itoa(pre)));
	else
		return (NULL);
}

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
