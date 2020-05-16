/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenmike <jenmike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 13:16:30 by jenmike           #+#    #+#             */
/*   Updated: 2020/05/16 17:43:53 by jenmike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			*path_array(t_setup *s_room, int *room,
		int size, int total_links)
{
	int				i;
	int				j;
	t_links			*explore;
	int				*path_array;

	i = 0;
	j = 0;
	if (!(path_array = (int *)malloc(sizeof(int) * total_links)))
		error_out(4);
	while (i < size)
	{
		explore = s_room->links;
		while (explore)
		{
			if (explore->from_room == room[i] && visit_check(s_room, explore->to_room) == UNVISITED)
				path_array[j++] = explore->to_room;
			explore = explore->next;
		}
		i++;
	}
	return (path_array);
}

static int			get_all_links(t_setup *s_room, int *room, int size)
{
	int				i;
	t_links			*explore;
	int				total_links;

	i = 0;
	total_links = 0;
	while (i < size)
	{
		explore = s_room->links;
		while (explore)
		{
			if (explore->from_room == room[i] && visit_check(s_room, explore->to_room))
				total_links++;
			explore = explore->next;
		}
		i++;
	}
	return (total_links);
}

void    	get_paths(t_setup *s_room, int moves, int *room, int size)
{
	int				i;
	int				*p_array;
	int				total_links;

	i = 0;
	total_links = 0;
	while (i < size)
	{
		enter_room(s_room, room[i]);
		if (room[i] == s_room->end->r_nbr)
		{
			exit_room(s_room, room[i]);
			s_room->quickest_path = moves;
			return ;
		}
		i++;
	}
	if (!(total_links = get_all_links(s_room, room, size)))
		return ;
	p_array = path_array(s_room, room, size, total_links);
	get_paths(s_room, moves + 1, p_array, total_links);
	i = 0;
	while (i < size)
		exit_room(s_room, room[i++]);
	free(p_array);
}
