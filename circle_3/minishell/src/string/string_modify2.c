/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_modify2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:40:48 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:40:50 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	str_replace(t_string *str, size_t pos, size_t len, \
		const char *str_to_replace)
{
	size_t	replace_len;
	char	*backup;
	size_t	i;

	if ((str_to_replace == NULL) || (pos > str->text_len - 1) || len == 0)
		return (NO_ACTION);
	replace_len = ft_strlen(str_to_replace);
	if (str->text_len + replace_len > str->capacity - 1 + len)
		if (str_reserve(str, (str->capacity * 2) + replace_len) != SUCCESS)
			return (ERROR);
	backup = NULL;
	if (pos <= str->text_len)
		backup = ft_strdup(&(str->text[pos + len]));
	i = str->text_len;
	while (i-- > pos)
		str_pop_back(str);
	if (pos <= str->text_len)
		str_append(str, str_to_replace);
	str_append(str, backup);
	if (backup != NULL)
		free(backup);
	return (SUCCESS);
}

int	str_replace_all(t_string *str, const char *substr_old, \
		const char *substr_new)
{
	char	*replace_location;
	size_t	replace_idx;
	size_t	replace_len;

	if (substr_old == NULL || substr_new == NULL)
		return (NO_ACTION);
	replace_len = ft_strlen(substr_old);
	replace_location = ft_strnstr(str->text, substr_old, str->text_len);
	while (replace_location != NULL)
	{
		replace_idx = replace_location - str->text;
		if (str_replace(str, replace_idx, replace_len, substr_new) == ERROR)
			return (ERROR);
		replace_location = ft_strnstr(str->text, substr_old, str->text_len);
	}
	return (SUCCESS);
}
