/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_inf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:51:50 by ehande            #+#    #+#             */
/*   Updated: 2021/01/30 19:04:51 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_r(t_all *all, char *s)
{
	if (*s != 'R')
		return (1);
	all->flags = all->flags | F_R;
	s++;
	skip_sp(&s, 0);
	if (!(all->inf.r.x = get_digit(&s)))
		return (0);
	skip_sp(&s, 0);
	if (!(all->inf.r.y = get_digit(&s)))
		return (0);
	skip_sp(&s, 0);
	if (*s)
		return (0);
	if (all->inf.r.x > 2560 || all->inf.r.y > 1440)
		write(1, "warning - bad screan size !\n", 13);
	return (1);
}

char		*get_path(char *s)
{
	int	i;

	i = 0;
	skip_sp(&s, 0);
	if (!s)
		return (NULL);
	if (*s == '.' && *(++s) == '/')
		while (s + i != ft_strnstr(s, ".xpm", ft_strlen(s)) && *(s + i))
			i++;
	if (ft_strnstr(s + i, ".xpm", ft_strlen(s)) != s + i)
		return (NULL);
	return (ft_substr(s, 0, i + 4));
}

t_rgb		get_fc(t_all *all, char *s, char c, char msk)
{
	t_rgb rgb;

	if (*s != c)
		close_app(all, "error - incorect F or C format!");
	all->flags = all->flags | msk;
	s++;
	skip_sp(&s, 0);
	if (0 > (rgb.r = get_digit(&s)) || rgb.r > 255)
		close_app(all, "error - incorect F or C format!");
	skip_sp(&s, 1);
	if (0 > (rgb.g = get_digit(&s)) || rgb.g > 255)
		close_app(all, "error - incorect F or C format!");
	skip_sp(&s, 1);
	if (0 > (rgb.b = get_digit(&s)) || rgb.b > 255)
		close_app(all, "error - incorect F or C format!");
	skip_sp(&s, 0);
	if (*s)
		close_app(all, "error - incorect F or C format!");
	return (rgb);
}

char		*check_repit(int i, char *s, char *flags, char msk)
{
	if (*flags & msk)
		return (NULL);
	*flags = *flags | msk;
	return (get_path(s + i));
}

void		pars_inform(t_all *all, char *s)
{
	if (!get_r(all, s))
		close_app(all, "error - incorect R format!");
	if (*s == 'N' && *(s + 1) == 'O')
		if (!(all->inf.no = check_repit(2, s, &all->flags, F_NO)))
			close_app(all, "error - incorect NO format!");
	if (*s == 'S' && *(s + 1) == 'O')
		if (!(all->inf.so = check_repit(2, s, &all->flags, F_SO)))
			close_app(all, "error - incorect SO format!");
	if (*s == 'W' && *(s + 1) == 'E')
		if (!(all->inf.we = check_repit(2, s, &all->flags, F_WE)))
			close_app(all, "error - incorect WE format!");
	if (*s == 'E' && *(s + 1) == 'A')
		if (!(all->inf.ea = check_repit(2, s, &all->flags, F_EA)))
			close_app(all, "error - incorect EA format!");
	if (*s == 'S' && *(s + 1) != 'O')
		if (!(all->inf.s = check_repit(1, s, &all->flags, F_S)))
			close_app(all, "error - incorect S format!");
	if (*s == 'F')
		all->inf.f = get_fc(all, s, 'F', F_F);
	if (*s == 'C')
		all->inf.c = get_fc(all, s, 'C', F_C);
}
