/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:48:08 by ehande            #+#    #+#             */
/*   Updated: 2021/01/31 15:18:52 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_digit(char **s)
{
	int res;

	res = 0;
	while (ft_isdigit(**s))
	{
		res = res * 10 + (**s - '0');
		*s += 1;
	}
	return (res);
}

void	init_vl(t_vl *vl)
{
	vl->i = 0;
	vl->j = 0;
	vl->n_i = -1;
	vl->n_j = -1;
	vl->counter = 0;
	vl->ch = 0;
	vl->s = NULL;
	vl->p = NULL;
}

int		close_app(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	exit(0);
	return (0);
}

char	*chang_notation(int i, unsigned long long inp, int sst)
{
	unsigned long long	tmp;
	char				*str;

	tmp = inp;
	if (!inp)
		return (ft_strdup("0"));
	while (tmp && i++ >= 0)
		tmp /= sst;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (i-- >= 0)
	{
		str[i] = (inp % sst) < 10 ? (inp % sst) + 48 : (inp % sst) + 87;
		inp /= sst;
	}
	return (str);
}
