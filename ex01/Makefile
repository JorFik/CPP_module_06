NAME		=	Serializer
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++17 -Wno-shadow
_INCLUDE	=	include
INCLUDE		=	$(addprefix -I, $(_INCLUDE))
RM			=	rm -f

_HEADER		=	Serializer.hpp
HEADER		=	$(patsubst %, include/%, $(_HEADER))

_SRC		=	main.cpp\
				Serializer.cpp
SRC			=	$(patsubst %, src/%, $(_SRC))
OBJ			=	$(SRC:src/%.cpp=bin/%.o)

YELLOW		=	\033[3;33m
GREEN		=	\033[1;32m
RED			=	\033[3;31m
RESET		=	\033[0m

GREEN_FORMAT	=	"\r$(GREEN)%-80s$(RESET)\n"
RED_FORMAT		=	"\r$(RED)%-80s$(RESET)"
YELLOW_FORMAT	=	"\r$(YELLOW)%-80s$(RESET)"

all: $(NAME)

bin:
	mkdir -p bin

bin/%.o: src/%.cpp $(HEADER) | bin
	@printf $(YELLOW_FORMAT) "Compiling $(patsubst bin/%, %, $@)..."
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@printf $(GREEN_FORMAT) "All files have been compiled successfully!"
	@printf $(YELLOW_FORMAT) "Linking $(NAME)..."
	@sleep 0.3
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@
	@printf $(GREEN_FORMAT) "Linking complete!"

clean:
	@for obj in $(OBJ); do \
		printf $(RED_FORMAT) "Removing $$obj...";\
		$(RM) $$obj; \
		sleep 0.1; \
	done
	@printf $(GREEN_FORMAT) "The cleaning process is complete!"

fclean: clean
	@printf $(RED_FORMAT) "Removing $(NAME)..."
	@$(RM) $(NAME)
	@sleep 0.2
	@printf $(GREEN_FORMAT) "The full cleaning process is complete!"

re: fclean all

.PHONY: all clean fclean re

ifdef DEBUG
CXXFLAGS	+=	-g3
all: fclean $(NAME)
endif
ifdef TEST
CXXFLAGS	+=	-D TEST
all: fclean $(NAME)
endif
