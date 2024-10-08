/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:21:18 by bposa             #+#    #+#             */
/*   Updated: 2024/09/03 18:56:23 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_my_boi(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free_null(paths[i]);
		i++;
	}
	free_null(paths);
}

void	free_gang(t_data *data)
{
	if (data->tok_res != NULL)
		free_null(data->tok_res);
	if (data->temp_str != NULL)
		free_null(data->temp_str);
	if (data->new_str != NULL)
		free_null(data->new_str);
	free_tokens(data->token);
}

void	free_tokens(t_token *head)
{
	t_token	*tmp;

	tmp = NULL;
	while (head != NULL)
	{
		tmp = head;
		if (tmp->value)
			free_null(tmp->value);
		if (tmp->path)
			free_null(tmp->path);
		head = head->next;
		free_null(tmp);
	}
}

int	free_retstatus(char *array, int status)
{
	free(array);
	array = NULL;
	return (status);
}
