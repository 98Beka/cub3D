/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:58:09 by ehande            #+#    #+#             */
/*   Updated: 2020/11/12 19:34:20 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t sz)
{
	size_t t;
	size_t i;

	t = 0;
	i = 0;
	while (src[t] != '\0')
		t++;
	if (sz == 0)
		return (t);
	while (src[i] != '\0' && i < (sz - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (t);
}
