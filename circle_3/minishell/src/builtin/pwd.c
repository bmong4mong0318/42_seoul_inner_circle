/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:27:02 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:27:04 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/param.h>
#include <stdio.h>
#include "../libft/include/libft.h"
#include "../main/print_error.h"

/*
** NOTE1: It is independent of environment variable PWD.
** NOTE2: All arguments are ignored.
*/

#define SUCCESS (0)
#define ERROR	(1)

int	exec_pwd(char **arglist, char **our_envp)
{
	char	*buf;

	(void)arglist;
	(void)our_envp;
	buf = ft_calloc(1, MAXPATHLEN);
	if (getcwd(buf, MAXPATHLEN) == NULL)
	{
		ft_perror("orsh: pwd");
		return (ERROR);
	}
	ft_putstr_fd(buf, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(buf);
	return (SUCCESS);
}
