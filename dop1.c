/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:47:53 by ehande            #+#    #+#             */
/*   Updated: 2021/01/31 21:31:08 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*check_line(char *s, t_all *all)
{
	if (!*s)
		return (NULL);
	if ((*s == '1' || *s == ' ') && all->f_bg_m)
		return (ft_lstnew(s));
	if ('R' != *s && 'N' != *s && 'S' != *s && 'W' != *s
			&& 'E' != *s && 'S' != *s && 'F' != *s && 'C' != *s)
		close_app("not_wallid line!");
	return (ft_lstnew(s));
}

int		ch_is_map(char *s)
{
	int	i;
	int	flag;

	flag = 0;
	if (!*s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] != '1' && s[i] != ' ')
			return (0);
		if (s[i] == '1')
			flag = 1;
	}
	if (flag)
		return (1);
	return (0);
}

void	all_init(t_all *all)
{
	all->mxl_line = 0;
	all->flags = F_NONE;
	all->inf.f.r = -1;
	all->inf.f.g = -1;
	all->inf.f.b = -1;
	all->inf.r.x = 0;
	all->inf.r.y = 0;
	all->dirx = -1;
	all->diry = 0;
	all->plx = 0;
	all->ply = 0.66;
	all->f_bg_m = 0;
	all->dif = 0;
	all->sp_num = 0;
}

int		skip_sp(char **s, int vl)
{
	char flag;

	flag = 0;
	while (**s == ' ')
		*s += 1;
	if (vl)
	{
		if (**s == ',')
		{
			flag = 1;
			*s += 1;
		}
		while (**s == ' ')
			*s += 1;
	}
	return (flag);
}
