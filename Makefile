NAME = mapgen

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes
RM = rm -f

LIBFT = libft/libft.a
LIBFT_PATH = ./libft

FILES_S = main \
		DiamondSquare
		
SRC_DIR = ./src/

OBJS_DIR = ./objet/

SRCS_F = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES_S)))

OBJS_F = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_S)))

GREEN = \033[1;32m
BLUE =  \033[1;34m
RED = \033[1;31m
NC = \033[0m

OBJ = $(OBJS_F)

# Création des .o pour les fichiers généraux
$(OBJS_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$@ : $(BLUE)[READY]$(NC)"


all: $(NAME)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@clear
	@echo "$(RED)============== [OBJECT DELETED] ==============$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@clear
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"

re: fclean all
	@echo "\n$(BLUE)================= [ START ] =================$(NC)\n"

test: fclean all
	clear ; ./$(NAME) data.txt

.PHONY: all clean fclean re