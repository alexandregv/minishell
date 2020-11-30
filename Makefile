# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 20:31:11 by aguiot--          #+#    #+#              #
#    Updated: 2020/11/30 18:12:14 by aguiot--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC			= clang

# Compiler & Preprocessor flags
CFLAGS		+= -Wall -Werror -Wextra
CPPFLAGS	+= -I include/ -I libft/include/
MAKEFLAGS	+= --no-print-directory

# Recompile on headers/Makefile changes
HEADERS		= include/$(NAME).h libft/include/libft.h
DEPS		= $(HEADERS) Makefile libft/Makefile

# Source files
SRC_PATH	= src/
SRC_NAME	= main env prompt path signals exec expansions print builtins \
			  builtins/echo builtins/cd builtins/env builtins/setenv \
			  builtins/unsetenv builtins/exit builtins/where \
			  builtins/pwd builtins/history builtins/fg

# Object files
OBJ_PATH	= obj/
OBJ_NAME	= $(addsuffix .o, $(SRC_NAME))
OBJ			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Library
LIB_PATH	= libft
LIB_NAME	= ft
LIB_FILE	= $(LIB_PATH)/lib$(LIB_NAME).a
LIB_FLAGS	= -L $(LIB_PATH) -l $(LIB_NAME)

# Colors
C_RESET		= \033[0m
C_PENDING	= \033[0;36m
C_SUCCESS	= \033[0;32m

# Escape Sequences (ANSI/VT100)
ES_ERASE	= "\033[A\033[K\033[A"
ERASE		= $(ECHO) $(ES_ERASE)

# Hide STD/ERR and prevent Make from returning non-zero code
HIDE_STD	= > /dev/null
HIDE_ERR	= 2> /dev/null || true

# Multi platforms 
ECHO 		= echo
#ifeq ($(shell uname),Linux)
#	ECHO	+= -e
#endif

GREP		= grep --color=auto --exclude-dir={.bzr,CVS,.git,.hg,.svn}

#NORMINETTE	= norminette
NORMINETTE	= ~/.norminette/norminette.rb

all: $(NAME)

$(NAME): $(LIB_FILE) $(OBJ)
	$(CC) $(OBJ) $(LIB_FLAGS) -o $(NAME)
	@$(ERASE)
	@$(ERASE)
	@$(ERASE)
	@$(ECHO) "$(NAME)\t[$(C_SUCCESS)✅ $(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful! 👌 $(C_RESET)"

$(LIB_FILE):
	@echo ""
	@$(MAKE) -C $(LIB_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(DEPS)
	@mkdir -p $(OBJ_PATH)/builtins $(HIDE_ERR)
	@$(ERASE)
	@$(ECHO) "$(NAME)\t[$(C_PENDING)⏳ $(C_RESET)]"
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@$(ERASE)

clean:
	@$(RM) -r $(OBJ_PATH) $(HIDE_ERR)
	@$(RM) -r $(NAME).dSYM $(HIDE_ERR)
	@$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

norm:
	@$(NORMINETTE) include/ src/ libft/include/ libft/src/ | $(GREP) -v 'Not a valid file' | $(GREP) -EB1 'Error|Warning' || true

.PHONY: clean fclean all re norm
