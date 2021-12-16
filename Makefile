NAME			= 	cub3D
NAME_BONUS		= 	cub3D_bonus

SRCS			= 	${shell find ./sources/main.c ./sources/parser ./sources/render ./sources/utils -name "*.c"}
SR_B			= 	${shell find ./sources/main_bonus.c ./sources/parser ./sources/render ./sources/utils -name "*.c"}
HDRS			=	${shell find ./includes -name "*.h"}

INCS		=		-I./includes/ -I./minilibx/ -I./libft/
GCC				=	gcc -Wall -Wextra -Werror

LIBFT			=	./libmlx.dylib ./libft/libft.a
LFLAGS			=	-L ./libft -lft

#COLORS
GREEN			=	\033[32;1m
BLUE			=	\033[36;1m
PURPLE			=	\033[35;1m
RESET			=	\033[0m

#RDL_INC			=	-I ~/.brew/opt/readline/include/
#RDL				=	-lreadline -L ~/.brew/opt/readline/lib $(RDL_INC)

all				:	$(NAME) $(LIBFT)

$(LIBFT)		:	./libft/*.c ./libft/*.h
					@$(MAKE) -C ./libft/
					@$(MAKE) clean -C ./libft

OBJS			=	$(patsubst %.c, %.o, $(SRCS))
OBJS_B			=	$(patsubst %.c, %.o, $(SR_B))

%.o:				%.c
					$(GCC) -c -g $< -o $@ $(INCS)

$(NAME)			:	$(OBJS) $(HDRS) $(LIBFT)
					$(MAKE) -C minilibx/
					cp minilibx/libmlx.dylib .
					@$(GCC) $(OBJS) -o $(NAME) $(LIBFT)
					@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
					@echo "$(NAME): $(GREEN)project was created$(RESET)\n"

bonus			:	$(NAME_BONUS) $(LIBFT)

$(NAME_BONUS)	:	$(OBJS_B) $(HDRS) $(LIBFT)
					$(MAKE) -C minilibx/
					cp minilibx/libmlx.dylib .
					@$(GCC) $(OBJS_B) -o $(NAME_BONUS) $(LIBFT)
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
