/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 09:38:22 by ehande            #+#    #+#             */
/*   Updated: 2020/11/13 00:58:57 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cwrds(char const *s, char c)
{
	int		i;
	int		qwords;

	qwords = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			qwords++;
		i++;
	}
	return (qwords);
}

static int		lwrds(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		*leak(char **main_arr, int qwords)
{
	int	i;

	i = 0;
	while (i < qwords)
	{
		free(main_arr[i]);
		i++;
	}
	free(main_arr);
	return (NULL);
}

static char		**getwrd(char const *s, int qwords, char c, char **main_arr)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < qwords)
	{
		while (*s == c)
			s++;
		len = lwrds(s, c);
		if (!(main_arr[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (leak(main_arr, i));
		j = 0;
		while (j < len)
			main_arr[i][j++] = *s++;
		main_arr[i][j] = '\0';
	}
	main_arr[i] = NULL;
	return (main_arr);
}

char			**ft_split(char	const *s, char c)
{
	char	**main_arr;
	int		qwords;

	if (!s)
		return (NULL);
	qwords = cwrds(s, c);
	if (!(main_arr = (char **)malloc(sizeof(char *) * (qwords + 1))))
		return (NULL);
	main_arr = getwrd(s, qwords, c, main_arr);
	return (main_arr);
}
