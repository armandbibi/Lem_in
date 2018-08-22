# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 08:57:44 by triou             #+#    #+#              #
#    Updated: 2018/08/22 17:55:58 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem_in
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra 
SDIR	= srcs
IDIR	= includes
ODIR	= objs
LDIR	= libft
LIB	= ft
ITEMS 	= lem_in.c \
	  ft_parse_args.c \
	  ft_parse_instructions.c \
	  ft_catch_errors.c \
	  ft_parse_nbr_ants.c \
	  ft_parse_rooms.c \
	  ft_parse_tubes.c \
	  ft_is_command.c \
	  ft_errors.c \
	  get_next_line.c \
	  ft_atoi.c \
	  t_maze_operations.c \
	  t_adj_lst_operations.c

OBJS	= $(addprefix $(ODIR)/, $(ITEMS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $^ -L $(LDIR) -I $(LDIR) -l $(LIB)
	@echo "success !!!!!!"
	
	
$(OBJS) : | $(ODIR)


$(ODIR):
	mkdir $(ODIR)

$(ODIR)/%.o : $(SDIR)/%.c $(IDIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(IDIR) -I $(LDIR)

clean :
	@$(MAKE) -C $(LDIR) clean
	@rm -rf $(ODIR)

fclean : clean
	@$(MAKE) -C $(LDIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
