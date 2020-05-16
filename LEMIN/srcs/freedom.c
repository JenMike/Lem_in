
#include "lemin.h"

//frees all items in array and then array pointer

void    free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        ft_strdel(&arr[i]);
        i++;
    }
    free(arr);
}

//frees saved rooms and subsequent connected t_room structs (links)

void    free_map(t_room **map)
{
    t_room  *room;
    t_room  *next;

    if (*map == NULL)
        return ;
    room = *map;
    while (room != NULL)
    {
        free_link_array((room->links));
        next = room->next;
        free(room->name);
        free(room);
        room = next;
    }
    *map = NULL;
}

void    free_link_array(t_room **links)
{
    if (!links)
        return ;
    free(links);
}

void    free_links(t_room *room)
{
    free(room->links);
    room->links = NULL;
}

static void			free_mf(t_room *track)
{
	t_room			*del;

	while (track)
	{
		del = track;
		track = track->next;
		free(del->name);
		del->name = NULL;
		free(del);
		del = NULL;
	}
}

void		free_rooms(t_setup *s_room)
{
	free_mf(s_room->rooms);
	free_mf(s_room->room_temp);
	free_mf(s_room->path);
}