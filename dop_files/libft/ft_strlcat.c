/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:15:52 by ehande            #+#    #+#             */
/*   Updated: 2020/11/20 20:17:05 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sz)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] && i < sz)
		i++;
	while (src[j] && (i + j + 1) < sz)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < sz)
		dst[i + j] = 0;
	while (src[j] != '\0')
		j++;
	return (i + j);
}
