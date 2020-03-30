# compiler shit
CC = gcc
LIBS = -lm -lSDL -lSDL_image -lSDL_mixer
INCLUDE = -I. -I./src
# obj shit
OBJS := src/main.o src/bios.o src/keine.o src/mokou.o 
OBJS += src/mami.o
NAME = build/mami.out
CPPFLAGS += -g -W

%.o: %.c %.cpp
	$(CC) -c -o $@ $^ $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) -g

clean:
	rm $(OBJS)
	rm $(NAME)


