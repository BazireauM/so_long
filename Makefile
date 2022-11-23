NAME	=	so_long

SRCS	=	main.c

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
