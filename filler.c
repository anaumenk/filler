/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:32:40 by anaumenk          #+#    #+#             */
/*   Updated: 2018/03/16 18:05:47 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	check_piece(t_import *h, int x)
{
	int y;

	while (x < h->piece_h)
	{
		y = 0;
		while (y < h->piece_w)
		{
			if (h->piece[x][y] == '*' && h->m == 0 && (h->m = 1))
			{
				h->piece_s_u = x;
				h->piece_s_l = y;
				h->piece_s_r = y;
				h->piece_s_d = x;
			}
			if (h->piece[x][y] == '*' && h->m == 1 && y < h->piece_s_l)
				h->piece_s_l = y;
			if (h->piece[x][y] == '*' && h->m == 1 && y > h->piece_s_r)
				h->piece_s_r = y;
			if (h->piece[x][y] == '*' && h->m == 1 && x > h->piece_s_d)
				h->piece_s_d = x;
			y++;
		}
		x++;
	}
}

void	piece(char **line, t_import *h)
{
	int		i;
	char	*tmp;

	tmp = ft_strchr(*line, ' ') + 1;
	h->piece_h = ft_atoi(tmp);
	h->piece_w = ft_atoi(ft_strchr(tmp, ' ') + 1);
	h->piece = (char**)malloc(sizeof(char*) * (h->piece_h));
	i = 0;
	free(*line);
	while (i < h->piece_h)
	{
		get_next_line(0, line);
		h->piece[i++] = ft_strdup(*line);
		free(*line);
	}
	h->m = 0;
	i = 0;
	check_piece(h, i);
	h->x = 0;
	h->y = 0;
	fill_it(h);
}

void	map(char **line, t_import *h)
{
	int		i;
	char	*tmp;

	tmp = ft_strchr(*line, ' ') + 1;
	h->map_h = ft_atoi(tmp);
	h->map_w = ft_atoi(ft_strchr(tmp, ' ') + 1);
	h->map = (char**)malloc(sizeof(char*) * (h->map_h));
	free(*line);
	get_next_line(0, line);
	free(*line);
	i = 0;
	while (i < h->map_h)
	{
		get_next_line(0, line);
		h->map[i++] = ft_strdup(*line + 4);
		free(*line);
	}
	get_next_line(0, line);
}

int		main(void)
{
	char		*line;
	t_import	*h;

	h = ft_memalloc(sizeof(t_import));
	get_next_line(0, &line);
	h->p = (ft_strstr(line, "anaumenk") && ft_strstr(line, "p1")) ? 'O' : 'X';
	h->lp = (ft_strstr(line, "anaumenk") && ft_strstr(line, "p1")) ? 'o' : 'x';
	free(line);
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
			map(&line, h);
		if (ft_strstr(line, "Piece"))
			piece(&line, h);
	}
	free(h);
	return (0);
}
