/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:36:01 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:36:02 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_pow(unsigned int num, int power)
{
	int	result;

	if (power < 0)
		return (-1);
	result = 1;
	while (power-- > 0)
		result *= num;
	return (result);
}

void	ft_putnbr_uint_fd(unsigned int n, int fd)
{
	size_t			nbr_len;
	char			digit;
	unsigned int	divider;

	if (fd < 0)
		return ;
	nbr_len = ft_nbrlen_uint(n);
	while (nbr_len > 0)
	{
		divider = ft_pow(10, nbr_len - 1);
		digit = (n / divider) + '0';
		n %= divider;
		nbr_len--;
		write(fd, &digit, 1);
	}
}
