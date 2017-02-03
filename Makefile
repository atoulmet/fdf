# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 16:31:19 by atoulmet          #+#    #+#              #
#    Updated: 2017/02/03 17:15:15 by atoulmet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

SRC_PATH = srcs/

SRCS = compute_screen_view.c fdf_error.c link_points.c main.c parsing.c parsing2.c resize.c window_and_img.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

INC = -I ./includes/ -I./libft

LIB = -L minilibx -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	    @make -C libft/
		    @gcc $(OBJ) $(INC) $(LIB) -o $(NAME)

%.o: $(SRC_PATH)%.c
	        @gcc -c $(FLAGS) $< -o $@ $(INC)

clean :
	        @rm -rf $(OBJ)

fclean : clean
	        @rm -rf $(NAME)
			        @make -C libft fclean

re : fclean all
