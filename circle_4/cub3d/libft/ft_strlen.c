/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:53:58 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:54:00 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strlen(char const *str)
{
	ssize_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len += 1;
	return (len);
}