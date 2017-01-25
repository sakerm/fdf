NAME = fdf

CPL = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit

SRC = src/aff.c src/main.c src/matrice_de_rotation.c src/parsing.c

OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME) : $(OBJ)
	@make -C inc/libft/
	@gcc -o $(NAME) $(CPL) $(OBJ)  inc/libft/libft.a

clean :
	@rm -f $(OBJ)
	make clean -C inc/libft

fclean : clean
	@rm -f $(NAME)
	make fclean -C inc/libft

re : fclean $(NAME)
