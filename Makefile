# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochenash <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 14:42:56 by ochenash          #+#    #+#              #
#    Updated: 2018/09/04 16:05:54 by ochenash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a

CC =			gcc

FLAGS =			-Wall -Werror -Wextra

HEADER =		$(FT_SRC_DIR)libft.h

FT_SRC_DIR =	./libft/

PRINTF_HEADER =	$(PRINTF_DIR)ft_printf.h

PRINTF_DIR =	./printf/

FT_COMPILED =	ft_putchar.o \
				ft_putstr.o \
				ft_strlen.o \
				ft_strcat.o \
				ft_strncat.o \
				ft_strlcat.o \
				ft_strcpy.o \
				ft_strncpy.o \
				ft_strdup.o \
				ft_strcmp.o \
				ft_strncmp.o \
				ft_strstr.o \
				ft_strnstr.o \
				ft_strchr.o \
				ft_strrchr.o \
				ft_islower.o \
				ft_isupper.o \
				ft_isalpha.o \
				ft_isdigit.o \
				ft_isalnum.o \
				ft_isprint.o \
				ft_isascii.o \
				ft_tolower.o \
				ft_toupper.o \
				ft_bzero.o \
				ft_memset.o \
				ft_memchr.o \
				ft_memcmp.o \
				ft_memcpy.o \
				ft_memccpy.o \
				ft_memmove.o \
				ft_atoi.o \
				ft_memalloc.o \
				ft_memdel.o \
				ft_strnew.o \
				ft_strdel.o \
				ft_strclr.o \
				ft_striter.o \
				ft_striteri.o \
				ft_strmap.o \
				ft_strmapi.o \
				ft_strequ.o \
				ft_strnequ.o \
				ft_strsub.o \
				ft_strjoin.o \
				ft_strtrim.o \
				ft_strsplit.o \
				ft_itoa.o \
				ft_putendl.o \
				ft_putnbr.o \
				ft_putchar_fd.o \
				ft_putstr_fd.o \
				ft_putendl_fd.o \
				ft_putnbr_fd.o \
				ft_lstnew.o \
				ft_lstdelone.o \
				ft_lstdel.o \
				ft_lstadd.o \
				ft_lstiter.o \
				ft_lstmap.o \
				ft_memdup.o \
				ft_strrev.o \
				ft_ptrswap.o \
				ft_memswap.o \
				ft_strlcpy.o

PRINTF_CMPLD =	ft_printf.o \
				new_conversion.o \
				print_conversion.o \
				del_conversion.o \
				parse_conversion.o \
				print_number.o \
				print_string.o \
				print_wstring.o \
				digitc.o \
				tally_print.o \
				print_spacing.o \
				print_num_spaced.o \
				get_conv_num.o \
				print_wint.o

COMPILED =		$(FT_COMPILED) $(PRINTF_CMPLD)

all: $(NAME)

$(NAME): $(COMPILED)
	ar rc $(NAME) $(COMPILED)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)%.c $(HEADER)
	$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_CMPLD): %.o: $(PRINTF_DIR)%.c $(PRINTF_HEADER)
	$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_DIR) $< -o $@

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all
