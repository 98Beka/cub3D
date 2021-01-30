/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:47:23 by ehande            #+#    #+#             */
/*   Updated: 2021/01/28 21:08:13 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b << 0));
}

void			player_start_rotate(t_all *all)
{
	float		rotspeed;
	float		olddirx;
	float		oldplanex;

	if (all->pl_orintation == 'N')
		return ;
	if (all->pl_orintation == 'S')
		rotspeed = DEGREE * 180;
	if (all->pl_orintation == 'W')
		rotspeed = DEGREE * 90;
	if (all->pl_orintation == 'E')
		rotspeed = DEGREE * 270;
	olddirx = all->dirx;
	all->dirx = all->dirx * cos(rotspeed) - all->diry * sin(rotspeed);
	all->diry = olddirx * sin(rotspeed) + all->diry * cos(rotspeed);
	oldplanex = all->plx;
	all->plx = all->plx * cos(rotspeed) - all->ply * sin(rotspeed);
	all->ply = oldplanex * sin(rotspeed) + all->ply * cos(rotspeed);
}

void			px_put(t_all *all, int x, int y, int color)
{
	char	*dst;
	int		b;

	b = all->img.bits_per_pixel / 8;
	dst = all->img.addr + (y * all->img.line_length + x * b);
	*(unsigned int*)dst = color;
}

void			px_put_sc(t_all *all, int x, int y, int color)
{
	char	*dst;
	t_vl	vl;
	int		b;

	b = all->img.bits_per_pixel / 8;
	vl.i = (y *= SCALE) - SCALE;
	vl.n_i = vl.i;
	vl.n_j = vl.j;
	vl.j = (x *= SCALE) - SCALE;
	while (vl.i < y)
	{
		vl.j = x - SCALE;
		while (vl.j < x)
		{
			dst = all->img.addr + (vl.i * all->img.line_length + vl.j * b);
			if ((vl.i == vl.n_i || vl.j == vl.n_j) && SCALE != 1)
				*(unsigned int*)dst = 0x191970;
			else
				*(unsigned int*)dst = color;
			vl.j++;
		}
		vl.i++;
	}
}
