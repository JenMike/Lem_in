
#include "lemin.h"

static void			r_add_line(t_setup *setup)
{
	t_parse			*tmp;

	if (!(setup->parse_tmp = (t_parse *)malloc(sizeof(t_parse))))
		lem_in_error(setup);
	if (!(setup->parse_tmp->line = ft_strdup(setup->line)))
		lem_in_error(setup);
	setup->parse_tmp->type = 0; //ERROR
	setup->parse_tmp->c = NULL;
	setup->parse_tmp->next = NULL;
	if (setup->parse)
	{
		tmp = setup->parse;
		while (tmp->next)
			tmp = tmp->next;
		setup->parse_tmp->line_i = tmp->line_i + 1;
		tmp->next = setup->parse_tmp;
	}
	else
	{
		setup->parse_tmp->line_i = 1;
		setup->parse = setup->parse_tmp;
	}
	setup->parse_tmp = NULL;
}

// get_ants checks 1st line, 
// if !digits or <0, exits with ERROR

int     get_ants(void)
{
    long long   ants;
    char        *line;

    ants = 0;
    line = NULL;
    get_next_line(0, &line);
    if (ft_can_atoi(line) != 1)
    {
        ft_memdel((void**)&line);
        error_out(3);
        exit(1);
    }
    ants = ft_atoi(line);
    ft_memdel((void**)&line);
    if (ants < 1)
    {
        error_out(3);
        exit(1);
    }
	ft_putnbr(ants);
	return (ants);
}

// get_map reads input and checks input validity
// uses validate_line to check input
// 1st line must be ants

void				parse_read(t_setup *setup)
{
	while (get_next_line(0, &setup->line) == 1)
	{
		parse_add_line(setup);
		free(setup->line);
		setup->line = NULL;
	}
	if (setup->line)
		free(setup->line);
	setup->line = NULL;
	if (!setup->parse)
		error_out(1);
	setup->parse_head = setup->parse;
	get_parse_types(setup);
}

void    get_map(t_room **map)
{
    char    *line;
    int     start;
    int     end;

    line = NULL;
    start = 0;
    end = 0;
    while (get_next_line(0, &line))
    {
        if (line[0])
            ft_putendl(line);
        if (validate_line(map, line, &start, &end) == 0)
        {
            free_map(map);
            ft_memdel((void**)&line);
            error_out(1);
        }
        ft_memdel((void**)&line);
    }
    ft_memdel((void**)&line);
    if (start != -1 || end != -1 || is_duplicate(map) == 1)
    {
        free_map(map);
        if (start != -1 || end != -1)
            error_out(2);
        else
            error_out(5);
    }
}
