/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:27:03 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/04 07:50:28 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	call_perror(t_pipex *data, char *error_msg)
{
	free_all(data->path_tab);
	if (data->blank_cmd == 1)
		ft_printf("%s: command not found\n", error_msg);
	else
		perror(error_msg);
	exit (1);
}
