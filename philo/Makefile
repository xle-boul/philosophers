# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:38:49 by xle-boul          #+#    #+#              #
#    Updated: 2022/10/20 16:49:07 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
UNDERLINE	= \e[4m
RESET		= \033[0m
END			= \e[0m

NAME := philo

CC := gcc
CFLAGS := -Werror -Wall -Wextra -fsanitize=thread -g
PTHREAD := -pthread

SRC_DIR := sources
OBJ_DIR := objs

SRC_FILES := $(wildcard *.c)
OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(notdir $(SRC_FILES:.c=.o)))

RM := rm -rf
MKDIR := mkdir -p

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@printf "$(YELLOW)Linking philosophers...\n\n$(END)"
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ $(PTHREAD)
	@printf "\n$(GREEN)philosophers compiled.\n$(END)"

$(OBJ_DIR)/%.o : %.c
	@$(MKDIR) $(OBJ_DIR)
	@printf "$(YELLOW)Compiling object:\n$(END)"
	$(CC) $(CFLAGS) -c -o $@ $< $(PTHREAD)
	@printf "$(GREEN)Object $(UNDERLINE)$(WHITE)$(notdir $@)$(END)$(GREEN) successfully compiled\n\n$(END)"

clean:
	@printf "$(YELLOW)Removing objects...\n$(END)"
	$(RM) $(OBJ_DIR)
	@printf "$(GREEN)Objects removed!\n\n$(END)"

fclean: clean
	$(RM) $(NAME)
	@printf "$(GREEN)All clean!\n\n$(END)"

re: fclean all

norm:
	@norminette

.PHONY: clean fclean all re
