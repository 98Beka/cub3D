/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:50:05 by ehande            #+#    #+#             */
/*   Updated: 2020/11/12 16:27:47 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *src1, const char *src2, size_t n)
{
	size_t			t;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)src1;
	s2 = (unsigned char *)src2;
	t = 0;
	while (n-- > 0)
	{
		if (!s1[t] || !s2[t])
			return (s1[t] - s2[t]);
		if (s1[t] != s2[t])
			return (s1[t] - s2[t]);
		t++;
	}
	return (0);
}
