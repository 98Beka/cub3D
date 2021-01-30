/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:58:29 by ehande            #+#    #+#             */
/*   Updated: 2021/01/29 15:09:45 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "dop_files/minilibx_opengl/mlx.h"
# include "dop_files/libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# define BUFFER_SIZE 1
# define SCALE		10
# define TXW		64
# define TXH		64
# define DEGREE		3.14159265359 / 180
# define F_NONE		0b00000000
# define F_C		0b00000001
# define F_NO		0b00000010
# define F_SO		0b00000100
# define F_WE		0b00001000
# define F_EA		0b00010000
# define F_S		0b00100000
# define F_R		0b01000000
# define F_F		0b10000000

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_scr
{
	void		*mlx;
	void		*win;
}				t_scr;

typedef struct	s_vl
{
	int			i;
	int			j;
	int			n_i;
	int			n_j;
	int			counter;
	char		ch;
	char		*s;
	char		*p;
}				t_vl;

typedef struct	s_rcst
{
	float		camerax;
	float		rdirx;
	float		rdiry;
	int			mapx;
	int			mapy;
	float		sdistx;
	float		sdisty;
	float		deltadistx;
	float		deltadisty;
	float		wd;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			texx;
	float		texpos;
	float		step;
	int			drstrt;
	int			drend;
	int			lh;
	float		wallx;
	int			x;
	int			bpp;
	int			txl;
	int			r;
	char		*s;
}				t_rcst;

typedef struct	s_sp
{
	float		spx;
	float		spy;
	float		invdet;
	float		trsx;
	float		trsy;
	int			scr;
	int			sph;
	int			drstrty;
	int			drendy;
	int			spw;
	int			drstrtx;
	int			drendx;
	int			st;
	int			txx;
	int			txy;
	int			d;
	int			c;
	int			y;
	int			bpp;
	int			txl;
	int			r;
	char		*s;
}				t_sp;

typedef struct	s_plr
{
	float		x;
	float		y;
	float		start;
	float		end;
}				t_plr;

typedef struct	s_reslution
{
	int			x;
	int			y;
}				t_reslution;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_inf
{
	t_reslution r;
	t_rgb		f;
	t_rgb		c;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
}				t_inf;

typedef struct	s_prite
{
	double		x;
	double		y;
	int			texture;
}				t_spr;

typedef struct	s_all
{
	t_inf		inf;
	t_plr		plr;
	t_data		img;
	t_img		tx[5];
	t_scr		scr;
	size_t		mxl_line;
	char		**inf_arr;
	char		**map;
	char		flags;
	int			dif;
	float		hypotinuse;
	float		dirx;
	float		diry;
	float		plx;
	float		ply;
	float		posx;
	float		posy;
	char		f_bg_m;
	char		pl_orintation;
	int			sp_num;
	t_spr		sprite[100];
}				t_all;

int				get_next_line(int fd, char **line);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_strchrgnl(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*rmdr(char *sbf, int i, int j);
void			get_inform(char *arg, t_all *all);
void			drow_map(t_all *all);
int				close_app(t_all *all, char *s);
int				ch_is_map(char *s);
t_list			*check_line(char *s, t_all *all);
void			all_init(t_all *all);
void			skip_sp(char **s, int vl);
int				get_digit(char **s);
void			pars_inform(t_all *all, char *s);
void			check_map(t_all *all, t_vl *vl);
void			init_vl(t_vl *vl);
void			px_put(t_all *all, int x, int y, int c);
void			px_put_sc(t_all *all, int x, int y, int color);
void			ft_cast_rays(t_all *all);
char			*get_path(char *s);
char			*chang_notation(int i, unsigned long long inp, int sst);
unsigned int	rgb(int r, int g, int b);
void			drow_wall(t_all *all, t_rcst *vl, int tx);
void			get_textur(t_all *all);
void			player_start_rotate(t_all *all);
void			save_img(t_all *all);
void			drow_sprit(t_all *all, float *zb);

#endif
