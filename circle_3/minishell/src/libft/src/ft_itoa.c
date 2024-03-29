/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:33:22 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:33:24 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	get_nbr_len(unsigned int n)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (n == 0)
		nbr_len = 1;
	else
	{
		while (n > 0)
		{
			n /= 10;
			++nbr_len;
		}
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	unsigned int	n_tmp;
	char			*pa_result;
	size_t			nbr_len;
	size_t			sign;

	sign = 0;
	n_tmp = n;
	if (n < 0)
	{
		n_tmp = -n;
		sign = 1;
	}
	nbr_len = get_nbr_len(n_tmp);
	pa_result = malloc(sizeof(*pa_result) * (nbr_len + sign + 1));
	if (!pa_result)
		return (NULL);
	pa_result[nbr_len + sign] = '\0';
	if (sign == 1)
		pa_result[0] = '-';
	while (nbr_len > 0)
	{
		pa_result[(nbr_len--) + sign - 1] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	return (pa_result);
}
