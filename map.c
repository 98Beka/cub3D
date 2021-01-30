/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:51:05 by ehande            #+#    #+#             */
/*   Updated: 2021/01/29 15:14:28 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		drow_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map[++i] && 0 > (j = -1))
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '0')
				px_put_sc(all, j + 1, i + 1, 0x000000);
			if (all->map[i][j] == '1')
				px_put_sc(all, j + 1, i + 1, 0x00008B);
			if (all->map[i][j] == '2')
				px_put_sc(all, j + 1, i + 1, 0xFF00FF);
			if (all->map[i][j] == ' ')
				px_put_sc(all, j + 1, i + 1, 0x000001);
		}
}

static void	f1(t_all *all, int i, int j)
{
	if (!(ft_strrchr("WSNE210", all->map[i - 1][j])))
		close_app(all, "error - incorrect map format!");
	if (!(ft_strrchr("WSNE210", all->map[i + 1][j])))
		close_app(all, "error - incorrect map format!");
	if (!(ft_strrchr("WSNE210", all->map[i][j + 1])))
		close_app(all, "error - incorrect map format!");
	if (!(ft_strrchr("WSNE210", all->map[i][j - 1])))
		close_app(all, "error - incorrect map format!");
	if (!(ft_strrchr("WSNE210", all->map[i - 1][j - 1])))
		close_app(all, "error - incorrect map format!");
	if (!(ft_strrchr("WSNE210", all->map[i - 1][j + 1])))
		close_app(all, "error - incorrect map format!");
	if (!(ft_strrchr("WSNE210", all->map[i + 1][j - 1])))
		close_app(all, "error - incorrect map format!");
	if (!(ft_strrchr("WSNE210", all->map[i + 1][j + 1])))
		close_app(all, "error - incorrect map format!");
}

void		check_sides(t_all *all, t_vl *vl)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (all->map[0][++i])
		if (!(ft_strrchr("1 ", all->map[0][i])))
			close_app(all, "error - incorrect map format!");
	while (all->map[++j] != NULL)
		if (!(ft_strrchr("1 ", all->map[j][0])))
			close_app(all, "error - incorrect map format!");
	while (all->map[++vl->n_j] != NULL)
		if (!(ft_strrchr("1 ", all->map[vl->n_j][i - 1])))
			close_app(all, "error - incorrect map format!");
	while (all->map[j - 1][--i])
		if (!(ft_strrchr("1 ", all->map[j - 1][i])))
			close_app(all, "error - incorrect map format!");
}

void		check_map(t_all *all, t_vl *vl)
{
	check_sides(all, vl);
	vl->i = -1;
	while (all->map[++vl->i] && 0 > (vl->j = -1))
		while (all->map[vl->i][++vl->j])
		{
			if (all->map[vl->i][vl->j] == '2')
			{
				all->sprite[all->sp_num].x = vl->i + 1;
				all->sprite[all->sp_num].y = vl->j + 1;
				all->sp_num++;
			}
			if (ft_strrchr("WSNE", all->map[vl->i][vl->j]))
			{
				all->plr.x = vl->i + 1;
				all->plr.y = vl->j + 1;
				all->pl_orintation = all->map[vl->i][vl->j];
				all->map[vl->i][vl->j] = '0';
				vl->counter++;
			}
			else if (ft_strrchr("WSNE02", all->map[vl->i][vl->j]))
				f1(all, vl->i, vl->j);
		}
	if (vl->counter != 1)
		close_app(all, "error - incorrect map format, this game only for one!");
}
