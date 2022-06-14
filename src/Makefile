NAME	=	solong
CC	=	gcc
CCFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f
LIBFT_IFLAG	=	-I../libft
MLX_FLAGS = -L../mlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH	=	../libft/
LIBFT_FILES	=	ft_strdup.c ft_strncmp.c get_next_line.c get_next_line_utils.c
LIBFT_SRCS	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILES))
LIBFT_OBJS	=	$(LIBFT_SRCS:.c=.o)

SRCS	=	main.c ft_strcpy.c  collect.c keys.c check_map.c map_to_window.c
# SRCS_B	=	
OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

ifdef	WITH_BONUS
	OBJECTS	=	$(OBJS_B)
else
	OBJECTS	=	$(OBJS)
endif

all	:	$(NAME)

bonus	:
	make WITH_BONUS=1 all

.c.o	:
	$(CC) $(CCFLAGS) $(LIBFT_IFLAG) -c $< -o $@

$(NAME)	:	$(LIBFT_OBJS) $(OBJECTS)
	$(CC) $(CCFLAGS) $(LIBFT_IFLAG) $(MLX_FLAGS) $^ -o $@

clean	:
	$(RM) $(LIBFT_OBJS) $(OBJS_B) $(OBJS)

fclean	:	clean
	$(RM) $(NAME) 

re	:	fclean all

.PHONY	:	all bonus clean fclean re