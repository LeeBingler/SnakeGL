SRC_C	=	src/glad.c

SRC_CPP	=	src/main.cpp	\
			src/renderLoop.cpp	\
			src/Shader.cpp	\
			src/Texture2D.cpp	\
			src/game/Map.cpp		\
			src/game/Snake.cpp		\
			src/game/Game.cpp		\
			src/game/Coin.cpp		\

INC =	include/

FLAGS =	-g3 -g -Wall -Wextra -I$(INC)

LIBFLAGS =	-L./lib/glfw3/src -lglfw3

OBJ =	$(SRC_C:.c=.o) $(SRC_CPP:.cpp=.o)

NAME =	test

all: 	$(NAME)

lib:
	make -C lib/glfw3/

%.o: %.c
	gcc -c $< -o $@ $(FLAGS)

%.o: %.cpp
	g++ -c $< -o $@ $(FLAGS)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(FLAGS) $(LIBFLAGS)

run:
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
