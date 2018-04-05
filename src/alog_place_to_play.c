/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alog_place_to_play.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:35:51 by mberedda          #+#    #+#             */
/*   Updated: 2016/12/13 18:47:13 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/filler.h"

// Indiquer le char de mon player [X]
// Connaitre la derniere position du player adverse [ ]
// En fonction de ma derniere position et cette de l'adversaire choisir position opti [ ]

// fprintf(stderr, "COOR_PLACE = %d %d\n",y_map - data->piece->delta_y, x_map - data->piece->delta_x);
// printf("%d %d\n",y_map - data->piece->delta_y, x_map - data->piece->delta_x);

int static			check_place_after(t_elem *data, int x_map, int y_map, int y_piece, int x_piece)
{
	x_map += 1;
	while (data->piece->coor_piece[++y_piece])
	{
		if (data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece)] == 'O'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece)] == 'X'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece + 1)] == 'O'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece + 1)] == 'X')
			return (-1);
	}
	data->my_player->pos_opt[++(data->my_player->y_pos)] = (int*)malloc((2) * sizeof(int));
	data->my_player->pos_opt[data->my_player->y_pos][0] = y_map;
	data->my_player->pos_opt[data->my_player->y_pos][1] = x_map;
	return (0);
}

// not done

int static			check_place_before(t_elem *data, int x_map, int y_map, int y_piece, int x_piece)
{
	x_map -= 1;
	while (data->piece->coor_piece[++y_piece])
	{
		if (data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece)] == 'O'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece)] == 'X'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece + 1)] == 'O'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece + 1)] == 'X')
			return (-1);
	}
	data->my_player->pos_opt[++(data->my_player->y_pos)] = (int*)malloc((2) * sizeof(int));
	data->my_player->pos_opt[data->my_player->y_pos][0] = y_map;
	data->my_player->pos_opt[data->my_player->y_pos][1] = x_map;
	return (0);
}

// not done

int static			check_place_up(t_elem *data, int x_map, int y_map, int y_piece, int x_piece)
{
	y_map -= data->piece->size_y;
	while (data->piece->coor_piece[++y_piece])
	{
		if (data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece)] == 'O'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece)] == 'X'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece + 1)] == 'O'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece + 1)] == 'X')
			return (-1);
	}
	data->my_player->pos_opt[++(data->my_player->y_pos)] = (int*)malloc((2) * sizeof(int));
	data->my_player->pos_opt[data->my_player->y_pos][0] = y_map;
	data->my_player->pos_opt[data->my_player->y_pos][1] = x_map;
	return (0);
}

// not done

int static			check_place_down(t_elem *data, int x_map, int y_map, int y_piece, int x_piece)
{
	y_map += 1;
	while (data->piece->coor_piece[++y_piece])
	{
		if (data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece)] == 'O'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece)] == 'X'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece + 1)] == 'O'
		|| data->current_map[y_map + COOR_PIECE(y_piece, x_piece)]\
							[x_map + COOR_PIECE(y_piece, x_piece + 1)] == 'X')
			return (-1);
	}
	data->my_player->pos_opt[++(data->my_player->y_pos)] = (int*)malloc((2) * sizeof(int));
	data->my_player->pos_opt[data->my_player->y_pos][0] = y_map;
	data->my_player->pos_opt[data->my_player->y_pos][1] = x_map;
	return (0);
}

int					parse_place(t_elem *data, int x_map, int y_map, char pion)
{
	int y = -1;
	// fprintf(stderr, "%d\n",data->my_player->pos_opt[y][0]);
	// fprintf(stderr, "%d\n",data->my_player->pos_opt[y][1]);
	data->my_player->pos_opt = (int **)malloc(1000 * sizeof(int*));
	fprintf(stderr, "PION = %c\n", pion);
	while (data->current_map[(++y_map + data->piece->size_y) - data->piece->delta_y])
	{
		x_map = 4;
		while (data->current_map[y_map][(++x_map + data->piece->size_x)])
		{
			// fprintf(stderr, "MY_MAP = %c A L'INDICE = %d\n",data->current_map[y_map][x_map], x_map);
			if(data->current_map[y_map][x_map] == pion)
			{
				if (data->piece->size_y <= y_map 
					&& data->piece->size_x <= x_map)
				{
					if (check_place_before(data, x_map, y_map, -1, 0) || check_place_up(data, x_map, y_map, -1, 0))	
					{
						fprintf(stderr, "UP = %d\n", check_place_up(data, x_map, y_map, -1, 0));
						fprintf(stderr, "BEFORE = %d\n", check_place_before(data, x_map, y_map, -1, 0));
					}

				}
				if ((check_place_down(data, x_map, y_map, -1, 0)) || check_place_after(data, x_map, y_map, -1, 0))
				{
					fprintf(stderr, "DOWN = %d\n", check_place_down(data, x_map, y_map, -1, 0));
					fprintf(stderr, "AFTER = %d\n", check_place_after(data, x_map, y_map, -1, 0));
				}
			}
		}
	}
	data->my_player->pos_opt[data->my_player->y_pos + 1] = NULL;
	fprintf(stderr, "DELTA_X = %d DELTA_Y = %d\n",data->piece->delta_x ,data->piece->delta_y);
	fprintf(stderr, "SEND_X = %d SEND_Y = %d\n",data->my_player->pos_opt[0][1] - (4 + data->piece->delta_x), data->my_player->pos_opt[0][0] - data->piece->delta_y);
	printf("%d %d\n",data->my_player->pos_opt[0][1] - (4 + data->piece->delta_x), data->my_player->pos_opt[0][0] - data->piece->delta_y);	
	while (data->my_player->pos_opt[++y])
		fprintf(stderr, "coor_y = %d coor_x = %d\n",data->my_player->pos_opt[y][0], data->my_player->pos_opt[y][1]);
	return (0);
}



/*
**	__Fn__check dernier emplacement du joueur adverse <=> compare avec pos_opt quel est la meilleure option
*/