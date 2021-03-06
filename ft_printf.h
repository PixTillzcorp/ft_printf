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
    wchar_t wc;
    wint_t *ws;
    double dbl;
    long long ll;
    intmax_t imt;
    uintmax_t uimt;
    unsigned int ud;
    unsigned long ul;
    unsigned char uc;
    unsigned short ui;
}				t_types;

int				ft_helpflag(void);
int				ft_isflag(const char format);
int				ft_printf(const char *format, ...);
int				flag_pre(const char **format);
int				flag_minw(const char **format);
int				pre_wstr(wint_t *str, int pre);
char			*flag_flag(const char **format);
char			*join_flag(char *dest, char *str);
int				flag_conv(const char **fmt, va_list *args, char *flag, int minw, int pre);
int				choice(const char **format, va_list *args);

void			flag_lm(const char **fmt, char **ret);
int				ft_isconv(const char tag);
int				ft_islm(const char tag);
int				convert(va_list *args, char *flag, int minw, int pre, char *lm);
char			recup_conv(char *flag);
int				no_conv(const char **format, char *flag, int minw);
char			*decimal(va_list *args, char *lm, int pre, char conv);
int				chrct(va_list *args, char *flag, char *lm, int minw, char conv);
int				string(char *str, char *flag, char *lm, int minw, int pre);
int				wstring(wint_t *str, char *flag, char *lm, int minw, int pre);
char			*base_swap_oct(va_list *args, char *lm, int pre, char conv, char *flag);
char			*base_swap_hex(va_list *args, char *lm, int pre, char conv);
char			*base_swap_sci(va_list *args, char *lm, int pre, char conv);
char			*base_swap_bin(va_list *args, char *lm, int pre);
char			*ptr(va_list *args, char *flag, char *lm, int minw, int pre);
char			*add_flag(char *ret, int minw, char *flag, char conv, int pre);
char			*add_minw(char *ret, int minw, char *flag, char conv, int pre);
char			*add_bin_oct(char *str);
char			*add_pre(char *ret, char conv, int pre);
char			*minw_decimal(char *ret, char *flag, int minw);
char			*udecimal(va_list *args, char *lm, int pre, char conv);



#endif
