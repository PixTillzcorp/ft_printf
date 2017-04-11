#include "ft_printf.h"

char	*ptr(va_list *args, char *lm, int pre)
{
	t_types num;
	char *ret;

	num.ptr = va_arg(*args, void *);
	if (!lm)
		return (ret = ft_ptr_to_hex(num.ptr));
	else
		return (NULL);
}

char	*base_swap_bin(va_list *args, char *lm, int pre)
{
	t_types num;
	char *ret;

	num.ll = va_arg(*args, long long);
	if (!lm)
		return (ret = ft_dec_to_bin(num.ud));
	else if (ft_strcmp(lm, "l"))
		return (ret = ft_ldec_to_bin((long long)num.l));
	else if (ft_strcmp(lm, "ll"))
		return (ret = ft_ldec_to_bin(num.ll));
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
