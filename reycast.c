/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:47:03 by ehande            #+#    #+#             */
/*   Updated: 2021/01/28 21:06:36 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_dir(t_all *all, t_rcst *vl)
{
	vl->camerax = 2 * vl->x / (float)all->inf.r.x - 1;
	vl->rdirx = all->dirx + all->plx * vl->camerax;
	vl->rdiry = all->diry + all->ply * vl->camerax;
	vl->mapx = (int)all->plr.x;
	vl->mapy = (int)all->plr.y;
	if (!vl->rdiry)
		vl->deltadistx = 0;
	else if (!vl->rdirx)
		vl->deltadistx = 1;
	else
		vl->deltadistx = fabs(1 / vl->rdirx);
	if (!vl->rdirx)
		vl->deltadisty = 0;
	else if (!vl->rdiry)
		vl->deltadisty = 1;
	else
		vl->deltadisty = fabs(1 / vl->rdiry);
	vl->wd = 0;
	vl->hit = 0;
}

void	check_dir(t_all *all, t_rcst *vl)
{
	vl->stepx = (vl->rdirx < 0) ? (-1) : (1);
	vl->stepy = (vl->rdiry < 0) ? (-1) : (1);
	if (vl->rdirx < 0)
		vl->sdistx = (all->plr.x - vl->mapx) * vl->deltadistx;
	else
		vl->sdistx = (vl->mapx + 1.0 - all->plr.x) * vl->deltadistx;
	if (vl->rdiry < 0)
		vl->sdisty = (all->plr.y - vl->mapy) * vl->deltadisty;
	else
		vl->sdisty = (vl->mapy + 1.0 - all->plr.y) * vl->deltadisty;
}

void	get_hit(t_all *all, t_rcst *vl)
{
	while (all->map[vl->mapx - 1][vl->mapy - 1] != '1')
		if (vl->sdistx < vl->sdisty)
		{
			vl->sdistx += vl->deltadistx;
			vl->mapx += vl->stepx;
			vl->side = 0;
		}
		else
		{
			vl->sdisty += vl->deltadisty;
			vl->mapy += vl->stepy;
			vl->side = 1;
		}
	if (vl->side == 0)
		vl->wd = (vl->mapx - all->plr.x + (1 - vl->stepx) / 2) / vl->rdirx;
	else
		vl->wd = (vl->mapy - all->plr.y + (1 - vl->stepy) / 2) / vl->rdiry;
}

void	get_drow_address(t_all *all, t_rcst *vl)
{
	vl->lh = (int)(all->inf.r.y / vl->wd);
	vl->drstrt = -vl->lh / 2 + all->inf.r.y / 2;
	if (vl->drstrt < 0)
		vl->drstrt = 0;
	vl->drend = vl->lh / 2 + all->inf.r.y / 2;
	if (vl->drend >= all->inf.r.y)
		vl->drend = all->inf.r.y - 1;
	if (vl->side == 0)
		vl->wallx = all->plr.y + vl->wd * vl->rdiry;
	else
		vl->wallx = all->plr.x + vl->wd * vl->rdirx;
	vl->wallx -= floor((vl->wallx));
	vl->texx = (int)(vl->wallx * (float)(TXW));
	if (vl->side == 0 && vl->rdirx > 0)
		vl->texx = TXW - vl->texx - 1;
	if (vl->side == 1 && vl->rdiry < 0)
		vl->texx = TXW - vl->texx - 1;
	vl->step = 1.0 * TXH / vl->lh;
	vl->texpos = (vl->drstrt - all->inf.r.y / 2 + vl->lh / 2) * vl->step;
}

void	ft_cast_rays(t_all *all)
{
	t_rcst	vl;
	float	zbuffer[all->inf.r.x];

	vl.x = -1;
	while (++vl.x < all->inf.r.x)
	{
		get_dir(all, &vl);
		check_dir(all, &vl);
		get_hit(all, &vl);
		get_drow_address(all, &vl);
		if (!vl.side && all->plr.x > vl.rdirx + all->plr.x)
			drow_wall(all, &vl, 0);
		else if (!vl.side)
			drow_wall(all, &vl, 1);
		else if (vl.side && all->plr.y > vl.rdiry + all->plr.y)
			drow_wall(all, &vl, 2);
		else if (vl.side)
			drow_wall(all, &vl, 3);
		zbuffer[vl.x] = vl.wd;
	}
	drow_sprit(all, zbuffer);
	drow_map(all);
	px_put_sc(all, all->plr.y, all->plr.x, 0x3333ff);
	mlx_put_image_to_window(all->scr.mlx, all->scr.win, all->img.img, 0, 0);
}
