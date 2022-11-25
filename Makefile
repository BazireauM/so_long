NAME	=	so_long

SRCS	=	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			include/parssing.c\
			include/display.c\
			include/mov.c\
			include/mov_utils.c\
			include/test_map.c\
			include/test_char.c\
			include/test_way.c\
			main.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	= -Wall -Werror -Wextra

rm		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lmlx

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)
