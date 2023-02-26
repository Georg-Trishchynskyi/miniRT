NAME = minirt	
LIB = libft.a
LIB_D = mlx
SRC = src
INC = inc
LIB_F = libft
CC = gcc
LIBS = $(LIB_F)/$(LIB)
CFLAGS = -g -o3 -I $(LIB_D) -I $(INC)
SRC_F = src/bump_maping.c src/color.c src/cylinder.c src/error.c src/free.c src/ft_mlx.c \
	src/general_intesections.c src/hyperboloid.c src/key_hook.c src/light.c src/main.c \
	src/material.c src/multithreading.c src/parse.c src/parse_other.c src/parse_shapes.c \
	src/parse_textures.c src/parse_utils.c src/plane.c src/polygon.c src/print_check.c \
	src/render.c src/sphere.c src/texture.c src/textures_sphere.c src/trace_ray.c \
	src/utils.c src/vector1.c src/vector2.c src/vector3.c
OBJ_F = $(SRC_F:.c=.o)

GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;34m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME): $(OBJ_F) $(LIBS)
	@$(CC) $^ -o3 -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)FDF compiled!$(DEF_COLOR)"

$(LIBS): 
	@make -C $(LIB_D)
	@echo "$(BLUE)mlx is done!$(DEF_COLOR)"
	@make -C $(LIB_F)
	@echo "$(BLUE)libft is done!$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make clean -C $(LIB_D)
	@make fclean -C $(LIB_F)
	@echo "$(YELLOW)Evrything was cleaned $(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re