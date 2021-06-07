FLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client

SRCS = utils.c utils2.c
NAME = $(SERVER) $(CLIENT)

all : $(NAME)

$(SERVER): 
		gcc $(FLAGS) -o $(SERVER) server.c $(SRCS)
$(CLIENT):
		gcc $(FLAGS) -o $(CLIENT) client.c $(SRCS)
bonus: all

clean:
	rm -rf client server

fclean: clean

re: fclean all