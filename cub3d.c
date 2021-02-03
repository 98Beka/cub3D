/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:58:38 by ehande            #+#    #+#             */
/*   Updated: 2021/01/31 21:34:31 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(int key, t_all *all)
{
	float	speed;
	float	old_dirx;
	float	old_planex;

	speed = 0.05;
	old_planex = all->plx;
	old_dirx = all->dirx;
	if (key == 47)
		speed = -0.07;
	all->dirx = all->dirx * cos(speed) - all->diry * sin(speed);
	all->diry = old_dirx * sin(speed) + all->diry * cos(speed);
	all->plx = all->plx * cos(speed) - all->ply * sin(speed);
	all->ply = old_planex * sin(speed) + all->ply * cos(speed);
}

void	move(int key, t_all *all, float x, float y)
{
	if (key == 13)
	{
		if (all->map[(int)(all->plr.x + x) - 1][(int)all->plr.y - 1] == '0')
			all->plr.x += x;
		if (all->map[(int)all->plr.x - 1][(int)(all->plr.y + y) - 1] == '0')
			all->plr.y += y;
	}
	if (key == 1)
	{
		if (all->map[(int)(all->plr.x - x) - 1][(int)all->plr.y - 1] == '0')
			all->plr.x -= x;
		if (all->map[(int)(all->plr.x) - 1][(int)(all->plr.y - y) - 1] == '0')
			all->plr.y -= y;
	}
}

void	strave(int key, t_all *all, float x, float y)
{
	if (key == 2)
	{
		if (all->map[(int)(all->plr.x + x) - 1][(int)all->plr.y - 1] == '0')
			all->plr.x += x;
		if (all->map[(int)all->plr.x - 1][(int)(all->plr.y + y) - 1] == '0')
			all->plr.y += y;
	}
	if (key == 0)
	{
		if (all->map[(int)(all->plr.x - x) - 1][(int)all->plr.y - 1] == '0')
			all->plr.x -= x;
		if (all->map[(int)(all->plr.x) - 1][(int)(all->plr.y - y) - 1] == '0')
			all->plr.y -= y;
	}
}

int		hook_key(int key, t_all *all)
{
	if (key == 13 || key == 1)
		move(key, all, all->dirx * 0.2, all->diry * 0.2);
	if (key == 0 || key == 2)
		strave(key, all, all->plx * 0.2, all->ply * 0.2);
	if (key == 43 || key == 47)
		rotate(key, all);
	if (key == 53)
		close_app("bye!!!");
	ft_cast_rays(all);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all all;

	if (argc == 1)
		close_app("pleas, write path of map.");
	if (argc > 3)
		close_app("incorect arguments.");
	all_init(&all);
	get_inform(argv[1], &all);
	player_start_rotate(&all);
	make_win(&all);
	get_textur(&all);
	drow_map(&all);
	ft_cast_rays(&all);
	if (argc == 3 && ft_strncmp("--save", argv[2], 6))
		close_app("wrong comand to save img");
	else if (argc == 3)
		save_img(&all);
	mlx_hook(all.scr.win, 2, 1L << 0, hook_key, &all);
	mlx_hook(all.scr.win, 17, 17, close_app, "bye!");
	mlx_loop(all.scr.mlx);
	mlx_destroy_image(all.scr.mlx, all.img.img);
	return (0);
}
