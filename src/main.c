/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:12:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/08/26 20:29:59 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code = 0;

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	t_env	**env_ll;
	int		status;

	status = 0;
	(void)argv;
	if (!env || !*env || argc != 1)
		return (1);
	env = add_shell_lvl(env);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	env_ll = ft_calloc(1, sizeof(t_env *));
	if (!env_ll)
	{
		free_null(data);
		return (1);
	}
	initializer(data, env_ll, env);
	status = wow_loop(data, env_ll);
	super_free(data, env_ll);
	return (status);
}
