/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:52:04 by ehande            #+#    #+#             */
/*   Updated: 2020/11/14 00:27:48 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*begin;

	begin = (*lst);
	if (begin == NULL)
		(*lst) = new;
	else
	{
		begin = ft_lstlast(begin);
		begin->next = new;
	}
}
