# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 14:00:44 by muabdi            #+#    #+#              #
#    Updated: 2024/03/24 17:40:51 by muabdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = rush-02

# Compiler
CC = cc
CFLAGS = 

# Directories
SRCDIR = ./src
OBJDIR =./build

# Files
SRCS = $(SRCDIR)/main.c \
    $(SRCDIR)/read_file.c \
    $(SRCDIR)/util/ft_check.c \
    $(SRCDIR)/util/ft_fgets.c \
    $(SRCDIR)/util/ft_group_three.c \
    $(SRCDIR)/util/ft_key.c \
    $(SRCDIR)/util/ft_key_generator.c \
    $(SRCDIR)/util/ft_putchar.c \
    $(SRCDIR)/util/ft_putstr.c \
    $(SRCDIR)/util/ft_row_len.c \
    $(SRCDIR)/util/ft_strchr.c \
    $(SRCDIR)/util/ft_strcmp.c \
    $(SRCDIR)/util/ft_strlen.c \
    $(SRCDIR)/util/ft_strtok.c

OBJS = $(OBJDIR)/main.o \
    $(OBJDIR)/read_file.o \
    $(OBJDIR)/util/ft_check.o \
    $(OBJDIR)/util/ft_fgets.o \
    $(OBJDIR)/util/ft_group_three.o \
    $(OBJDIR)/util/ft_key.o \
    $(OBJDIR)/util/ft_key_generator.o \
    $(OBJDIR)/util/ft_putchar.o \
    $(OBJDIR)/util/ft_putstr.o \
    $(OBJDIR)/util/ft_row_len.o \
    $(OBJDIR)/util/ft_strchr.o \
    $(OBJDIR)/util/ft_strcmp.o \
    $(OBJDIR)/util/ft_strlen.o \
    $(OBJDIR)/util/ft_strtok.o

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
