/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:32:30 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:32:31 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>  
#include <stddef.h>
#include <limits.h>

extern bool	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	size_t			sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		sum *= 10;
		sum += (*str - '0');
		++str;
	}
	if (sign > 0 && sum > LONG_MAX + 0)
		return (-1);
	else if (sign < 0 && sum > (size_t)LONG_MAX + 1)
		return (0);
	return ((int)(sum * sign));
}
