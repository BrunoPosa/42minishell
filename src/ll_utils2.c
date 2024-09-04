/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:35:09 by walnaimi          #+#    #+#             */
/*   Updated: 2024/09/03 19:00:03 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_arr_updater(t_env **env_ll)
{
	int		i;
	int		size;
	t_env	*tmp;
	char	**env;

	i = 0;
	tmp = (*env_ll);
	size = ll_size(env_ll);
	env = malloc(sizeof(char **) * (size + 1));
	if (!env)
		return (NULL);
	while (i < size)
	{
		env[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;
	tmp = NULL;
	return (env);
}

int	ll_size(t_env **env_ll)
{
	t_env	*tmp;
	int		i;

	if (!env_ll || !*env_ll)
		return (0);
	i = 1;
	tmp = *env_ll;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = NULL;
	return (i);
}

void	free_all_ll(t_env **env_ll)
{
	free_ll(*env_ll);
	free_null(env_ll);
}
