/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:35:27 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:35:29 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

size_t	ft_putstr_until(const char *str, char stopper, t_print *_info)
{
	size_t		len;
	const char	*str_cpy;

	len = 0;
	str_cpy = str;
	while (*str_cpy != stopper && *str_cpy != '\0')
	{
		len += 1;
		str_cpy += 1;
	}
	ft_nputstr_fd(str, STDOUT, len);
	_info->print_cnt += len;
	return (len);
}

int	ft_vprintf(const char *fmt, va_list argp)
{
	int		print_cnt;
	t_print	*_info;

	_info = init_info_malloc();
	while (*fmt != '\0')
	{
		fmt += ft_putstr_until(fmt, '%', _info);
		if (*fmt == '%')
		{
			_info->state = PRINTF_SPEC;
			fmt += 1;
			parse_format(&fmt, argp, _info);
			reset_state(_info);
		}
	}
	print_cnt = _info->print_cnt;
	free(_info);
	return (print_cnt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	argp;
	int		done;

	va_start(argp, fmt);
	done = ft_vprintf(fmt, argp);
	va_end(argp);
	return (done);
}
