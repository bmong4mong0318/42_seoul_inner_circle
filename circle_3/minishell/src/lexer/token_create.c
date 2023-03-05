/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:30:26 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:30:29 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*new_token(char *str_input)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(*token));
	token->type = E_TYPE_DEFAULT;
	token->str = new_string(8);
	if (token->str == NULL)
		return (NULL);
	token->heredoc_fd = -1;
	token->str->f_append(token->str, str_input);
	token->f_append = token_append;
	token->f_pop_back = token_pop_back;
	token->f_push_back = token_push_back;
	token->f_reset = token_reset;
	return (token);
}
