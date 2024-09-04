/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:18:12 by walnaimi          #+#    #+#             */
/*   Updated: 2024/09/03 18:47:54 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * incorrect_pipe_syntax() checks for syntax errors related to pipes.
 * It ensures that two consecutive pipes are not used,
 * and that a pipe is not used as the last character of the command.
 *
 * RETURN VALUES:
 * Upon success, it returns 0. If it fails, it returns 2.
 */
static int	incorrect_pipe_syntax(t_token *token)
{
	t_token	*head;

	head = token;
	while (head->value)
	{
		if (head->type == PIPE)
		{
			if (head->next->value == NULL || head->next->type == PIPE)
			{
				if (head->next->value == NULL)
					return (err_msg(NEW_LINE, SYNTAX, 1));
				return (err_msg(head->next->value, SYNTAX, 1));
			}
		}
		head = head->next;
	}
	return (SUCCESS);
}

/**
 * incorrect_syntax() checks for specific operators and checks if they're
 * being repeated by the users.
 * 
 * RETURN VALUES: Upon success, it returns 0. If it fails, it returns 2.
 */
static int	incorrect_syntax(t_token *token, t_type token_type)
{
	t_token	*head;

	head = token;
	while (head)
	{
		if (head->next != NULL)
		{
			if ((head->type == token_type && head->next->type == token_type)
				|| (head->type == token_type && head->next->type == RED_IN)
				|| (head->type == token_type && head->next->type == RED_OUT)
				|| (head->type == token_type && head->next->type == HDOC)
				|| (head->type == token_type && head->next->type == APPEND)
				|| (head->type == token_type && head->next->type == PIPE)
				|| (head->type == token_type && head->next->type == FLAG)
				|| (head->type == token_type && head->next->value == NULL))
			{
				if (head->next->value == NULL)
					return (err_msg(NEW_LINE, SYNTAX, 1));
				return (err_msg(head->next->value, SYNTAX, 1));
			}
		}
		head = head->next;
	}
	head = NULL;
	return (SUCCESS);
}

/**
 * As we run through the tokens (nodes in a linked list) we check
 * if the next token type is valid for the token type that the user
 * inputted previously. Examples below:
 * "%> |||"
 * "%> syntax error near unexpected token `||'"
 */
int	syntax_check(t_token *token)
{
	if (incorrect_pipe_syntax(token) == FAILURE)
		return (FAILURE);
	if (incorrect_syntax(token, RED_OUT) == FAILURE
		|| incorrect_syntax(token, RED_IN) == FAILURE
		|| incorrect_syntax(token, HDOC) == FAILURE
		|| incorrect_syntax(token, APPEND) == FAILURE)
		return (FAILURE);
	else
		return (SUCCESS);
}
