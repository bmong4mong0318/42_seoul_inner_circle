/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:30:12 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:30:13 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "../../include/libft.h"
#include "scanner.h"
#include "../main/print_error.h"

bool	is_bracket_inside_bracket(t_token *tok_1)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = &(tok_1->str->text[1]);
	while (*tmp != '\0')
	{
		if (*tmp == '(')
		{
			*tmp = '\0';
			print_error_syntax_str(tmp - count);
			return (true);
		}
		count++;
		tmp++;
	}
	return (false);
}

bool	is_bracket_unclosed(t_token *tok_1)
{
	char	c;

	c = tok_1->str->text[tok_1->str->text_len - 1];
	if ((tok_1->str->text[0] == '(' && c != ')'))
	{
		if (*(tok_1->str->text + 1) == '\0')
			print_error_syntax_str("newline");
		else
			print_error_syntax_char(*(tok_1->str->text + 1));
		return (true);
	}
	if (tok_1->str->text[0] == ')')
	{
		print_error_syntax_char(')');
		return (true);
	}
	if (is_bracket_inside_bracket(tok_1))
		return (true);
	return (false);
}

bool	is_meta_token_type(t_token_type type)
{
	if (type != E_TYPE_PIPE && type != E_TYPE_DOUBLE_PIPE && \
			type != E_TYPE_DOUBLE_AMPERSAND && type != E_TYPE_AMPERSAND)
		return (false);
	else
		return (true);
}

bool	is_meta_char(char c)
{
	if (c != '|' && c != '&' && c != '<' && c != '>')
		return (false);
	else
		return (true);
}
