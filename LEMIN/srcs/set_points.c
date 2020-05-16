/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenmike <jenmike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:57:47 by jenmike           #+#    #+#             */
/*   Updated: 2020/05/16 18:28:49 by jenmike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void				set_pts(t_setup *setup)
{
	setup->start = setup->path;
	setup->end = setup->path;
	while (setup->end && setup->end->next)
		setup->end = setup->end->next;
}

static void			put_ants(t_setup *setup)
{
	setup->start->ant = setup->ants;
	setup->ants = NULL;
}

void        set_pathpoints(t_setup *setup)
{
    
    pathfinder(setup);
    set_pt(setup);
    put_ants(setup);
    /* if (setup->start->next != setup->end)
        move_ants(); 
        else
            */
}