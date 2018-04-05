/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:57:38 by mberedda          #+#    #+#             */
/*   Updated: 2016/12/13 12:46:23 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "ft_printf.h"

# define MY_PLAYER "$$$ exec p2 : [./mberedda.filler]"
# define COOR_PIECE(Y_COOR, X_COOR) data->piece->coor_piece[Y_COOR][X_COOR]

// fprintf(stderr, "DONE = %d\n", data->piece->done);

typedef struct 			s_player
{
	char				**piece;
	int					**coor_player;
	int					player_num;
	int					**pos_opt;
	int					y_pos;

}						t_player;

typedef struct 			s_piece
{
	char				**piece;
	int					**coor_piece;
	int					size_x;
	int					size_y;
	int					delta_x;
	int					delta_y;
	int					done;

}						t_piece;

typedef struct 			s_elem
{
	char				**current_map;
	int					map_boo;
	int					pos_y;
	int					pos_x;

	t_player			*vm_player;
	t_player			*my_player;
	t_piece				*piece;
}						t_elem;

/*
**	__Fn__debbug
*/

void			print_map_debbug(t_elem *data, int i);

/*
**	__Fn__tools
*/
int					piece_or_not(char *str, int i, char c);

/*
**	__Fn__parsing
*/

t_elem			*get_current_piece(t_elem *data, char *line, int tmp_delta);
void			get_elem(t_elem *data);
t_elem			*init(t_elem *data);
t_elem			*clean_piece(t_elem *data);
t_elem			*each_piece_coor(t_elem *data, int x, int y, int i);
int				parse_place(t_elem *data, int x_map, int y_map, char pion);
# endif