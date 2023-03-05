/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:29:27 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:29:28 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.h"

void	init_iterator(t_iterator *iter, char *line)
{
	iter->line = line;
	iter->line_len = ft_strlen(line);
	iter->curpos = INIT_SRC_POS;
	iter->f_next = iter_next;
	iter->f_peek = iter_peek;
	iter->f_skip_white_space = iter_skip_white_space;
	iter->f_unget = iter_unget;
	iter->f_has_next = iter_has_next;
}
