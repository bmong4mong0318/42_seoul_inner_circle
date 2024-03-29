/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:35:19 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:35:20 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_spec_char(va_list argp, t_print *_info)
{
	char	c;

	c = va_arg(argp, int);
	ft_putchar_fd(c, STDOUT);
	_info->print_cnt += 1;
	_info->state = PRINTF_DONE;
}

void	handle_spec_percent(va_list argp, t_print *_info)
{
	(void)argp;
	ft_putchar_fd('%', STDOUT);
	_info->print_cnt += 1;
	_info->state = PRINTF_DONE;
}

void	handle_spec_str(va_list argp, t_print *_info)
{
	char	*s;

	s = va_arg(argp, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", STDOUT);
		_info->print_cnt += 6;
	}
	else
	{
		ft_putstr_fd(s, STDOUT);
		_info->print_cnt += ft_strlen(s);
	}
	_info->state = PRINTF_DONE;
}

void	handle_spec_addr(va_list argp, t_print *_info)
{
	void	*addr_decimal;

	addr_decimal = va_arg(argp, void *);
	ft_putstr_fd("0x", STDOUT);
	_info->print_cnt += (print_to_hex_fit((size_t)addr_decimal, 0) + 2);
	_info->state = PRINTF_DONE;
}

void	handle_spec_int(va_list argp, t_print *_info)
{
	int	num;

	num = va_arg(argp, int);
	ft_putnbr_fd(num, STDOUT);
	_info->print_cnt += ft_nbrlen(num);
	_info->state = PRINTF_DONE;
}
