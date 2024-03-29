/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_get_token_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:29:56 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:29:58 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"

void	get_dollar_sign(t_token *tok, t_scanner *scan)
{
	char	c;

	tok->f_push_back(tok, scan->f_next(scan));
	while (scan->f_has_next(scan))
	{
		c = scan->f_peek(scan);
		if (ft_isspace(c) || is_meta_char(c) || c == '\"' || c == '\'')
			break ;
		tok->f_push_back(tok, scan->f_next(scan));
	}
}

void	get_bracket(t_token *tok, t_scanner *scan)
{
	int	c;

	tok->type = E_TYPE_BRACKET;
	while (scan->f_has_next(scan))
	{
		c = scan->f_next(scan);
		tok->f_push_back(tok, c);
		if (c == ')')
			break ;
	}
}

static bool	is_meta_char_2(char c)
{
	if (c != '|' && c != '&' && c != '<' && c != '>' \
			&& c != '(' && c != ')')
		return (false);
	else
		return (true);
}

void	get_cmd_or_arg(t_token *tok, t_scanner *scan)
{
	char	c;

	tok->type = E_TYPE_SIMPLE_CMD;
	while (scan->f_has_next(scan))
	{
		c = scan->f_peek(scan);
		if (c == '\'')
			get_single_quote(tok, scan);
		else if (c == '\"')
			get_double_quote(tok, scan);
		else if (c == '$')
			get_dollar_sign(tok, scan);
		else if (ft_isspace(c) == false && is_meta_char_2(c) == false)
			tok->f_push_back(tok, scan->f_next(scan));
		else
			break ;
	}
}
