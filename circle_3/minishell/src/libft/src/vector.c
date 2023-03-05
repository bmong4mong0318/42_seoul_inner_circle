/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:38:29 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:38:31 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_vector	*new_vector(size_t init_capacity)
{
	t_vector	*pa_vec;

	pa_vec = new_darray_malloc(init_capacity);
	pa_vec->get_last = darray_get_last;
	pa_vec->is_empty = darray_is_empty;
	pa_vec->iterate = darray_iterate;
	pa_vec->map_malloc = darray_map_malloc;
	pa_vec->pop_back = darray_pop_back;
	pa_vec->push_back = darray_push_back;
	pa_vec->reserve = darray_reserve;
	pa_vec->reset = darray_reset;
	pa_vec->shrink_to_fit = darray_shrink_to_fit;
	return (pa_vec);
}

void	delete_vector(t_vector **address_of_vec)
{
	delete_darray(address_of_vec);
}
