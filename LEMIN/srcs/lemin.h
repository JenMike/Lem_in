#ifndef LEMIN_H
# define LEMIN_H
# define VISITED 1
# define UNVISITED 0

# include "../libft/libft.h"

typedef struct  s_room
{
char            *name;
int             r_nbr;
int             start;
int             end;
int             path;
int             x;
int             y;
int             len;
int             visit_check;
int             quickest_path;
struct s_ants   *ant;
struct s_room   **links;
struct s_room   *next;
struct s_room   *prev;
}               t_room;

typedef struct		s_parse
{
	int				line_i;
	char			*line;
	int				type;
	char			*c;

	struct s_parse	*next;
}					t_parse;

typedef struct  s_links
{
    int             from_room;
    int             to_room;
    struct s_links  *next;
}               t_links;

typedef struct  s_setup 
{
	int				quickest_path;
    int             ac;
    char            **av;
	char			*line;
	struct s_room	*rooms;
	struct s_room	*room_temp;
	struct s_room	*start;
	struct s_room	*end;
	struct s_room	*path;
	struct s_ants	*ants;
	struct s_room	*latest_room;
	struct s_links	*links;
    struct s_parse  *parse;
    struct s_parse  *parse_tmp;
    struct s_parse  *parse_head;
    
}               t_setup;


typedef struct  s_move
{
    /* data */
}               t_move;

typedef struct s_output
{
    /* data */
}               t_output;

typedef struct s_ants
{
	long int		nbr;
	struct s_ants *next;
}				t_ants;


void            free_rooms(t_setup *s_room);
void        	set_pathpoints(t_setup *setup);
void            pathfinder(t_setup *s_room);
void    	    get_paths(t_setup *s_room, int moves, int *room, int size);
void            exit_room(t_setup *s_room, int r_nbr);
void            enter_room(t_setup *s_room, int r_nbr);
int             visit_check(t_setup *s_room, int room_nbr);
void            add_links(t_room ***tmp_links, t_room ***set_links, t_room **door, int array_size);
t_room          *add_room(t_room **map);
int             check_co_ords(char **arr);
void            command_check(t_room **room, int *start, int *end);
void            del_room(t_room **map);
int             duplicate_coordinates(t_room **map);
int             duplicate_name(t_room **map);
void	        error_out(int errtype);
void            free_array(char **arr);
void            free_link_array(t_room **links);
void            free_links(t_room *room);
void            free_map(t_room **map);
int             ft_links(t_room **map, char *line);
int             ft_rooms(t_room **map, char **arr, int *start, int *end);
int             get_ants(void);
void            get_map(t_room **map);
int             is_duplicate(t_room **map);
int             link_array(t_room **room, t_room **door);
int             link_split(t_room **map, char *line);
t_room          *new_room(void);
int		        validate_line(t_room **map, char *line, int *start, int *end);
int             valid_format(t_room **map, char *line, int *start, int *end);

#endif