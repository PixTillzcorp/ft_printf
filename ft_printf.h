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

typedef union	u_types
{
    int d;
    char c;
    long l;
    short i;
    char *s;
    size_t z;
    double dbl;
    long long ll;
}				t_types;

int				ft_printf(const char *format, ...);
int				flag_pre(const char **format);
int				flag_minw(const char **format);
char			*flag_flag(const char **format);
int				flag_conv(const char **fmt, va_list *args, char *flag, int minw, int pre);
int				choice(const char **format, va_list *args);

#endif
