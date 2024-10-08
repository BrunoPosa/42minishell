/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:58:29 by walnaimi          #+#    #+#             */
/*   Updated: 2024/09/03 12:42:54 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s != '\0' && (*s >= '0' && *s <= '9'))
	{
		res = (res * 10) + (*s - '0');
		s++;
		if (res < 0)
		{
			if (sign == 1)
				return ((int) 9223372036854775807);
			return ((int) -9223372036854775807 - 1);
		}
	}
	return ((int)res * sign);
}
