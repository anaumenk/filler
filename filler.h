/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:33:37 by anaumenk          #+#    #+#             */
/*   Updated: 2018/03/02 16:33:39 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libftprintf/includes/libft.h"

typedef struct	s_import
{
	char	p;
	char	lp;
	char	**map;
	int		map_h;
	int		map_w;
	char	**piece;
	int		piece_h;
	int		piece_w;
	int		m;
	int		piece_s_u;
	int		piece_s_l;
	int		piece_s_r;
	int		piece_s_d;
	int		x;
	int		y;
	int		d;
	int		exit;
}				t_import;

void			fill_it(t_import *h);

#endif
