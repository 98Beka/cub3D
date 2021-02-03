/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:55:56 by ehande            #+#    #+#             */
/*   Updated: 2021/01/31 16:56:33 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		header(t_all *all, int fd)
{
	int		in;
	short	sh;

	write(fd, "BM", 2);
	in = 14 + 40 + all->inf.r.y *
			all->inf.r.x * 4;
	write(fd, &in, 4);
	sh = 0;
	write(fd, &sh, 2);
	write(fd, &sh, 2);
	in = 14 + 40;
	write(fd, &in, 4);
}

void		info(t_all *all, int fd)
{
	int		in;
	short	sh;

	in = 40;
	write(fd, &in, 4);
	in = all->inf.r.x;
	write(fd, &in, 4);
	in = all->inf.r.y;
	write(fd, &in, 4);
	sh = 1;
	write(fd, &sh, 2);
	sh = 32;
	write(fd, &sh, 2);
	in = 0;
	write(fd, &in, 4);
	in = all->inf.r.x * all->inf.r.y * 4;
	write(fd, &in, 4);
	in = 1000;
	write(fd, &in, 4);
	write(fd, &in, 4);
	in = 0;
	write(fd, &in, 4);
	write(fd, &in, 4);
}

void		save_img(t_all *all)
{
	int		fd;
	char	*img;
	int		i;

	i = all->inf.r.y;
	fd = open("screen.bmp", O_RDWR | O_CREAT | O_TRUNC, 00666);
	if (fd < 0)
		close_app("Can't open screen.bmp");
	header(all, fd);
	info(all, fd);
	img = all->img.addr;
	while (--i)
		img += all->inf.r.x * 4;
	while (i < all->inf.r.x)
	{
		write(fd, img, all->inf.r.x * 4);
		img -= all->inf.r.x * 4;
		i++;
	}
	close(fd);
	close_app("bye");
}
