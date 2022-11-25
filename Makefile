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
			include/test_way_utils.c\
			ft_printf/ft_printf.c\
			ft_printf/choose_%.c\
			ft_printf/choose_d.c\
			ft_printf/choose_c.c\
			ft_printf/choose_p.c\
			ft_printf/choose_s.c\
			ft_printf/choose_type.c\
			ft_printf/choose_u.c\
			ft_printf/choose_x.c\
			ft_printf/choose_xmaj.c\
			ft_printf/ft_itoa_u.c\
			ft_printf/ft_parssing_input.c\
			ft_printf/ft_putnbr_base.c\
			ft_printf/ft_itoa.c\
			ft_printf/ft_putstr_fd.c\
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
