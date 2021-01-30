/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:48:48 by ehande            #+#    #+#             */
/*   Updated: 2020/11/11 15:27:06 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	string_size(int n)
{
	size_t i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static	char	*int_to_string(char *str, int n, size_t len)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*result;
	size_t	string_s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	string_s = string_size(n);
	result = (char *)malloc(sizeof(char) * string_s + 1);
	if (result == NULL)
		return (NULL);
	result = int_to_string(result, n, string_s);
	return (result);
}
