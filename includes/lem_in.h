/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:34:20 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/30 02:47:53 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>

# define LM_NBR_ANTS	1
# define LM_ROOM		2
# define LM_TUBE		3
# define LM_START		4
# define LM_END			5
# define LM_COM			6

typedef struct				s_instruction
{
	char					*str;
	char					*error;
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
	char 					*name;
	int						numero;
	int						y;
	int						x;
	int						layer;
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
}							t_maze;

typedef struct				s_queue
{
	int						front;
	int						rear;
	int						size;
	unsigned				capacity;
	t_adj_lst				**array;
}							t_queue;
/*
** functions for reading the file and initializing the maze
*/
t_maze						*ft_parse_file(int ac, char **av, t_maze *maze);
t_maze						*ft_parse_instructions(int fd, t_maze *maze);
t_maze						*ft_catch_errors_maze(t_maze *maze);
t_maze						*new_maze(t_maze *maze);

/*
** functions mostly usefull for controlling the instructions
*/
t_maze						*maze_append(t_maze *maze, char *str);
void						ft_show_instructs(t_maze *maze);
int							ft_turn_and_check(t_maze *maze, int *value);
t_instruction				*ft_parse_nbr_ants(t_maze *maze, t_instruction *instru);
t_instruction				*ft_parse_rooms(t_maze *maze, t_instruction *instru);
t_instruction				*ft_parse_tubes(t_maze *maze, t_instruction *instru);
int							ft_is_tube(t_instruction *tmp);
int							ft_is_room(t_instruction *tmp);
int							ft_is_command(t_instruction *instru);
t_instruction				*ft_add_error(t_instruction *dest, char *error);
void						print_fatal_error(char *str);
int							ft_atoi(char *str);

/*
** functions use during bfs 
*/
void						ft_bfs(t_maze *maze);

/*
** functions for adjacent_list
*/
t_adj_node					*new_adj_node(t_adj_lst *dest);
t_adj_lst					*new_tab_adj(int nbr_rooms);
void						ft_add_lst_edge(t_adj_lst *tab, t_adj_lst *dest, t_adj_lst *srcs);
void						show_adj_lst_tab(t_maze *maze, t_adj_lst *tab, int size);
void						ft_delete_node(t_adj_lst *lst, t_adj_node *node);

/*
** functions for controlling the queue
*/
t_queue						*new_queue(unsigned capacity);
int							ft_queue_is_full(t_queue *queue);
int							ft_queue_is_empty(t_queue *queue);
void						ft_enqueue(t_queue *queue, t_adj_lst *item);
t_adj_lst					*ft_dequeue(t_queue *queue);

#endif
