/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:31:21 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:32:20 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DARRAY_H
# define DARRAY_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_darray {
	size_t		size;
	size_t		capacity;
	void		**data;
}	t_darray;

extern t_darray	*new_darray_malloc(size_t init_capacity);
extern void		delete_darray(t_darray **arr_ptr);
extern void		*new_data_malloc(size_t init_capacity);
extern void		darray_set_data(t_darray *arr, size_t index, void *data);
extern void		darray_reset(t_darray *vec);
extern int		darray_is_empty(t_darray *vec);
extern void		*darray_reserve(t_darray *vec, size_t new_capacity);
extern void		darray_push_back(t_darray *vec, void *data);
extern void		darray_pop_back(t_darray *vec);
extern void		*darray_shrink_to_fit(t_darray *vec);
extern void		darray_iterate(t_darray *arr, void (*f)(void *));
extern t_darray	*darray_map_malloc(t_darray *arr, void *(*f)(void *));

#endif /* DARRAY_H */
