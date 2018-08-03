
# define LEM_IN_MAZE

typedef struct	s_room
{
	int	vertex;
	char 	*name;
	struct	s_room *next;
}		t_room;
t_room	create_room(int vertex);
void	room_set_name(char *name);
void	room_set_next(t_room *next);

typedef struct	s_maze
{
	t_room	entry;
	t_room	exit;
	int	nbr_rooms;
	int	nbr_tubes;
	int	nbr_ants;
	t_room	adj_rooms;
}		t_maze;
void	ft_info_maze(t_maze *maze);
