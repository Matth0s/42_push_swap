
SRC		=	push_swap.c \
			check_args.c \
			moves_pri.c \
			moves_sec.c \
			sort_1.c \
			sort_2.c \
			sort_inv.c \
			utils.c \

OBJ		=	${SRC:.c=.o}
#--------------------------------------//---------------------------------------
NAME	=	push_swap

FLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	push_swap.h

CC		=	clang
#--------------------------------------//---------------------------------------
.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "  Criando .o de "$<
#--------------------------------------//---------------------------------------
all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|           Push_Swap Criado           |"
	@echo "\\ ************************************ /"
	@echo ""

#--------------------------------------//---------------------------------------
clean:
	@rm -rf $(OBJ)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|         Arquivos .o Deletados        |"
	@echo "\\ ************************************ /"
	@echo ""

fclean:		clean
	@rm -rf $(NAME)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|           Push_Swap Deletada         |"
	@echo "\\ ************************************ /"
	@echo ""
#--------------------------------------//---------------------------------------

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"

.PHONY:		all clean fclean re git
