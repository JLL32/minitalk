FLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client

SRCS = 	utils.c

all : $(SERVER) $(CLIENT)

$(SERVER): 
		gcc $(FLAGS) -o $(SERVER) server.c $(SRCS)
$(CLIENT):
		gcc $(FLAGS) -o $(CLIENT) client.c $(SRCS)

clean:
	rm -rf client server

fclean: clean

re: fclean all