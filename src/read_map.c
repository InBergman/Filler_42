/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:52:55 by mberedda          #+#    #+#             */
/*   Updated: 2016/12/09 16:40:36 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/filler.h"

static t_elem			*get_size_map(char *line, t_elem *data)
{
	char **new_line;

	new_line 	= ft_strsplit(line, ' ');
	data->pos_y = ft_atoi(new_line[1]);
	data->pos_x = ft_atoi(new_line[2]);
	return (data);
}

static t_elem			*get_size_piece(char *line, t_elem *data)
{
	char **new_line;

	new_line 			= ft_strsplit(line, ' ');
	data->piece->size_y = ft_atoi(new_line[1]);
	data->piece->size_x = ft_atoi(new_line[2]);
	return (data);
}

static t_elem			*get_player_num(char *line, t_elem *data)
{
	if (ft_strequ((char const*)line, MY_PLAYER))
	{
		data->my_player->player_num = 1;
		return (data);
	}
	data->my_player->player_num = 2;
	return (data);
}

static t_elem			*get_coor_map(char *line, t_elem *data)
{
	if (ft_strnequ((char const*)line, "Plateau", 6))
		data = get_size_map(line, data);
	return (data);
}

static t_elem			*get_coor_piece(char *line, t_elem *data)
{
	if (ft_strnequ((char const*)line, "Piece", 4))
		data = get_size_piece(line, data);
	return (data);
}

static t_elem			*get_player(char *line, t_elem *data)
{
	if (ft_strnequ((char const*)line, "$$$", 2))
		data = get_player_num(line, data);
	return (data);
}

static t_elem					*get_current_map(t_elem *data, char *line)
{
	if ((ft_strnequ((char const*)line, "000", 2) || data->map_boo > 0))
	{
		data->map_boo++;
		if ((data->map_boo - 1) == data->pos_y)
		{
			data->current_map[data->map_boo - 1] = NULL;
			return (data);
		}
		if (data->map_boo == 1)
			data->current_map = ft_memalloc(sizeof(char**) * data->pos_y + 1);
		data->current_map[data->map_boo - 1] = ft_strdup(line);
	}
	return (data);
}

void			get_elem(t_elem *data)
{
	char		*line;

	line = NULL;
	while(get_next_line(0, &line))
	{
		data = get_player(line, data);
		data = get_coor_map(line, data);
		data = get_current_map(data, line);
		data = get_current_piece(data, line, 0);
		data = clean_piece(data);
		data = get_coor_piece(line, data);
	}
}