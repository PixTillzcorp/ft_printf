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

int			ft_printf(const char *format, ...);
char		*flag_presc(const char *format, va_list *args);
char		*flag_space(const char *format, va_list *args);
void		flag_conv(const char *format, va_list *args, int presc);
char 		*flag_flag(const char *format);
char		*choice(const char *format, va_list *args);

#endif
