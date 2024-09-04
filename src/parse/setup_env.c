/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:25:26 by walnaimi          #+#    #+#             */
/*   Updated: 2024/09/03 19:57:07 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Counts the number of keys in the environment
 * list that match the words in the input string.
 *
 * @param env_list The list of environment variables to search in.
 * @param input    The input string containing words
 * to match against the environment list.
 *
 * @return The number of matching keys found in the environment list.
 */
int	count_matching_keys(const char *input)
{
	int			count;
	const char	*ptr;

	count = 0;
	ptr = input;
	while (*ptr != '\0')
	{
		if (*ptr == '$')
			count++;
		ptr++;
	}
	return (count);
}
