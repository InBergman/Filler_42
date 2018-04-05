/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:42:34 by mberedda          #+#    #+#             */
/*   Updated: 2016/12/08 16:35:36 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/filler.h"

t_elem				*each_piece_coor(t_elem *data, int x, int y, int i)
{
	data->piece->coor_piece = (int **)malloc(20 * sizeof(int*));
	while (data->piece->piece[++y])
	{
		x = -1;
		while (data->piece->piece[y][++x])
		{
			if (data->piece->piece[y][x] == '*')
			{
				++i;
				data->piece->coor_piece[i] = (int*)malloc((2) * sizeof(int));
				data->piece->coor_piece[i][0] = y;
				data->piece->coor_piece[i][1] = x;
			}
		}	
	}	
	data->piece->coor_piece[i + 1] = NULL;
	return (data);
}
