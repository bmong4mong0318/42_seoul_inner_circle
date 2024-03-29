/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:33:07 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:33:09 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../include/libft.h"

bool	ft_isinteger(char *s)
{
	int			sign;
	size_t		sum;

	sum = 0;
	sign = 1;
	if (s[0] == '-' && s++)
		sign = -1;
	while (*s != '\0')
	{
		if (ft_isdigit(*s) == false)
			return (false);
		sum *= 10;
		sum += (*s - '0');
		s++;
	}
	if (sign < 0 && sum > ((size_t)INT_MAX + 1))
		return (false);
	else if (sign > 0 && sum > (size_t)INT_MAX)
		return (false);
	else
		return (true);
}
