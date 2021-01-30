/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:48:32 by ehande            #+#    #+#             */
/*   Updated: 2020/11/06 21:43:27 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s2, const char *s1, size_t len)
{
	unsigned int	n;
	size_t			t;

	if (*s1 == '\0')
		return (char*)(s2);
	n = 0;
	t = ft_strlen(s1);
	while (*s2 != '\0')
	{
		if (n + t > len)
			return (NULL);
		if (ft_strncmp(s2, s1, t) == 0)
			return (char*)(s2);
		s2++;
		n++;
	}
	return (NULL);
}
