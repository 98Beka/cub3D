/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:46:58 by ehande            #+#    #+#             */
/*   Updated: 2021/01/28 20:12:47 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pos_sp(t_all *all, t_sp *vl)
{
	vl->invdet = 1.0 / (all->plx * all->diry - all->dirx * all->ply);
	vl->trsx = vl->invdet * (all->diry * vl->spx - all->dirx * vl->spy);
	vl->trsy = vl->invdet * (-all->ply * vl->spx + all->plx * vl->spy);
	vl->scr = (int)((all->inf.r.x / 2) * (1 + vl->trsx / vl->trsy));
	vl->sph = abs((int)(all->inf.r.y / (vl->trsy)));
	vl->drstrty = -vl->sph / 2 + all->inf.r.y / 2;
	if (vl->drstrty < 0)
		vl->drstrty = 0;
	vl->drendy = vl->sph / 2 + all->inf.r.y / 2;
	if (vl->drendy >= all->inf.r.y)
		vl->drendy = all->inf.r.y - 1;
	vl->spw = abs((int)(all->inf.r.y / (vl->trsy)));
	vl->drstrtx = -vl->spw / 2 + vl->scr;
	if (vl->drstrtx < 0)
		vl->drstrtx = 0;
	vl->drendx = vl->spw / 2 + vl->scr;
	if (vl->drendx >= all->inf.r.x)
		vl->drendx = all->inf.r.x - 1;
}

void	send_px_2(t_all *all, t_sp *vl)
{
	vl->d = (vl->y) * 256 - all->inf.r.y * 128 + vl->sph * 128;
	vl->txy = ((vl->d * TXH) / vl->sph) / 256;
	vl->c = *(int *)(vl->s + (vl->txy * vl->txl + vl->txx * (vl->bpp / 8)));
	if ((vl->c != 0x980088))
		px_put(all, vl->st, vl->y, vl->c);
}

void	send_px(t_all *all, float *zb, t_sp *vl)
{
	int tmp;

	tmp = vl->st - (-vl->spw / 2 + vl->scr);
	vl->txx = (int)(256 * tmp * TXW / vl->spw) / 256;
	vl->y = vl->drstrty - 1;
	if (vl->trsy > 0 && vl->st > 0 && vl->st < all->inf.r.x &&
			vl->trsy < zb[vl->st] + 0.5)
		while (++vl->y < vl->drendy)
			send_px_2(all, vl);
}

void	drow_sprit(t_all *all, float *zb)
{
	t_sp	vl;
	int		sp_n;

	sp_n = -1;
	vl.txl = all->tx[4].line_length;
	vl.bpp = all->tx[4].bits_per_pixel;
	vl.s = all->tx[4].addr;
	while (++sp_n < all->sp_num)
	{
		vl.spx = all->sprite[sp_n].x - all->plr.x;
		vl.spy = all->sprite[sp_n].y - all->plr.y;
		get_pos_sp(all, &vl);
		vl.st = vl.drstrtx - 1;
		while (++vl.st < vl.drendx)
			send_px(all, zb, &vl);
	}
}

void	drow_wall(t_all *all, t_rcst *vl, int tx)
{
	unsigned int	c;
	int				i;
	int				y;

	i = -1;
	vl->r = all->inf.f.r;
	vl->txl = all->tx[tx].line_length;
	vl->bpp = all->tx[tx].bits_per_pixel;
	vl->s = all->tx[tx].addr;
	while (i++ < vl->drstrt)
		px_put(all, vl->x, i, rgb(all->inf.c.r, all->inf.c.g, all->inf.c.b));
	while (i++ < vl->drend)
	{
		y = (int)vl->texpos & (TXH - 1);
		vl->texpos += vl->step;
		c = *(int *)(vl->s + (y * vl->txl + vl->texx * (vl->bpp / 8)));
		if (vl->side == 1)
			c = (c >> 1) & 8355711;
		px_put(all, vl->x, i, c);
	}
	while (i++ < all->inf.r.y)
		px_put(all, vl->x, i, rgb(vl->r, all->inf.f.g, all->inf.f.b));
}
