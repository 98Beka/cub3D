/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:32:06 by ehande            #+#    #+#             */
/*   Updated: 2020/11/12 16:25:04 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != '\0')
		str++;
	while (str != s)
		if (*str != c)
			str--;
		else
			return (str);
	if (*str == c)
		return (str);
	return (NULL);
}
