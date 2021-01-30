/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:34:53 by ehande            #+#    #+#             */
/*   Updated: 2020/11/12 16:15:18 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	t1;
	size_t	t2;

	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(p = (char *)malloc(sizeof(*s1) * (t1 + t2) + 1)))
		return (NULL);
	ft_strlcpy((char *)p, (char *)s1, t1 + 1);
	ft_strlcat((char *)p, s2, t1 + t2 + 1);
	return (p);
}
