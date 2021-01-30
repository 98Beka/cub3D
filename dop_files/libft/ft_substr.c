/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:36:07 by ehande            #+#    #+#             */
/*   Updated: 2020/11/12 16:29:57 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t		i;
	size_t		size;
	char		*str;

	if (!src)
		return (NULL);
	if (ft_strlen((char *)src) < start)
		return (ft_strdup(""));
	if ((size = ft_strlen((char *)src + start)) < len)
		len = size;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
