/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:18:54 by ehande            #+#    #+#             */
/*   Updated: 2020/11/12 15:41:03 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	if (!(d = (char*)malloc(sizeof(*d) * len + 1)))
		return (NULL);
	while (i < len)
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
