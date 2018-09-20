/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:34:20 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/20 13:29:30 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include <inttypes.h>
# define LM_NBR_ANTS	1
# define LM_ROOM		2
# define LM_TUBE		3
# define LM_START		4
# define LM_END			5
# define LM_COM			6

typedef	struct				s_error
{
	char					*msg;
	int						level;
}							t_error;

typedef struct				s_instruction
{
	char					*str;
	struct s_error			*error;
	struct s_instruction	*next;
	struct s_instruction	*prev;
	int						type;
}							t_instruction;

typedef struct				s_adj_node
{
	struct s_adj_lst		*dest;
	struct s_adj_node		*next;
}							t_adj_node;

typedef struct				s_adj_lst
{
	struct s_adj_node		*head;
	char					*name;
	int						numero;
	int						layer;
	struct s_adj_lst		*prev_in_graph;
	int						belong_to_pass;
}							t_adj_lst;

typedef struct				s_maze
{
	size_t					length;
	size_t					nbr_ants;
	t_instruction			*head;
	t_instruction			*tail;
	int						nbr_rooms;
	t_adj_lst				*tab_adj;
	int						have_start;
	int						have_end;
	t_adj_lst				*start;
	t_adj_lst				*end;
	struct s_stack			**good_ways;
	struct s_stack			*best_way;
	int						nbr_of_good_ways;
	struct s_error			*error;
	int						count_comments;
	int						count_tubes;
}							t_maze;

typedef struct				s_queue
{
	int						front;
	int						rear;
	int						size;
	unsigned				capacity;
	t_adj_lst				**array;
}							t_queue;

typedef struct				s_stack
{
	int						top;
	unsigned				capacity;
	t_adj_lst				**array;
	int						size;
}							t_stack;

/*
** functions mostly usefull for parsing the instructions
*/
t_maze						*ft_parse(t_maze *maze, int ac, char **av);
t_maze						*ft_read_file(t_maze *maze);
void						ft_show_instructs(t_maze *maze, int verbose);
int							ft_turn_and_check(t_maze *maze, int *value);
t_instruction				*ft_parse_nbr_ants(t_maze *maze, t_instruction *i);
t_instruction				*ft_parse_rooms(t_maze *maze, t_instruction *i);
t_instruction				*ft_parse_tubes(t_maze *maze, t_instruction *i);
int							ft_is_tube(t_instruction *tmp);
int							ft_is_room(t_instruction *tmp);
int							ft_is_command(t_instruction *instru);
int							ft_atoi(t_maze *maze, const char *str);
int							ft_check_parameters(t_maze *maze);
int							ft_set_adj_lst(t_maze *maze, t_instruction *index);
t_maze						*ft_parse_instructions(t_maze *maze);
void						ft_exit_properly(t_maze *maze, int error);
void						ft_show_details(t_maze *maze);
void						ft_parse_args(int ac, char **av, int *m, int *v);

/*
** function for maze controle
*/

t_maze						*maze_append(t_maze *maze, char *str);
t_maze						*new_maze(t_maze *maze);
void						ft_del_maze(t_maze *maze);

/*
** functions use during bfs
*/
int							ft_bfs(t_maze *maze, int shorter);
void						show_the_passes(t_maze *maze);
char						*ft_itoa(intmax_t num, char *str, int base);
void						show_room(int i, char *str);
void						ft_modulo_i(int *i, int modulo);
void						init_passes(t_maze *maze, int *size, char ***rooms,
		int **ants);
char						**stack_to_tab_tab(t_maze *maze, t_stack *stack,
		int **tab_of_ants);

/*
** functions for adjacent_list
*/
t_adj_lst					*new_tab_adj(int nbr_rooms);
void						ft_add_lst_edge(t_adj_lst *tab,
		t_adj_lst *dest, t_adj_lst *srcs);

/*
** functions for controlling the queue
*/

t_queue						*new_queue(unsigned capacity);
int							ft_queue_is_empty(t_queue *queue);
void						ft_enqueue(t_queue *queue, t_adj_lst *item);
t_adj_lst					*ft_dequeue(t_queue *queue);
void						ft_del_queue(t_queue *queue);

/*
** functions for controlling the stack
*/
t_stack						*new_stack(unsigned capacity);
void						ft_stack_push(t_stack *stack, t_adj_lst *item);
t_adj_lst					*ft_stack_pop(t_stack *stack);
void						ft_del_stack(t_stack *stack);

/*
** functions utils
*/
void						add_ant_to_table(int *tab, int size, int n);
int							int_tab_is_empty(int **tab, int *size, int limit);

/*
** functions fo controlling errors
*/
t_error						*new_error(char *msg, int level);
t_error						*set_error(t_error *o, char *n, int level);
#endif
