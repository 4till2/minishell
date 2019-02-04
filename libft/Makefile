# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserkez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            # #    Created: 2018/11/15 16:14:56 by yserkez           #+#    #+#              #
#    Updated: 2019/01/27 22:04:56 by yserkez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
CFLAGS	:= -Wall -Werror -Wextra

NAME		:= libft.a
SRCDIR	:= srcs
OBJDIR	:= obj
INCDIR	:= includes

LIBCDIR		:= libc_funcs
HELPDIR		:= help_funcs
LISTDIR		:= list_funcs
PRINTFDIR	:= printf_funcs

LIBCS	:= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
			ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c

HELPS	:= b_printf.c ft_iswhite.c ft_putchar.c ft_putnbr_fd.c ft_strclr.c \
			ft_strjoinr.c ft_strsplit.c b_putchar.c ft_itoa.c ft_putchar_fd.c \
			ft_putstr.c ft_strdel.c ft_strmap.c ft_strsub.c b_putstr.c \
			ft_itoa_base.c ft_putendl.c ft_putstr_fd.c ft_strequ.c ft_strmapi.c \
			ft_strtoupper.c ft_chartostr.c ft_memalloc.c ft_putendl_fd.c \
			ft_putstr_newline.c ft_striter.c ft_strnequ.c ft_strtrim.c \
			ft_countdigits.c ft_memdel.c ft_putnbr.c ft_strappend.c ft_striteri.c \
			ft_strnew.c get_next_line.c ft_ftoa.c ft_nbrsize.c ft_putnbr_base.c \
			ft_strbin.c ft_strjoin.c ft_strjoin2.c ft_strrev.c ft_strncpyn.c \
			ft_arrcdel.c ft_printall.c ft_indexof.c ft_chrrp.c

LISTS	:= ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
			ft_lstmap.c

PRINTF	:= ft_printf.c append_arg.c do_mods.c hash_functions.c set_flag.c

LIBC_D	:= $(addprefix $(LIBCDIR)/, $(LIBCS))
HELP_D		:= $(addprefix $(HELPDIR)/, $(HELPS))
LIST_D	:= $(addprefix $(LISTDIR)/, $(LISTS))
PRINT_D	:= $(addprefix $(PRINTFDIR)/, $(PRINTF))

ALL		:= $(LIBC_D) $(HELP_D) $(LIST_D) $(PRINT_D)

HEADERS	:= $(wildcard $(INCDIR)/*.h)
SRCS		:= $(addprefix $(SRCDIR)/, $(ALL))
OBJECTS	:= $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(ALL)))

#colors
COM_COLOR		:= \033[0;34m
CR_COLOR		:= \033[1;34m
SRC_COLOR		:= \033[0;33m
OK_COLOR		:= \033[0;32m
LIB_COLOR		:= \033[1;32m
ERROR_COLOR	:= \033[0;31m
WARN_COLOR	:= \033[0;33m
NO_COLOR		:= \033[m

# prompt
OK_STR		:= "[OK]"
ERROR_STR	:= "[ERROR]"
WARN_STR 	:= "[WARNING]"
COM_STR   := "Compiling"

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
#@printf "%b" "$(NO_COLOR)Creating $@...\n"
	@ar rcs $@ $^
	@ranlib $@
	@printf "%b" "$(CR_COLOR)Created archive: $(LIB_COLOR)$@\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
#@printf "%b" "$(COM_COLOR)$(COM_STR): $(SRC_COLOR)$<\n"
	@$(CC) -c $(CFLAGS) -I$(INCDIR) $< -o $@

$(OBJDIR):
	@printf "$(NO_COLOR)Creating obj/ directory...\n"
	@mkdir $(OBJDIR)
	@mkdir $(addprefix $(OBJDIR)/, $(LIBCDIR))
	@mkdir $(addprefix $(OBJDIR)/, $(HELPDIR))
	@mkdir $(addprefix $(OBJDIR)/, $(LISTDIR))
	@mkdir $(addprefix $(OBJDIR)/, $(PRINTFDIR))

.PHONY: clean
clean:
	@printf "%b" "$(NO_COLOR)Removing .o files...\n"
	@rm -rf $(OBJDIR)
	@printf "%b" "$(OK_COLOR)$(OK_STR): $(NO_COLOR).o files were successfully removed\n"

.PHONY: fclean
fclean: clean
	@printf "%b" "$(NO_COLOR)Removing $(NAME)...\n"
	@rm -f $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STR): $(NO_COLOR)$(NAME) was successfully removed\n"

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	@norminette $(SRCS) $(HEADERS)
