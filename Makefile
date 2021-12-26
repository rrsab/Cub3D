OS :=	$(shell uname)

#COLORS
GREEN			=	\033[32;1m
BLUE			=	\033[36;1m
PURPLE			=	\033[35;1m
RESET			=	\033[0m

adds =

FLAGS	= -Wall -Wextra -Werror

ifeq ($(OS), Linux)
	COMPILE = Linux Compile...
	MINILIBX_DIR = minilibx/minilibx_linux
	LIB_MLX = ./minilibx/minilibx_linux
	OPENGL = -lm -lbsd -lX11 -lXext
	MLX_A = libmlx_Linux.a
	FLAGS	+= -D LINUX=1
	#adds = sudo apt-get install gcc make xorg libxext-dev libbsd-dev
endif
ifeq ($(OS), Darwin)
	COMPILE = MAC OS Compile...
	MINILIBX_DIR = minilibx/minilibx_opengl
	LIB_MLX = ./minilibx/minilibx_opengl
	OPENGL = -lz -framework OpenGL -framework AppKit
	MLX_A = libmlx.a
	FLAGS	+= -D DARWIN=1
endif

NAME			= 	cub3D
NAME_BONUS		= 	cub3D_bonus

SRCS			= 	${shell find ./sources/main.c ./sources/parser ./sources/rendering ./sources/events -name "*.c"}
SR_B			= 	${shell find ./sources/main_bonus.c ./sources/parser ./sources/rendering ./sources/events -name "*.c"}
HDRS			=	${shell find ./includes -name "*.h"}

INCS		=		-I./includes/ -I/usr/include -I./minilibx-linux/ -I./libft/
GCC				=	gcc $(FLAGS)

LIBFT			=	./libft/libft.a $(MLX_A)

LFLAGS			=	-L ./libft -lft

MINILIBX_A_DIR 		=	$(MINILIBX_DIR)/$(MLX_A)

all				:	$(NAME) $(LIBFT)

$(LIBFT)		:	./libft/src/*.c ./libft/inc/*.h
					@$(MAKE) -C ./libft/
					@$(MAKE) clean -C ./libft

OBJS			=	$(patsubst %.c, %.o, $(SRCS))
OBJS_B			=	$(patsubst %.c, %.o, $(SR_B))

%.o:				%.c
					$(GCC) -c -g $< -o $@ $(INCS)

$(NAME)			:	$(OBJS) $(HDRS) $(LIBFT)
					$(MAKE)  -C $(LIB_MLX)
					cp $(MINILIBX_A_DIR) $(MLX_A)
					@$(GCC) $(OBJS) $(OPENGL) -o $(NAME) -L. $(LIBFT)
					@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
					@echo "$(NAME): $(GREEN)project was created$(RESET)\n"

bonus			:	$(NAME_BONUS) $(LIBFT)

$(NAME_BONUS)	:	$(OBJS_B) $(HDRS) $(LIBFT)
					$(MAKE)  -C $(LIB_MLX)
					cp $(MINILIBX_A_DIR) $(MLX_A)
					@$(GCC) $(OBJS_B) $(OPENGL) -o $(NAME_BONUS) -L. $(LIBFT)
					@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
					@echo "$(NAME): $(GREEN)project was created$(RESET)\n"

clean			:
					@rm -rvf $(OBJS)
					@rm -rvf $(OBJS_B)
					@echo "\n$(NAME): $(BLUE)object files were deleted$(RESET)\n"

fclean			:	clean
					@rm -f $(NAME)
					@rm -f $(NAME_BONUS)
					@echo "$(NAME): $(PURPLE)project remake done$(RESET)\n"

re				:	fclean all

norm			:
					@echo "\033[46m\033[30mNORMINETTE$(RESET)"
					norminette $(SRCS) ./sources/main_bonus.c ./includes/colors.h ./includes/cub3d.h ./includes/keycode.h

.PHONY			:	all clean fclean re	bonus	norm
