/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:57:38 by mberedda          #+#    #+#             */
/*   Updated: 2016/12/13 12:48:02 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/filler.h"

void		print_map_debbug(t_elem *data, int i)
{
	while(data->piece->piece[++i])
	{
		ft_putstr_fd("my_piece = ", 2);
		ft_putendl_fd((const char*)data->piece->piece[i], 2);
	}
}

t_elem		*init(t_elem *data)
{
	// data 			= ft_memalloc(sizeof(t_elem*));
	// data->vm_player = ft_memalloc(sizeof(t_player*));
	// data->my_player = ft_memalloc(sizeof(t_ player*));
	// data->piece 	= ft_memalloc(sizeof(t_piece*));

	// // ft_bzero(data, sizeof(t_elem*));
	// ft_bzero(data->vm_player, sizeof(t_player*));
	// ft_bzero(data->my_player, sizeof(t_player*));
	// ft_bzero(data->piece, sizeof(t_piece*));
	data = (t_elem*)malloc(sizeof(t_elem));
	data->vm_player = (t_player*)malloc(sizeof(t_player));
	data->my_player = (t_player*)malloc(sizeof(t_player));
	data->piece = (t_piece*)malloc(sizeof(t_piece));

	data->current_map = NULL;
	data->map_boo = 0;
	data->pos_y = 0;
	data->pos_x = 0;

	data->piece->piece = NULL;
	data->piece->coor_piece = NULL;
	data->piece->size_x = 0;
	data->piece->size_y = 0;
	data->piece->delta_x = 0;
	data->piece->delta_y = 0;
	data->piece->done = 0;

	data->vm_player->piece = NULL;
	data->vm_player->coor_player = NULL;
	data->vm_player->player_num = 0;
	data->vm_player->pos_opt = NULL;
	data->my_player->y_pos = -1;

	data->my_player->piece = NULL;
	data->my_player->coor_player = NULL;
	data->my_player->player_num = 0;
	data->my_player->pos_opt = NULL;
	data->my_player->y_pos = -1;
	return (data);
}
int				main(void)
{
	t_elem		*data;

	data = NULL;
	data = init(data);
	get_elem(data);
	// print_map_debbug(&data, -1);
	return (0);
}