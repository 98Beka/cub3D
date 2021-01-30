/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:40:15 by ehande            #+#    #+#             */
/*   Updated: 2020/11/06 21:27:07 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*src;
	int					i;

	i = -1;
	src = (unsigned char *)s;
	while (n--)
		if (*src++ == (unsigned char)c)
			return (src + i++);
	return (NULL);
}
