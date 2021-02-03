/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:51:58 by ehande            #+#    #+#             */
/*   Updated: 2021/01/31 15:19:46 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		fix_map(t_all *all)
{
	t_vl vl;

	vl.i = -1;
	while (all->map[++vl.i])
		if (all->mxl_line > ft_strlen(all->map[vl.i]))
		{
			vl.j = -1;
			vl.p = ft_calloc(all->mxl_line + 1, sizeof(char *));
			vl.p[all->mxl_line] = '\0';
			ft_memset(vl.p, ' ', all->mxl_line);
			while (all->map[vl.i][++vl.j])
				vl.p[vl.j] = all->map[vl.i][vl.j];
			free(all->map[vl.i]);
			all->map[vl.i] = vl.p;
		}
}

void		clean_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	free(lst);
}

char		**get_arr(t_list *head, int i)
{
	char	**arr;
	t_list	*tmp;

	tmp = head;
	arr = ft_calloc(ft_lstsize(head) + 1, sizeof(char *));
	while (head)
	{
		arr[i++] = head->content;
		head = head->next;
	}
	arr[i] = NULL;
	clean_lst(tmp);
	return (arr);
}

void		get_map(int fd, t_all *all, char *p)
{
	t_list	*head;
	t_vl	vl;

	head = NULL;
	ft_lstadd_back(&head, check_line(p, all));
	while (get_next_line(fd, &p))
	{
		if (all->mxl_line < ft_strlen(p))
			all->mxl_line = ft_strlen(p);
		ft_lstadd_back(&head, check_line(p, all));
	}
	ft_lstadd_back(&head, check_line(p, all));
	all->map = get_arr(head, 0);
	close(fd);
	fix_map(all);
	init_vl(&vl);
	check_map(all, &vl);
}

void		get_inform(char *argv, t_all *all)
{
	t_list	*head;
	t_vl	vl;

	head = NULL;
	if (!(vl.j = open(argv, O_RDONLY)))
		close_app("file not finded!");
	while (get_next_line(vl.j, &vl.p) && !ch_is_map(vl.p))
		if (*vl.p && *vl.p != ' ')
			ft_lstadd_back(&head, ft_lstnew(vl.p));
		else
			free(vl.p);
	all->f_bg_m = 1;
	all->inf_arr = get_arr(head, 0);
	get_map(vl.j, all, vl.p);
	vl.i = 0;
	while (all->inf_arr[vl.i])
	{
		pars_inform(all, all->inf_arr[vl.i]);
		free(all->inf_arr[vl.i]);
		vl.i++;
	}
	free(all->inf_arr);
	if (all->flags != (char)0b11111111 || vl.i != 8)
		close_app("error - incorect inform format!");
}
