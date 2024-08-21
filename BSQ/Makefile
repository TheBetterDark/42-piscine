# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 14:00:44 by muabdi            #+#    #+#              #
#    Updated: 2024/03/26 21:53:19 by muabdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = bsq

# Compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRCDIR = ./src
OBJDIR =./build

# Files
SRCS = // TODO: Add yo shit here

OBJS = // TODO: Add yo shit here

# Default target
all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile .c files into .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
${NAME}: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Delete only object files
clean:
	@rm -rf $(OBJDIR)

# Delete object files and executable
fclean: clean
	@rm -f $(NAME)

# Recompile everything
re: fclean all

# Mark these targets as phony, so they don't correspond to actual files
.PHONY: all clean fclean re
