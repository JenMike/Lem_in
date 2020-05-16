#include "lemin.h"

static void			create_room(t_setup *s_room, int current_room)
{
	t_room			*explore;

	explore = s_room->rooms;
	while (explore && explore->r_nbr != current_room)
		explore = explore->next;
	if (!(s_room->room_temp = (t_room *)malloc(sizeof(t_room))))
		error_out(4);
	s_room->room_temp->name = ft_strdup(explore->name);
	s_room->room_temp->r_nbr = explore->r_nbr;
	s_room->room_temp->x = explore->x;
	s_room->room_temp->y = explore->y;
	s_room->room_temp->start = explore->start;
	s_room->room_temp->end = explore->end;
	s_room->room_temp->visit_check = UNVISITED;
	s_room->room_temp->ant = explore->ant;
	s_room->room_temp->next = NULL;
	s_room->room_temp->prev = NULL;
}

static void			create_path(t_setup *s_room, int current_room)
{
	create_room(s_room, current_room);
	if (!s_room->path)
		s_room->path = s_room->room_temp;
	else
	{
		s_room->room_temp->next = s_room->path;
		s_room->path->prev = s_room->room_temp;
		s_room->path = s_room->room_temp;
	}
	s_room->room_temp = NULL;
}

static void			p_generate(t_setup *s_room, int moves, int current_room)
{
	t_links			*explore;

	explore = s_room->links;
	if (moves > s_room->quickest_path)
		return ;
	enter_room(s_room, current_room);
	if (current_room == s_room->end->r_nbr && moves == s_room->quickest_path)
	{
		s_room->quickest_path = -2;
		exit_room(s_room, current_room);
		create_path(s_room, current_room);
		return ;
	}
	while (explore)
	{
		if (explore->from_room == current_room && visit_check(s_room, explore->to_room) == UNVISITED)
			p_generate(s_room, moves + 1, explore->to_room);
		if (s_room->quickest_path == -2)
		{
			create_path(s_room, current_room);
			return ;
		}
		explore = explore->next;
	}
	exit_room(s_room, current_room);
}

void				pathfinder(t_setup *s_room)
{
	get_paths(s_room, 0, &s_room->start->r_nbr, 1);
	if (s_room->quickest_path == -1)
	{
		s_room->parse_head = s_room->parse;
		while (s_room->parse_head && s_room->parse_head->next)
			s_room->parse_head = s_room->parse_head->next;
		error_out(2);
	}
	p_generate(s_room, 0, s_room->start->r_nbr);
}
