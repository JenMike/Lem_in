#include "lemin.h"

int					visit_check(t_setup *s_room, int room_nbr)
{
	t_room			*exploring;

    exploring = s_room->rooms;
	while (exploring)
	{
		if (exploring->r_nbr == room_nbr && exploring->visit_check == 1)
			return (VISITED);
		exploring = exploring->next;
	}
	return (UNVISITED);
}
