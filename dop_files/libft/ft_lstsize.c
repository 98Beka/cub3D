/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:15:20 by ehande            #+#    #+#             */
/*   Updated: 2020/11/14 00:28:13 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*s;
	int		count;

	count = 0;
	s = lst;
	if (lst != NULL)
	{
		while (s != NULL)
		{
			count++;
			s = s->next;
		}
	}
	return (count);
}
