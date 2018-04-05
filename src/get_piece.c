/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:45:28 by mberedda          #+#    #+#             */
/*   Updated: 2016/12/13 18:01:52 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/filler.h"

int					piece_or_not(char *str, int i, char c)
{
	while(str[++i])
		if (str[i] == c)
			return (i);
	return (-2);
}

static int					empty_line(char *str, int i, char c)
{
	while(str[++i])
		if (str[i] != c)
			return (-2);
	return (1);
}
static int					empty_col(t_elem *data, int y)
{
	while (data->piece->piece[y])
	{
		if (data->piece->piece[y][0] == '*')
			return (1);
		y++;
	}
	return(0);
}

static t_elem				*clean_piece_y(t_elem *data, int y)
{
	while(empty_col(data, 0) == 0)
	{
		while (data->piece->piece[y])
		{
			data->piece->piece[y] = ft_strdup(data->piece->piece[y] + 1);
			y++;
		}
		y = 0;
	}
	return (data);
}

static t_elem				*new_len_piece(t_elem *data, int y)
{
	data->piece->size_x = ft_strlen(data->piece->piece[0]);
	while (data->piece->piece[y])
		y++;
	data->piece->size_y = y;
	return (data);
}

t_elem						*clean_piece(t_elem *data)
{
	char		pion;

	pion = '\0';
	if (data->piece->done == data->piece->size_y && data->piece->size_y != 0 && data->piece->done != 0)
	{
		data = clean_piece_y(data, 0);
		data = new_len_piece(data, 0);
		data = each_piece_coor(data, -1, -1, -1);
		pion = data->my_player->player_num == 1 ? 'X' : 'O';
		parse_place(data, -1, -1, pion);
	}
	return (data);
}

static char			**ft_realloc(t_elem *data, char *line, int i)
{
	char		**new_tab;

	new_tab = NULL;
	if (!data->piece->piece)
	{
		data->piece->piece = (char**)malloc(sizeof(char*) * 10);	
		data->piece->piece[0] = ft_strdup(line);
		return (data->piece->piece);
	}
	while (data->piece->piece[i])
		i++;
	new_tab = (char**)malloc(sizeof(char*) * 10);
	i = -1;
	while (data->piece->piece[++i])
		new_tab[i] = ft_strdup(data->piece->piece[i]);
	new_tab[i] = ft_strdup(line);
	new_tab[i + 1] = NULL;
	return(new_tab);
}

t_elem					*get_current_piece(t_elem *data, char *line, int tmp_delta)
{
	int boo;

	boo = 0;
	if (empty_line(line, -1, '.') != -2 && data->piece->done == 0)
		data->piece->delta_y += empty_line(line, -1, '.');
	if ((tmp_delta = piece_or_not(line, -1, '*')) != -2)
	{
		boo++;
		data->piece->done++;
		if (boo == 1)
			data->piece->delta_x = tmp_delta;
		data->piece->piece = ft_realloc(data, line, 0);
	}
	else if (ft_strnequ((char const*)line, ".", 1))
		data->piece->done++;
	return (data);
}