# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 11:11:36 by rmatsuka          #+#    #+#              #
#    Updated: 2021/07/01 22:04:46 by rmatsuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra
LIBFT		=	./libft/libft.a
SRCS		=	calc.c \
				calc_mandelbrot.c \
				calc_julia.c \
				mlx_utils.c \
				key_hooks.c \
				mouse_hooks.c \
				main.c

OBJS		=	$(SRCS:.c=.o)
MLX			= 	-Imlx
MLXFLAGS	=	-lXext -lX11 -lm -lbsd
MLXPATH		=	./minilibx-linux
RM 			=	rm -f

all: $(NAME) ## Run compile

$(NAME): $(MLXPATH) $(OBJS) $(LIBFT)
	make -C $(MLXPATH)
	$(CC) $(MLX) $(OBJS) $(MLXPATH)/libmlx.a $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

$(MLXPATH):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLXPATH)

$(LIBFT):
		make -C ./libft

clean: ## Delete *.o file
	make clean -C ./libft
	$(RM) $(OBJS)

fclean: clean ## Delete *.o file and fractol
	make fclean -C ./libft
	$(RM) $(NAME)

plot1: ## Plot mandelbrot
	./fractol mandelbrot

plot2: ## Plot julia
	./fractol julia

plot3: ## Plot burning ship
	./fractol burningship

plot4: ## Plot tricorn
	./fractol tricorn

bonus: all

re: fclean all ## Recompile

.PHONY: all clean fclean re help bonus

.PHONY: plot1 plot2 plot3 plot4

help:
	@grep -E '^[a-zA-Z1-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
