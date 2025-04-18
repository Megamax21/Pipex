/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:49:14 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/09 15:55:14 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

int	ft_util_safe_atoi(long int nb, int sign, char c)
{
	if (sign == 1 && (nb > INT_MAX / 10 || (nb == INT_MAX / 10
				&& (c - '0') > INT_MAX % 10)))
		return (0);
	if (sign == -1 && (nb > -(long)INT_MIN / 10
			|| (nb == -(long)INT_MIN / 10
				&& (c - '0') > -(INT_MIN % 10))))
		return (0);
	return (1);
}

int	get_atoi_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_safe_atoi(const char *s, int *out)
{
	int			sign;
	size_t		i;
	long int	nb;

	if (!s || !out)
		return (0);
	nb = 0;
	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	sign = get_atoi_sign(s[i]);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (ft_util_safe_atoi(nb, sign, s[i]) == 0)
			return (0);
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	*out = (int)(nb * sign);
	return (1);
}
