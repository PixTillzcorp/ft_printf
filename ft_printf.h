/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:43:22 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/02 17:43:24 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>

typedef union	u_types
{
    int d;
    char c;
    long l;
    short i;
    void *ptr;
    char *s;
    size_t z;
    wint_t wc;
    wchar_t *ws;
    double dbl;
    long long ll;
    intmax_t imt;
    uintmax_t uimt;
    unsigned int ud;
    unsigned char uc;
}				t_types;

int				ft_printf(const char *format, ...);
int				flag_pre(const char **format);
int				flag_minw(const char **format);
char			*flag_flag(const char **format);
int				flag_conv(const char **fmt, va_list *args, char *flag, int minw, int pre);
int				choice(const char **format, va_list *args);

void	flag_lm(const char **fmt, char **ret, char flag);
int		ft_isconv(const char tag);
int		ft_islm(const char tag);
int		convert(va_list *args, char *flag, int minw, int pre, char *lm);
char	recup_conv(char **flag);
char	*decimal(va_list *args, char *lm, int pre, char conv);
char	*chrct(va_list *args, char *lm, int pre, char conv);
char	*string(va_list *args, char *lm, int pre, char conv);
char	*base_swap_oct(va_list *args, char *lm, int pre, char conv);
char	*base_swap_hex(va_list *args, char *lm, int pre, char conv);
char	*base_swap_sci(va_list *args, char *lm, int pre, char conv);
char	*ptr(va_list *args, char *lm, int pre, char conv);



#endif
