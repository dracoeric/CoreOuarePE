#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 14:34:35 by erli              #+#    #+#              #
#    Updated: 2019/02/12 14:07:22 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		asm

SRCSDIR		=		./srcs
OBJSDIR		=		./objs

SRCS		=		main.c		op.c	asm_assemble.c			asm_get_header.c	\
					asm_convert.c		asm_next_line.c			asm_free_data.c		\
					asm_error_msg.c		asm_match_name_or_comment.c					\
					asm_write_header.c	

OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc -g

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/ -I libft/includes/

HEADER		=		includes/asm.h

RM			=		rm -f

LIB			=		libft/libft.a

ADDLIB		=		-L libft/	-lft

all			:		$(NAME)

$(NAME)		:		$(OBJS) $(LIB) $(HEADER)
					$(CC) $(CFLAG) $(INCL) $(OBJS) $(ADDLIB) $(FRAMEWORK) \
					-o $(NAME)

$(LIB)		:		
					make -C libft/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c $(HEADER)
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) -c $< -o $@

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		
					@make fclean
					@make all

delsav		:
					$(RM) *~
					$(RM) */*~
					$(RM) \#*\#
					$(RM) */\#*\#

reset		:		
					@make fclean
					@make delsav
					@make -C libft reset
					@rm -Rf objs

.PHONY		:		clean fclean re delsav reset
