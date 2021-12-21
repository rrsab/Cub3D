OS :=	$(shell uname)

#COLORS
GREEN			=	\033[32;1m
BLUE			=	\033[36;1m
PURPLE			=	\033[35;1m
RESET			=	\033[0m
F_NONE			= 	\033[37m
F_BOLD			= 	\033[1m
F_ORANGE		= 	\033[38m
F_RED			= 	\033[31m
F_YELLOW		= 	\033[33m
F_GREEN			= 	\033[32m
F_CYAN			= 	\033[36m
F_BLUE			= 	\033[34m

adds =

FLAGS	= -Wall -Wextra -Werror

ifeq ($(OS), Linux)
	COMPILE = Linux Compile...
	#@echo "$(F_GREEN) Linux Compile...$(F_NONE)"
	MINILIBX_DIR = minilibx/minilibx_linux
	LIB_MLX = ./minilibx/minilibx_linux
	OPENGL = -lm -lbsd -lX11 -lXext
	MLX_A = libmlx_Linux.a
	FLAGS	+= -D LINUX=1
	#adds = sudo apt-get install gcc make xorg libxext-dev libbsd-dev
endif
ifeq ($(OS), Darwin)
	COMPILE = MAC OS Compile...
	#@echo "$(F_GREEN)MAC OS Compile...$(F_NONE)"
	MINILIBX_DIR = minilibx/minilibx_mac
	LIB_MLX = ./minilibx/minilibx_mac
	OPENGL = -lz -framework OpenGL -framework AppKit
	MLX_A = libmlx.dylib
	FLAGS	+= -D DARWIN=1
endif

NAME			= 	cub3D
NAME_BONUS		= 	cub3D_bonus

SRCS			= 	${shell find ./sources/main.c ./sources/parser ./sources/render ./sources/utils -name "*.c"}
SR_B			= 	${shell find ./sources/main_bonus.c ./sources/parser ./sources/render ./sources/utils -name "*.c"}
HDRS			=	${shell find ./includes -name "*.h"}

INCS		=		-I./includes/ -I/usr/include -I./minilibx-linux/ -I./libft/
GCC				=	gcc $(FLAGS)

#$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
#$(CC) $(OBJ) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

LIBFT			=	./libft/libft.a $(MLX_A)
#./libmlx.dylib ./libft/libft.a
#	MINILIBX_DIR = minilibx_mac/minilbx_linux
#	LIB_MLX = ./minilibx_mac/minilbx_linux
#OPENGL 			= -lm -lbsd -lX11 -lXext
#	MLX_A = libmlx_Linux.a
#GCC				+= -D LINUX=1

LFLAGS			=	-L ./libft -lft

MINILIBX_A_DIR 		=	$(MINILIBX_DIR)/$(MLX_A)

all				:	$(NAME) $(LIBFT)

$(LIBFT)		:	./libft/*.c ./libft/*.h
					@$(MAKE) -C ./libft/
					@$(MAKE) clean -C ./libft

OBJS			=	$(patsubst %.c, %.o, $(SRCS))
OBJS_B			=	$(patsubst %.c, %.o, $(SR_B))

%.o:				%.c
					$(GCC) -c -g $< -o $@ $(INCS)

$(NAME)			:	$(OBJS) $(HDRS) $(LIBFT)
					$(MAKE)  -C $(LIB_MLX)
					#$(MAKE) -C minilibx_mac/
					#cp minilibx_mac/libmlx.dylib .
					#cp minilibx-linux/libmlx_Linux.a .
					cp $(MINILIBX_A_DIR) $(MLX_A)
					#cp $(MINILIBX_A_DIR) $(MLX_A)
#$(CC) $(FLAGS)  -I$(HEADER) $(OBJS) -L. $(LIB_NAME)  $(MINILIBX_A_DIR) $(OPENGL)  -o $(NAME_PROJECT)
					@$(GCC) $(OBJS) $(OPENGL) -o $(NAME) -L. $(LIBFT)
					@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
					@echo "$(NAME): $(GREEN)project was created$(RESET)\n"

#$(CC) $(OBJ) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus			:	$(NAME_BONUS) $(LIBFT)

$(NAME_BONUS)	:	$(OBJS_B) $(HDRS) $(LIBFT)
					$(MAKE)  -C $(LIB_MLX)
					#$(MAKE) -C minilibx_mac/
					#cp minilibx_mac/libmlx.dylib .
					cp $(MINILIBX_A_DIR) $(MLX_A)
					@$(GCC) $(OBJS_B) $(OPENGL) -o $(NAME_BONUS) -L. $(LIBFT)
					#@$(GCC) $(OBJS_B) $(OPENGL) -o $(NAME_BONUS) $(LIBFT)
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
					norminette ${shell find ./ -name "*.c *.h"}

.PHONY			:	all clean fclean re	bonus	norm
