SRCS			=	main.c ft_split.c pwd.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
# CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= minimini

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(OBJS) -lreadline

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
