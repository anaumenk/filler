/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:48:57 by anaumenk          #+#    #+#             */
/*   Updated: 2018/03/15 18:48:58 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		distance(int i, int j, t_import *h)
{
	int d;
	int d1;
	int d2;
	int x;
	int y;

	d = h->d;
	x = 0;
	while (x < h->map_h)
	{
		y = 0;
		while (y < h->map_w)
		{
			if (h->map[x][y] != '.' && h->map[x][y] != h->p
				&& h->map[x][y] != h->lp)
			{
				d1 = (i - x < 0) ? -(i - x) : (i - x);
				d2 = (j - y < 0) ? -(j - y) : (j - y);
				d = (d1 + d2 < d) ? d1 + d2 : d;
			}
			y++;
		}
		x++;
	}
	return (d);
}

int		find_place(int i, int j, t_import *h)
{
	int j_j;
	int x;
	int y;

	h->m = 0;
	x = h->piece_s_u;
	while (x < h->piece_h)
	{
		j_j = j;
		y = h->piece_s_l;
		while (y < h->piece_w)
		{
			if (h->piece[x][y] == '*' && (h->map[i][j_j] == h->p
				|| h->map[i][j_j] == h->lp))
				h->m++;
			else if (h->piece[x][y] == '*' && h->map[i][j_j] != '.'
				&& h->map[i][j_j] != h->p && h->map[i][j_j] != h->lp)
				return (0);
			y++;
			j_j++;
		}
		x++;
		i++;
	}
	return (h->m == 1) ? 1 : 0;
}

void	fill_it(t_import *h)
{
	int i;
	int j;

	i = 0;
	h->d = h->map_h - 1 + h->map_w - 1;
	while (i < h->map_h - ((h->piece_h - h->piece_s_u)
		- (h->piece_h - h->piece_s_d)))
	{
		j = 0;
		while (j < h->map_w - ((h->piece_w - h->piece_s_l)
			- (h->piece_w - h->piece_s_r)))
		{
			if (find_place(i, j, h) && distance(i, j, h) < h->d)
			{
				h->d = distance(i, j, h);
				h->x = i - h->piece_s_u;
				h->y = j - h->piece_s_l;
			}
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", h->x, h->y);
}
