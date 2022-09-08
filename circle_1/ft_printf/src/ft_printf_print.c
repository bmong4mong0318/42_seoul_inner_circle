/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:50:19 by dayun             #+#    #+#             */
/*   Updated: 2022/09/08 20:19:59 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

long long	fill_sign(long long num, t_tag *tag)
{
	if (num < 0)
	{
		tag->sign = '-';
		num = -num;
		tag->size--;
	}
	else if (tag->flags & PLUS)
	{
		tag->sign = '+';
		tag->size--;
	}
	else if (tag->flags & SPACE)
	{
		tag->sign = ' ';
		tag->size--;
	}
	return (num);
}

char	*fill_special(char *buf, long long num, t_tag *tag)
{
	if (tag->flags & SPECIAL)
	{
		if (tag->flag_num)
		{
			if (tag->flags & LEFT)
				return (buf);
			*buf++ = ' ';
			*buf++ = ' ';
		}
		else
		{
			*buf++ = '0';
			*buf++ = ('X' | tag->locase);
		}
	}
	return (buf);
}

char	*fill_num(char *buf, long long num, t_tag *tag)
{
	char				tmp[100];
	static const char	*digits = "0123456789ABCDEF";

	tag->size = tag->field_width;
	tag->prec = tag->precision;
	tag->locase = (tag->flags & SMALL);
	if (num == 0)
		tag->flag_num = 1;
	if (tag->flags & LEFT)
		tag->flags &= ~ZEROPAD;
	if (tag->flags & SIGN)
		num = fill_sign(num, tag);
	if ((tag->flags & SPECIAL) && !(tag->flag_num && (tag->flags & LEFT)))
		tag->size -= 2;
	if (num == 0 && (tag->prec || !tag->flag_dot))
		tmp[tag->base_len++] = '0';
	else
		while (num != 0)
			tmp[tag->base_len++] = (digits[do_div(&num, tag->base)]
					| tag->locase);
	if (tag->base_len > tag->prec)
		tag->prec = tag->base_len;
	tag->size -= tag->prec;
	return (fill_num2(buf, num, tag, tmp));
}

char	*fill_num2(char *buf, long long num, t_tag *tag, char *tmp)
{
	if (!(tag->flags & (ZEROPAD + LEFT)))
		while (tag->size-- > 0)
			*buf++ = ' ';
	if (tag->sign)
		*buf++ = tag->sign;
	buf = fill_special(buf, num, tag);
	if (!(tag->flags & LEFT))
	{
		while (tag->size-- > 0)
		{
			if (tag->flags & ZEROPAD)
				*buf++ = '0';
			else
				*buf++ = ' ';
		}
	}
	while (tag->base_len < tag->prec--)
		*buf++ = '0';
	while (tag->base_len-- > 0)
		*buf++ = tmp[tag->base_len];
	while (tag->size-- > 0)
		*buf++ = ' ';
	return (buf);
}

int	print_buf(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		i++;
	}
	return (i);
}
