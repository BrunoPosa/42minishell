/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:38:16 by walnaimi          #+#    #+#             */
/*   Updated: 2024/09/03 16:45:34 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Initialize heredoc_fds array to -1.
 *
 * @param data A pointer to the shell data structure containing information
 * about the shell state.
 *
 * @return void
 */
static void	heredoc_fds_init(t_data *data)
{
	int	i;

	i = 0;
	while (data->heredoc_fd[i])
	{
		data->heredoc_fd[i] = -1;
		i++;
	}
}

void	ll_env(t_env **env_ll, char **env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	if (*env_ll == NULL)
		*env_ll = ft_listnew(env[i++]);
	tmp = (*env_ll);
	while (env[i])
		ft_listadd_back(env_ll, ft_listnew(env[i++]));
	(*env_ll) = tmp;
}

/**
 * This function loops through the linked 
 * list of environment variables to find
 * the PATH variable. When it finds it, it 
 * extracts the value of the PATH variable
 * and stores it in the data->bin field. It
 *  then resets the *env_ll pointer to the
 * start of the linked list.
 */
void	find_bin(t_env **env_ll, t_data *data)
{
	t_env	*tmp;

	tmp = (*env_ll);
	while ((*env_ll)->next != NULL)
	{
		if (!ft_strncmp((*env_ll)->content, "PATH=", 5))
			data->bin = bin_extract((*env_ll)->content);
		(*env_ll) = (*env_ll)->next;
	}
	(*env_ll) = tmp;
}

char	*bin_extract(char *path)
{
	int	i;

	i = 0;
	if (!path)
		return (NULL);
	while (path)
	{
		if (!ft_strncmp(path, "PATH=", 5))
			return (path + 5);
		i++;
	}
	return (NULL);
}

void	initializer(t_data *data, t_env **env_ll, char **env)
{
	ft_bzero(data, sizeof(t_data));
	ll_env(env_ll, env);
	find_bin(env_ll, data);
	heredoc_fds_init(data);
	data->home_pwd = get_home((*env_ll));
	data->binary_paths = ft_split(data->bin, ':');
	if (!data->binary_paths)
	{
		free_null(data);
		free_all_ll(env_ll);
		printf("no path is found exiting...\n");
		exit(1);
	}
	data->status = 0;
	data->envll = *env_ll;
	data->in_quotes = 0;
	data->echoed = false;
	data->ignore_cmd = false;
}
