SL_NAME = so_long
FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/ -I$(LIB_DIR)
SL_SRC = srcs/main.c \
srcs/check_1.c\
srcs/check_2.c\
srcs/init.c\
srcs/key.c\
srcs/print.c\
srcs/utils.c
SL_OBJ = $(SL_SRC:.c=.o)
LIB_DIR = libft/
LIBFT = libft.a
all: $(SL_NAME)
$(SL_NAME): $(SL_OBJ)
	@make -C $(LIB_DIR)
	@gcc $(FLAGS) $(SL_SRC) -lmlx -framework OpenGL -framework AppKit $(INC) -o $(SL_NAME) $(LIB_DIR)$(LIBFT)
	@echo "##### so_long compiling finished #####"
%.o: %.c
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) $(INC) -Imlx $< -c
clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(SL_OBJ)
	@rm -f *.o
	@echo "##### Removed object files #####"
fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(SL_NAME)
	@echo "##### Removed binary files #####"
re: fclean all
.PHONY: all clean fclean re