#include "lemin.h"

void			enter_room(t_setup *s_room, int room_nbr)
{
	t_room			*exploring;

	exploring = s_room->rooms;
	while (exploring)
	{
		if (exploring->r_nbr == room_nbr)
			exploring->visit_check = VISITED;
		exploring = exploring->next;
	}
}

void            exit_room(t_setup *s_room, int room_nbr)
{
    t_room      *explore;

    explore = s_room->rooms;
    while (explore)
    {
        if (explore->r_nbr == room_nbr)
            explore->visit_check = UNVISITED;
        explore = explore->next;
    }
}
