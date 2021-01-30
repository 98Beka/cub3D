/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:47:28 by ehande            #+#    #+#             */
/*   Updated: 2021/01/28 07:18:11 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	get_imgs(t_all *all, char *path, int i)
{
	int		*w;
	int		*h;
	int		*b;
	t_img	t;

	w = &all->tx[i].width;
	h = &all->tx[i].height;
	t.img = mlx_xpm_file_to_image(all->scr.mlx, path, w, h);
	b = &t.bits_per_pixel;
	t.addr = mlx_get_data_addr(t.img, b, &t.line_length, &t.endian);
	return (t);
}

void	get_textur(t_all *all)
{
	all->tx[0] = get_imgs(all, all->inf.we, 0);
	all->tx[1] = get_imgs(all, all->inf.no, 1);
	all->tx[2] = get_imgs(all, all->inf.ea, 2);
	all->tx[3] = get_imgs(all, all->inf.so, 3);
	all->tx[4] = get_imgs(all, all->inf.s, 4);
}
