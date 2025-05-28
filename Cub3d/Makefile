NAME = cub3d
BNAME = cub3d_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g3  #-fsanitize=address 
MLX = -L. -lmlx -lm -lXext -lX11


ifeq ($(shell uname -s),Darwin)
	CFLAGS += -DMAC
	MLX = -L. -lmlx -framework OpenGL -framework AppKit
endif

SRCS = $(shell find src/mandatory -name "*.c")
OBJS = $(SRCS:.c=.o)
INITS= ./src/main.c ./src/get_cub.c
INITO = $(INITS:.c=.o)


BSRCS = $(shell find src/bonus -name "*.c")
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INITO)
	$(CC) $(CFLAGS) $(OBJS) $(INITO) $(MLX) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(OBJS) $(BOBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(BOBJS)  $(MLX) -o $(BNAME)

clean:
	rm -f $(OBJS) $(BOBJS) $(INITO)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all
