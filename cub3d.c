/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:58:38 by ehande            #+#    #+#             */
/*   Updated: 2021/01/30 21:10:30 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_win(t_all *all)
{
	int x;

	x = all->inf.r.x;
	all->scr.mlx = mlx_init();
	all->scr.win = mlx_new_window(all->scr.mlx, x, all->inf.r.y, "cub3D!");
	all->img.img = mlx_new_image(all->scr.mlx, x, all->inf.r.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
			&all->img.line_length, &all->img.endian);
}

void	rotate(int key, t_all *all)
{
	float	speed;
	float	old_dirx;
	float	old_planex;

	speed = 0.05;
	old_planex = all->plx;
	old_dirx = all->dirx;
	if (key == 2 || key == 124)
		speed = -0.05;
	all->dirx = all->dirx * cos(speed) - all->diry * sin(speed);
	all->diry = old_dirx * sin(speed) + all->diry * cos(speed);
	all->plx = all->plx * cos(speed) - all->ply * sin(speed);
	all->ply = old_planex * sin(speed) + all->ply * cos(speed);
}

void	move(int key, t_all *all, float x, float y)
{
	if (key == 13 || key == 126)
	{
		if (all->map[(int)(all->plr.x + x) - 1][(int)all->plr.y - 1] == '0')
			all->plr.x += x;
		if (all->map[(int)all->plr.x - 1][(int)(all->plr.y + y) - 1] == '0')
			all->plr.y += y;
	}
	if (key == 1 || key == 125)
	{
		if (all->map[(int)(all->plr.x - x) - 1][(int)all->plr.y - 1] == '0')
			all->plr.x -= x;
		if (all->map[(int)(all->plr.x) - 1][(int)(all->plr.y - y) - 1] == '0')
			all->plr.y -= y;
	}
	if (key == 0 || key == 123 || key == 2 || key == 124)
		rotate(key, all);
}

int		hook_key(int key, t_all *all)
{
	if (key == 13 || (key > -1 && key < 3) || (key > 122 && key < 127))
	{
		move(key, all, all->dirx * 0.2, all->diry * 0.2);
		ft_cast_rays(all);
	}
	if (key == 53)
		close_app(all, "bye!!!");
	drow_map(all);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all all;

	if (argc == 1)
		close_app(&all, "pleas, write path of map.");
	if (argc > 3)
		close_app(&all, "incorect arguments.");
	all_init(&all);
	get_inform(argv[1], &all);
	player_start_rotate(&all);
	make_win(&all);
	get_textur(&all);
	drow_map(&all);
	ft_cast_rays(&all);
	if (argc == 3 && ft_strncmp("--save", argv[2], 6))
		close_app(&all, "wrong comand to save img");
	else if (argc == 3)
		save_img(&all);
	mlx_hook(all.scr.win, 2, 1L << 0, hook_key, &all);
	mlx_hook(all.scr.win, 17, 17, close_app, "bye!");
	mlx_loop(all.scr.mlx);
	mlx_destroy_image(all.scr.mlx, all.img.img);
	return (0);
}
