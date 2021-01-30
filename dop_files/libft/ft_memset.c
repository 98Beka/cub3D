/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:43:24 by ehande            #+#    #+#             */
/*   Updated: 2020/11/06 21:33:37 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)d;
	while (len-- > 0)
		*p++ = (unsigned char)c;
	return (p);
}
