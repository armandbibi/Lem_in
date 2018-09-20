# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 08:57:44 by triou             #+#    #+#              #
#    Updated: 2018/09/20 13:21:49 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra $(debug)
SDIR	= srcs
INC 	= ./libft/

IDIR	= includes
ODIR	= objs
LDIR	= libft

ITEMS 	= lem_in.c \
		 ft_parse.c \
	 	 ft_parse_args.c \
	 	 ft_read_file.c \
	 	 ft_parse_instructions.c \
	 	 ft_parse_nbr_ants.c \
	 	 ft_parse_rooms.c \
	 	 ft_parse_tubes.c \
		 ft_set_adj_lst.c \
		 ft_check_parameters.c \
	 	 ft_is_command.c \
		 display_passes.c \
		 display_passes2.c \
		 get_next_line.c \
		 ft_atoi.c \
		 ft_itoa.c \
		 bfs.c \
		 ft_free_maze.c \
		 t_maze_operations.c \
		 t_adj_lst_operations.c \
		 t_queue_operations.c \
		 t_queue_operations2.c \
		 t_stack_operations.c \
		 t_error_operations.c \

OBJS	= $(addprefix $(ODIR)/, $(ITEMS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $^ -I $(IDIR) -I $(LDIR) -L $(LDIR) -lft
	@echo "success !!!!!!"
	
	
$(OBJS) : | $(ODIR)

$(ODIR):
	mkdir $(ODIR)

$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@$(CC) -o $@ -c $< -I $(IDIR) -I $(LDIR)
	@echo "compiling $<"

clean :
	@$(MAKE) -C $(LDIR) clean
	@rm -rf $(ODIR)

fclean : clean
	@$(MAKE) -C $(LDIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
