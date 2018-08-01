# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 08:57:44 by triou             #+#    #+#              #
#    Updated: 2018/07/30 05:04:17 by abiestro         ###   ########.fr        #
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
ITEMS 	= ft_atoi \
	ft_puterr \
	ft_create_elem \
	ft_dosort \
	ft_getargs \
	ft_isnumber \
	ft_issort \
	ft_lstadd \
	ft_lstdel \
	ft_lstprint \
	ft_lstpush \
	ft_lstrot \
	ft_lstrotrev \
	ft_lstswap \
	ft_readparams \
	ft_readstdn \
	get_next_line \
	instructs \
	instructs2 \
	instructs3 \
	ft_checkdb \
	algo_fast_sort \
	ft_bubble_sort \
	quick_sort \
	ft_get_nbr_elements \
	ft_brut_force \
	ft_optimisation \
	opti_past_sort \
	ft_operator_controls

OBJS	= $(addprefix $(ODIR)/, $(ITEMS:=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LDIR)

$(OBJS) : | $(ODIR)

$(ODIR):
	mkdir $(ODIR)

$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(IDIR) -I$(LDIR)

clean :
	@$(MAKE) -C $(LDIR) clean
	@rm -r $(ODIR)

fclean : clean
	@$(MAKE) -C $(LDIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
