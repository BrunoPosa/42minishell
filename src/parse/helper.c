/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:08:47 by walnaimi          #+#    #+#             */
/*   Updated: 2024/09/03 19:43:09 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Searches for a specific token type within a linked list of tokens.
 *
 * @param token The head of the linked list of tokens.
 * @param type The type of token to search for.
 *
 * @return A pointer to the first token of 
 * the specified type if found, NULL otherwise.
 */
t_token	*find_token(t_token *token, t_type type)
{
	t_token	*head;

	head = token;
	while (head != NULL)
	{
		if (type == head->type)
			return (head);
		head = head->next;
	}
	head = NULL;
	return (NULL);
}

/**
 * Searches for a specific token type within a linked list of tokens.
 *
 * @param token The head of the linked list of tokens.
 * @param type The type of token to search for.
 *
 * @return 1 if the token type is found, 0 otherwise.
 */
int	search_token_type(t_token *token, t_type type)
{
	t_token	*head;

	head = token;
	while (head != NULL)
	{
		if (head->type == type)
			return (1);
		head = head->next;
	}
	return (0);
}

int	ft_isnum_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
