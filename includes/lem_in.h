#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>

typedef struct			s_instruction
{
	char			*str;
	char			*error;
	struct s_instruction	*next;
	struct s_instruction	*prev;
}				t_instruction;

typedef struct			s_maze
{
	size_t			length;
	size_t			nbr_ants;
	t_instruction		*head;
	t_instruction		*tail;
}				t_maze;

t_maze				*ft_parse_file(int ac, char **av);
t_maze				*ft_parse_instructions(int fd);
t_maze				*ft_catch_errors_maze(t_maze *maze);

t_maze				*new_maze(void);
t_maze				*maze_append(t_maze *maze, char *str);
void				ft_show_instructs(t_maze *maze);

t_instruction			*ft_parse_nbr_ants(t_maze *maze, t_instruction *instru);
t_instruction			*ft_parse_rooms(t_maze *maze, t_instruction *instru);
int				ft_is_command(t_instruction *instru);
t_instruction			*ft_add_error(t_instruction *dest, char *error);
void				print_fatal_error(char *str);
int				ft_atoi(char *str);
#endif
