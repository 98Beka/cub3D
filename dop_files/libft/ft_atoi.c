/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:18:52 by ehande            #+#    #+#             */
/*   Updated: 2020/11/20 22:30:03 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		msp(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					sb;

	sb = 1;
	res = 0;
	i = msp(str);
	if (str[i] == '-')
	{
		i++;
		sb = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > 2147483647 && sb == 1)
		return (-1);
	if (res > 2147483648 && sb == -1)
		return (0);
	return (res * sb);
}
