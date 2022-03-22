NAME = hypercube

FLAGS = -Werror -Wall -Wextra

SRCS = main.cpp vertex.cpp

OBJS = ${SRCS:.cpp=.o}


${NAME}: ${OBJS}
		c++ ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re:    fclean all

.PHONY: all clean fclean re