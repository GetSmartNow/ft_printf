# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilnurgumerov <ilnurgumerov@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:32:38 by ctycho            #+#    #+#              #
#    Updated: 2020/12/10 00:48:32 by ilnurgumero      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar rc

SRC_P	=	./processor/

SRC_U	=	./utils/

OBJ_D	=	./obj

INC_D	=	./include/

INC		=	ft_printf.h

SRCS	=	ft_printf.c ft_parser.c \
			$(addprefix ${SRC_U}, ft_atoi.c ft_init.c ft_printf_utils.c \
			ft_putstr.c ft_reinit.c ft_strlen.c ) \
			$(addprefix ${SRC_P}, check_ft.c display_chr.c display_int.c \
			display_percent.c display_pointer.c display_str.c display_u.c \
			display_x.c display_x_cap.c )

OBJS	=	${SRCS:.c=.o}

GREEN	=	\033[0;32m

CYAN	=	\033[0;36m

MAGENTA	=	\033[0;35m

LGREEN	=	\033[1;32m

LYELLOW	=	\033[1;33m

LRED	=	\033[1;31m

LBLUE	=	\033[1;34m

all:		$(NAME)

${NAME}: ${OBJS} ${INC_D}${INC}
	@${AR} ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "${CYAN}Library "${NAME}" succesfully compiled"

%.o: %.c ${INC_D}${INC}
	@${CC} ${FLAG} -I ${INC_D} -c $< -o $@
	@echo "${MAGENTA}Object file: ${LYELLOW}$@ ${GREEN}successfuly compiled"

clean:		
	@rm -f ${OBJS}
	@echo "${LRED}All object files were cleaned"

fclean:		clean
	@rm -f ${NAME}
	@echo "${LRED}Binary file was cleaned"
	@echo "${LGREEN}Everything is cleaned succesfully"

re:     fclean all
	@echo "${LBLUE}Library successfuly rebuilt"










# NAME	=	libftprintf.a

# SRCS	=	ft_init.c ft_reinit.c ft_printf.c ft_printf_utils.c ft_parser.c \
# 			display_int.c display_chr.c display_str.c display_pointer.c \
# 			display_x.c display_u.c display_x_cap.c display_percent.c \
# 			ft_atoi.c ft_strlen.c check_ft.c ft_putstr.c

# OBJS	=	$(SRCS:.c=.o)

# GCC		=	gcc

# RM		=	rm -f

# AR		=	ar rcs

# FLAG	=	-Wall -Werror -Wextra

# all:		$(NAME)

# .c.o:
# 			$(GCC) $(FLAG) -c $< -o $(<:.c=.o)

# $(NAME):	$(OBJS)
# 			$(AR) $(NAME) $(OBJS)
# 	#		$(GCC) $(FLAG) $(SRCS)

# clean:		
# 			$(RM) $(OBJS)

# fclean:		clean
# 			$(RM) $(NAME)

# re:			fclean $(NAME)

# .PHONY:		all clean fclean re
