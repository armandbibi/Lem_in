
# define LEMIN_PARSE_H
# include "lemin_maze.h"


int	ft_parse_file(char **av, t_maze *maze, char **error);

char	**ft_innit_error(void);
void	ft_add_error(char **lst_error, int error);
void	ft_display_error(char **error);

int	ft_is_command(char *str, t_maze *maze);
int	ft_is_nbr_ants(char *str);
int	ft_is_room(char *str, t_maze *maze, char **error, int token);
int	ft_is_tube(char *str);

int	ft_parse_nbr_ants(t_maze *maze, char *str);
int	ft_parse_room(t_maze *maze, char *str);
int	ft_parse_tube(t_maze *maze, char *str);

int	ft_atoi(char *str);
