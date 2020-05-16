#include "lemin.h"

static void			init_setup(t_setup **setup, int ac, char **av)
{
	if (!(*setup = (t_setup *)malloc(sizeof(t_setup))))
		error_out(5);
	(*setup)->ac = ac;
	(*setup)->av = av;
	(*setup)->quickest_path = -1;
	(*setup)->rooms = NULL;
	(*setup)->room_temp = NULL;
	(*setup)->start = NULL;
	(*setup)->end = NULL;
	(*setup)->path = NULL;
	(*setup)->ants = NULL;
	(*setup)->links = NULL;
	(*setup)->parse = NULL;
	(*setup)->parse_tmp = NULL;
	(*setup)->parse_head = NULL;
}

int		main(int ac, char **av)
{
	int		ants;
	t_room	*map;
	t_setup *setup;

	init_setup(&setup, ac, av);
	map = NULL;
	ants = get_ants();
	ft_putchar('\n');
	get_map(&map);
	if (!ants)
	{
		free_map(&map);
		return (0);
	}
	set_pathpoints(setup);
	free_rooms;
	ft_putchar('\n');
	free_map(&map);
    printf("%s", "INPUT VALID\n");
	return (0);
}