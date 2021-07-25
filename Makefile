CLIENT			=	client

CLIENT_SRC		=	client.c utils.c

CLIENT_BON		=	client_bonus

CLIENT_BON_SRC	=	client_bonus.c utils.c


SERVER			=	server

SERVER_SRC		=	server.c utils.c

SERVER_BON		=	server_bonus

SERVER_BON_SRC	=	server_bonus.c utils.c


HEADER			=	minitalk.h

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

OFF_COLOR		=	\033[0m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
L_BLUE			=	\033[0;36m

all		:	$(CLIENT) $(SERVER)

$(CLIENT):	$(CLIENT_SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT)
	@echo "$(YELLOW)🌼Client compiled 🌼 $(OFF_COLOR)"

$(SERVER):	$(SERVER_SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SERVER_SRC) -o $(SERVER)
	@echo "$(L_BLUE)🌸Server compiled 🌸 $(OFF_COLOR)"

bonus	:	$(CLIENT_BON) $(SERVER_BON)

$(CLIENT_BON):	$(CLIENT_BON_SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(CLIENT_BON_SRC) -o $(CLIENT_BON)
	@echo "$(PURPLE)🌼 Bonus $(YELLOW)client $(PURPLE)compiled 🌼 $(OFF_COLOR)"
$(SERVER_BON):	$(SERVER_BON_SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SERVER_BON_SRC) -o $(SERVER_BON)
	@echo "$(PURPLE)🌸 Bonus $(L_BLUE)server $(PURPLE)compiled 🌸 $(OFF_COLOR)"
	@echo "$(GREEN)All bonuses compiled!✅ $(OFF_COLOR)"

clean	:	
	@$(RM) ./*.o
	@echo "$(RED)Object files not found!$(OFF_COLOR)"

fclean	:	clean
	@$(RM) libft.a $(CLIENT) $(SERVER) $(CLIENT_BON) $(SERVER_BON)
	@echo "$(RED)🗑 Program deleted!$(OFF_COLOR)"

re		:	fclean all